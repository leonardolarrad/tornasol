#include <cstdio>
#include <unordered_map>
#include <string>
#include <string_view>
#include <tornasol/tornasol.hh>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <ft2build.h>
#include FT_FREETYPE_H

sol::isize2 screen_size = { 1280, 720 };

FT_Library ft_lib;
FT_Face    ft_face;

struct baked_char {
	GLuint texture_id;
	sol::ivec2 size;
	sol::ivec2 bearing;
	sol::i32   advance;
};

std::unordered_map<char, baked_char> baked_chars_table = {};

auto vertex_shader_src = 
	"#version 400 core\n	   							                  "
	"layout (location = 0) in vec4 vertex; // <vec2 pos, vec2 tex>\n      "
	"out vec2 TexCoords;\n                                                "
	"\n                                                                   "
	"uniform mat4 projection;\n                                           "
	"\n                                                                   "
	"void main()\n                                                        "
	"{\n															      "
	"    gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);\n	      "
	"    TexCoords = vertex.zw;\n								          "
	"}\0 															      ";

auto fragment_shader_src = 
	"#version 400 core\n                                                  "
	"in vec2 TexCoords;\n                                                 "
	"out vec4 color;\n                                                    "
	"\n                                                                   "
	"uniform sampler2D text;\n 										      "
	"uniform vec3 textColor;\n											  "
	"\n 					                                              "
	"void main()\n                                                        "
	"{\n                                                                  "
	"    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);\n"
	"    color = vec4(textColor, 1.0) * sampled;\n                        "
	"}\0                                                                  ";

GLuint vertex_shader_id, fragment_shader_id, shader_program_id;
GLuint vao, vbo;

auto load_font() -> bool {
	if (FT_Init_FreeType(&ft_lib)) {
		return false;
	}
	
	if (FT_New_Face(ft_lib, "source_code_pro.ttf", 0, &ft_face)) {
		return false;
	}

	FT_Set_Pixel_Sizes(ft_face, 0, 48);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

	for (unsigned char c = 0; c < 128; c++) {
		// Raster char glyph.
		if (FT_Load_Char(ft_face, c, FT_LOAD_RENDER)) {
			std::printf("Failed to load glyph: %c\n", c);
			continue;
		}

		// Generate texture.
		GLuint texture_id;
		glGenTextures(1, &texture_id);
		glBindTexture(GL_TEXTURE_2D, texture_id);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			ft_face->glyph->bitmap.width,
			ft_face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			ft_face->glyph->bitmap.buffer
		);

		// Set texture opts.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Store texture for later use.
		baked_chars_table[c] = {
			texture_id,
			{ ft_face->glyph->bitmap.width, ft_face->glyph->bitmap.rows },
			{ ft_face->glyph->bitmap_left, ft_face->glyph->bitmap_top },
			ft_face->glyph->advance.x
		};
	}

	return true;
}

auto free_font() -> void {
	FT_Done_Face(ft_face);
	FT_Done_FreeType(ft_lib);
}

auto make_shader() -> bool {
	const auto print_linking_error = [](GLuint shader_id) -> bool {
		GLint success = 0;
		GLchar info_log[512];
		glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader_id, 512, NULL, info_log);
			info_log[511] = '\0'; // Ensure null-termination
			std::printf("ERROR::SHADER::COMPILATION_FAILED\n %s \n", info_log);
		}

		return (bool)success;
	};

	vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader_id, 1, &vertex_shader_src, nullptr);
	glCompileShader(vertex_shader_id);
	if (!print_linking_error(vertex_shader_id)) return false;

	fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader_id, 1, &fragment_shader_src, nullptr);
	glCompileShader(fragment_shader_id);
	if (!print_linking_error(fragment_shader_id)) return false;

	shader_program_id = glCreateProgram();
	glAttachShader(shader_program_id, vertex_shader_id);
	glAttachShader(shader_program_id, fragment_shader_id);
	glLinkProgram(shader_program_id);

	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);

	return true;
}

auto make_vao_and_vbo() -> void {
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);  
}

auto render_text(std::string_view text, sol::fvec2 position, sol::fvec3 color) -> void {
	glm::mat4 projection = glm::ortho(
		0.0f, float(screen_size.width), 0.0f, float(screen_size.height));
	
	glUseProgram(shader_program_id);
	glUniformMatrix4fv(
		glGetUniformLocation(shader_program_id, "projection"), 
		1, GL_FALSE, glm::value_ptr(projection));
	glUniform3f(
		glGetUniformLocation(shader_program_id, "textColor"), 
		color.x, color.y, color.z);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(vao);

	for (const auto c : text) {
		baked_char& baked_char = baked_chars_table[c];

		sol::f32 xpos = position.x + baked_char.bearing.x;
		sol::f32 ypos = position.y - (baked_char.size.y - baked_char.bearing.y);

		sol::f32 w = baked_char.size.x;
		sol::f32 h = baked_char.size.y;

		// Update the VBO for each character.
		sol::f32 vertices[6][4] = {
			{ xpos,     ypos + h,   0.0f, 0.0f },
			{ xpos,     ypos,       0.0f, 1.0f },
			{ xpos + w, ypos,       1.0f, 1.0f },

			{ xpos,     ypos + h,   0.0f, 0.0f },
			{ xpos + w, ypos,       1.0f, 1.0f },
			{ xpos + w, ypos + h,   1.0f, 0.0f }
		};
		
		// Render glyph texture over quad.
		glBindTexture(GL_TEXTURE_2D, baked_char.texture_id);

		// Update content of VBO memory.
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		
		// Render quad.
		glDrawArrays(GL_TRIANGLES, 0, 6);
		
		// Now advance cursors for next glyph (note that advance is number of 1/64 pixels).
		position.x += (baked_char.advance >> 6);
	}

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}

auto render_background() {
	glClearColor(1.f, 1.f, 1.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

auto center_layout(std::string_view text) -> sol::fvec2 {
	// Return the point (x, y) where the first character should be place
	// in order to center the given text in the screen.
	
	sol::f32 width = 0.0f;
	sol::f32 height = 0.0f;
	for (const auto c : text) {
		width += baked_chars_table[c].advance >> 6;
	}

	height = (baked_chars_table['H'].size.y / 2);
	
	return { (screen_size.width / 2) - (width / 2), (screen_size.height / 2) - height };
}

int main(int, char**) {
	auto engine = sol::init_engine().value();
	
	{
		auto window = tornasol::make_window("tmp", screen_size).value();
		window->make_current_gl_context();
		gladLoadGLLoader((GLADloadproc)sol::get_opengl_load_proc());
	}
	
	auto window = tornasol::make_window("tornasol-type", screen_size).value();
	window->make_current_gl_context();

	if (!load_font()) {
		std::printf("Failed to load font\n");
		return 1;
	}

	glViewport(0, 0, screen_size.width, screen_size.height);

	make_vao_and_vbo();
	if (!make_shader()) {
		std::printf("Failed to make shader\n");
		return 1;
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	std::string text = "";

	window->on_input_key = 
		[&text](sol::key key, sol::i32, sol::input_action action, sol::key_modifier) {
			const bool backspace_pressed = 
				key == sol::key::backspace &&
				(action == sol::input_action::press || 
				action == sol::input_action::repeat);
			
			if (!text.empty() && backspace_pressed) {
				text.pop_back();
			}
		};

	window->on_input_char = 
		[&text](char32_t c) {
			text.push_back(c);
		};
	
	while (!window->should_close()) {
		window->make_current_gl_context();
		


		render_background();
		render_text(
			text, 
			center_layout(text), 
			{ 0.0f, 0.0f, 0.0f });

		window->swap_buffers();
		engine.poll_events();
	}

	free_font();
	return 0;
}
