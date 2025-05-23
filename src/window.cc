#include "tornasol/platform/window.hh"
#include "GLFW/glfw3.h"

namespace sol {

class window::impl {
public:
    impl(GLFWwindow* handle) 
        : _glfw_window(handle) {}
    
    ~impl() {
        glfwDestroyWindow(_glfw_window);
    }

    impl(impl const&) = delete;
    impl& operator=(impl const&) = delete;

    impl(impl&& other) 
        : _glfw_window(other._glfw_window) {
        other._glfw_window = nullptr;
    }

    impl& operator=(impl&& other) {
        if (this != &other) {
            _glfw_window = other._glfw_window;
            other._glfw_window = nullptr;
        }
        return *this;
    }

    auto show() noexcept -> void {
        glfwShowWindow(_glfw_window);
    }

    auto hide() noexcept -> void {
        glfwHideWindow(_glfw_window);
    }

    auto make_current_gl_context() noexcept -> void {
        glfwMakeContextCurrent(_glfw_window);
    }

    auto swap_buffers() noexcept -> void {
        glfwSwapBuffers(_glfw_window);
    }

    auto should_close() const noexcept -> bool {
        return (bool) glfwWindowShouldClose(_glfw_window);
    }

private:
    GLFWwindow* _glfw_window;
};

window::window(unique<impl> impl) noexcept
    : _impl(std::move(impl)) {}


window::window(window&& other) noexcept
    : _impl(std::move(other._impl)) {
}

window& window::operator=(window&& other) noexcept {
    if (this != &other) {
        _impl = std::move(other._impl);
    }
    return *this;
}

window::~window() = default;

auto window::show() noexcept -> void {
    _impl->show();
}

auto window::hide() noexcept -> void {
    _impl->hide();
}

auto window::make_current_gl_context() noexcept -> void {
    _impl->make_current_gl_context();
}

auto window::swap_buffers() noexcept -> void {
    _impl->swap_buffers();
}

auto window::should_close() const noexcept -> bool {
    return _impl->should_close();
}

auto make_window(std::string_view title, isize2 size) -> result<window> {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto handle = glfwCreateWindow(
        (int) size.width, 
        (int) size.height, 
        title.data(), 
        nullptr, nullptr
    );

    if (!handle) {
        return std::unexpected { error { "Failed to create `glfw.window`" } };
    }

    return window { std::make_unique<window::impl>(handle) };
}

} // namespace sol