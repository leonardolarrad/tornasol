#include "tornasol/platform/window.hh"
#include "GLFW/glfw3.h"

namespace sol {

class glfw_window;

static auto _convert_key_from_glfw(int glfw_key) -> key {
    switch (glfw_key) {
        case GLFW_KEY_UNKNOWN:       return key::unknown;
        case GLFW_KEY_SPACE:         return key::space;
        case GLFW_KEY_APOSTROPHE:    return key::apostrophe;
        case GLFW_KEY_COMMA:         return key::comma;
        case GLFW_KEY_MINUS:         return key::minus;
        case GLFW_KEY_PERIOD:        return key::period;
        case GLFW_KEY_SLASH:         return key::slash;
        case GLFW_KEY_0:             return key::num_0;
        case GLFW_KEY_1:             return key::num_1;
        case GLFW_KEY_2:             return key::num_2;
        case GLFW_KEY_3:             return key::num_3;
        case GLFW_KEY_4:             return key::num_4;
        case GLFW_KEY_5:             return key::num_5;
        case GLFW_KEY_6:             return key::num_6;
        case GLFW_KEY_7:             return key::num_7;
        case GLFW_KEY_8:             return key::num_8;
        case GLFW_KEY_9:             return key::num_9;
        case GLFW_KEY_SEMICOLON:     return key::semicolon;
        case GLFW_KEY_EQUAL:         return key::equal;
        case GLFW_KEY_A:             return key::a;
        case GLFW_KEY_B:             return key::b;
        case GLFW_KEY_C:             return key::c;
        case GLFW_KEY_D:             return key::d;
        case GLFW_KEY_E:             return key::e;
        case GLFW_KEY_F:             return key::f;
        case GLFW_KEY_G:             return key::g;
        case GLFW_KEY_H:             return key::h;
        case GLFW_KEY_I:             return key::i;
        case GLFW_KEY_J:             return key::j;
        case GLFW_KEY_K:             return key::k;
        case GLFW_KEY_L:             return key::l;
        case GLFW_KEY_M:             return key::m;
        case GLFW_KEY_N:             return key::n;
        case GLFW_KEY_O:             return key::o;
        case GLFW_KEY_P:             return key::p;
        case GLFW_KEY_Q:             return key::q;
        case GLFW_KEY_R:             return key::r;
        case GLFW_KEY_S:             return key::s;
        case GLFW_KEY_T:             return key::t;
        case GLFW_KEY_U:             return key::u;
        case GLFW_KEY_V:             return key::v;
        case GLFW_KEY_W:             return key::w;
        case GLFW_KEY_X:             return key::x;
        case GLFW_KEY_Y:             return key::y;
        case GLFW_KEY_Z:             return key::z;
        case GLFW_KEY_LEFT_BRACKET:  return key::left_bracket;
        case GLFW_KEY_BACKSLASH:     return key::backslash;
        case GLFW_KEY_RIGHT_BRACKET: return key::right_bracket;
        case GLFW_KEY_GRAVE_ACCENT:  return key::grave_accent;
        case GLFW_KEY_WORLD_1:       return key::world_1;
        case GLFW_KEY_WORLD_2:       return key::world_2;
        case GLFW_KEY_ESCAPE:        return key::escape;
        case GLFW_KEY_ENTER:         return key::enter;
        case GLFW_KEY_TAB:           return key::tab;
        case GLFW_KEY_BACKSPACE:     return key::backspace;
        case GLFW_KEY_INSERT:        return key::insert;
        case GLFW_KEY_DELETE:        return key::del;
        case GLFW_KEY_RIGHT:         return key::right;
        case GLFW_KEY_LEFT:          return key::left;
        case GLFW_KEY_DOWN:          return key::down;
        case GLFW_KEY_UP:            return key::up;
        case GLFW_KEY_PAGE_UP:       return key::page_up;
        case GLFW_KEY_PAGE_DOWN:     return key::page_down;
        case GLFW_KEY_HOME:          return key::home;
        case GLFW_KEY_END:           return key::end;
        case GLFW_KEY_CAPS_LOCK:     return key::caps_lock;
        case GLFW_KEY_SCROLL_LOCK:   return key::scroll_lock;
        case GLFW_KEY_NUM_LOCK:      return key::num_lock;
        case GLFW_KEY_PRINT_SCREEN:  return key::print_screen;
        case GLFW_KEY_PAUSE:         return key::pause;
        case GLFW_KEY_F1:            return key::f1;
        case GLFW_KEY_F2:            return key::f2;
        case GLFW_KEY_F3:            return key::f3;
        case GLFW_KEY_F4:            return key::f4;
        case GLFW_KEY_F5:            return key::f5;
        case GLFW_KEY_F6:            return key::f6;
        case GLFW_KEY_F7:            return key::f7;
        case GLFW_KEY_F8:            return key::f8;
        case GLFW_KEY_F9:            return key::f9;
        case GLFW_KEY_F10:           return key::f10;
        case GLFW_KEY_F11:           return key::f11;
        case GLFW_KEY_F12:           return key::f12;
        case GLFW_KEY_F13:           return key::f13;
        case GLFW_KEY_F14:           return key::f14;
        case GLFW_KEY_F15:           return key::f15;
        case GLFW_KEY_F16:           return key::f16;
        case GLFW_KEY_F17:           return key::f17;
        case GLFW_KEY_F18:           return key::f18;
        case GLFW_KEY_F19:           return key::f19;
        case GLFW_KEY_F20:           return key::f20;
        case GLFW_KEY_F21:           return key::f21;
        case GLFW_KEY_F22:           return key::f22;
        case GLFW_KEY_F23:           return key::f23;
        case GLFW_KEY_F24:           return key::f24;
        case GLFW_KEY_F25:           return key::f25;
        case GLFW_KEY_KP_0:          return key::numpad_0;
        case GLFW_KEY_KP_1:          return key::numpad_1;
        case GLFW_KEY_KP_2:          return key::numpad_2;
        case GLFW_KEY_KP_3:          return key::numpad_3;
        case GLFW_KEY_KP_4:          return key::numpad_4;
        case GLFW_KEY_KP_5:          return key::numpad_5;
        case GLFW_KEY_KP_6:          return key::numpad_6;
        case GLFW_KEY_KP_7:          return key::numpad_7;
        case GLFW_KEY_KP_8:          return key::numpad_8;
        case GLFW_KEY_KP_9:          return key::numpad_9;
        case GLFW_KEY_KP_DECIMAL:    return key::numpad_decimal;
        case GLFW_KEY_KP_DIVIDE:     return key::numpad_divide;
        case GLFW_KEY_KP_MULTIPLY:   return key::numpad_multiply;
        case GLFW_KEY_KP_SUBTRACT:   return key::numpad_subtract;
        case GLFW_KEY_KP_ADD:        return key::numpad_add;
        case GLFW_KEY_KP_ENTER:      return key::numpad_enter;
        case GLFW_KEY_KP_EQUAL:      return key::numpad_equal;
        case GLFW_KEY_LEFT_SHIFT:    return key::left_shift;
        case GLFW_KEY_LEFT_CONTROL:  return key::left_control;
        case GLFW_KEY_LEFT_ALT:      return key::left_alt;
        case GLFW_KEY_LEFT_SUPER:    return key::left_super;
        case GLFW_KEY_RIGHT_SHIFT:   return key::right_shift;
        case GLFW_KEY_RIGHT_CONTROL: return key::right_control;
        case GLFW_KEY_RIGHT_ALT:     return key::right_alt;
        case GLFW_KEY_RIGHT_SUPER:   return key::right_super;
        case GLFW_KEY_MENU:          return key::menu;

        default: std::unreachable();
    }
}

static auto _convert_input_action_from_glfw(int action) -> input_action {
    switch (action) {
        case GLFW_PRESS:    return input_action::press;
        case GLFW_RELEASE:  return input_action::release;
        case GLFW_REPEAT:   return input_action::repeat;
        
        default: std::unreachable();
    }
}

static auto _convert_key_modifier_from_glfw(int mods) -> key_modifier {
    return (key_modifier) mods;
}


static auto _glfw_key_callback(GLFWwindow* glfw_handle, int key, int scancode, int action, int mods) -> void;
static auto _glfw_char_callback(GLFWwindow* glfw_handle, unsigned int codepoint) -> void;

class glfw_window : public window {
public:
    glfw_window(GLFWwindow* glfw_handle) : _glfw_handle(glfw_handle) {
        // Attach a pointer to this instance to the underlying glfw window
        // implementation. Mechanism used for accessing this high-level window 
        // from callbacks.
        glfwSetWindowUserPointer(glfw_handle, this);
        
        // Setup the callbacks.
        glfwSetKeyCallback(glfw_handle, _glfw_key_callback);
        glfwSetCharCallback(glfw_handle, _glfw_char_callback);
    }

    ~glfw_window() {
        if (_glfw_handle) {
            glfwDestroyWindow(_glfw_handle);
        }
    }

    glfw_window(glfw_window&& _) = delete;
    glfw_window& operator=(glfw_window&& _) = delete;

    glfw_window(const glfw_window&) = delete;
    glfw_window& operator=(const glfw_window&) = delete;

    auto show() noexcept -> void override {
        TORNASOL_ASSERT(_glfw_handle != nullptr);
        glfwShowWindow(_glfw_handle);
    }

    auto hide() noexcept -> void override {
        TORNASOL_ASSERT(_glfw_handle != nullptr);
        glfwHideWindow(_glfw_handle);
    }

    auto should_close() const noexcept -> bool override {
        TORNASOL_ASSERT(_glfw_handle != nullptr);
        return (bool) glfwWindowShouldClose(_glfw_handle);
    }

    auto make_current_gl_context() noexcept -> void override {
        TORNASOL_ASSERT(_glfw_handle != nullptr);
        glfwMakeContextCurrent(_glfw_handle);
    }

    auto swap_buffers() noexcept -> void override {
        TORNASOL_ASSERT(_glfw_handle != nullptr);
        glfwSwapBuffers(_glfw_handle);
    }

private:
    GLFWwindow* _glfw_handle;
};

static auto _glfw_key_callback(GLFWwindow* glfw_handle, int key, int scancode, int action, int mods) -> void {
    TORNASOL_ASSERT(glfwGetWindowUserPointer(glfw_handle) != nullptr);

    auto* window = static_cast<glfw_window*>(glfwGetWindowUserPointer(glfw_handle));
    
    if (window->on_input_key) {
        window->on_input_key(
            _convert_key_from_glfw(key), 
            scancode,
            _convert_input_action_from_glfw(action),
            _convert_key_modifier_from_glfw(mods));
    }
}

static auto _glfw_char_callback(GLFWwindow* glfw_handle, unsigned int codepoint) -> void {
    TORNASOL_ASSERT(glfwGetWindowUserPointer(glfw_handle) != nullptr);   

    auto* window = static_cast<glfw_window*>(glfwGetWindowUserPointer(glfw_handle));
    
    if (window->on_input_char) {
        window->on_input_char((char32_t)codepoint);
    }
}

auto make_window(std::string_view title, isize2 size) -> result<unique<window>> {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto glfw_handle = glfwCreateWindow(
        (int) size.width, 
        (int) size.height, 
        title.data(), 
        nullptr, nullptr
    );
    
    if (!glfw_handle) {
        return std::unexpected { error { "Failed to create window implementation " 
            "`glfw.create_window`" } };
    }

    return std::make_unique<glfw_window>(glfw_handle);
}

} // namespace sol