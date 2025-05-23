#include <tornasol/tornasol.hh>
#include <cstdio>
#include <glad/glad.h>

int main(int, char**) {
	auto engine = sol::init_engine().value();
	
	{
		auto window = sol::make_window("Hello, World!", { 800, 600 }).value();
		window.make_current_gl_context();
		//gladLoadGL();
		gladLoadGLLoader((GLADloadproc)sol::get_opengl_load_proc());
	}
	auto window = sol::make_window("Hello, World!", { 800, 600 }).value();
	window.make_current_gl_context();
	while (!window.should_close()) {
		

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		window.swap_buffers();
		engine.poll_events();
	}

	return 0;
}
