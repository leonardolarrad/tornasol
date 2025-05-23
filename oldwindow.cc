#include "tornasol/platform/window.hh"
#include <cstdio>

namespace sol {

TORNASOL_EXPORT
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
        std::printf("Failed to create GLFW window\n");
        return std::unexpected { error { "Failed to create `glfw.window`" } };
    }
    std::printf("AAAAAA?????123\n");

    return window(handle);
}

window::window(GLFWwindow* handle) : m_handle(handle) {    
}

window::~window() {
    glfwDestroyWindow(m_handle);
}

window::window(window&& other) : m_handle(other.m_handle) {
    other.m_handle = nullptr;
}

window& window::operator=(window&& other) {
    if (this != &other) {
        m_handle = other.m_handle;
        other.m_handle = nullptr;
    }
    return *this;
}

auto window::show() -> void {
    glfwShowWindow(m_handle);
}

auto window::hide() -> void {
    glfwHideWindow(m_handle);
}

auto window::close() -> void {
    glfwSetWindowShouldClose(m_handle, true);
}

auto window::maximize() -> void {
    glfwMaximizeWindow(m_handle);
}

auto window::minimize() -> void {
    glfwIconifyWindow(m_handle);
}

auto window::restore() -> void {
    glfwRestoreWindow(m_handle);
}

auto window::raise() -> void {
    glfwFocusWindow(m_handle);
}

auto window::get_title() const -> std::string_view {
    return glfwGetWindowTitle(m_handle);
}

auto window::set_title(std::string_view title) -> void {
    glfwSetWindowTitle(m_handle, title.data());
}

auto window::get_size() const -> isize2 {
    int width, height;
    glfwGetWindowSize(m_handle, &width, &height);
    return { width, height };
}

auto window::set_size(isize2 size) -> void {
    glfwSetWindowSize(m_handle, (int) size.width, (int) size.height);
}

auto window::get_position() const -> ivec2 {
    int x, y;
    glfwGetWindowPos(m_handle, &x, &y);
    return { x, y };
}

auto window::set_position(ivec2 pos) -> void {
    glfwSetWindowPos(m_handle, (int) pos.x, (int) pos.y);
}

}