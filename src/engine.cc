#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "tornasol/core/engine.hh"

namespace sol {

static auto _check_if_glfw_is_initialized() -> bool {
    glfwGetTime();
    int error_code = glfwGetError(nullptr);

    return error_code != GLFW_NOT_INITIALIZED;
}

static auto _init_glfw() -> bool {
    return (bool) glfwInit();
}

auto init_engine() -> result<engine> {
    if (_check_if_glfw_is_initialized()) {
        return std::unexpected { error{ "The engine is already initialized " 
            "`engine.already_initialized`" } };
    }

    if (!_init_glfw()) {
        return std::unexpected { error{ "Failed to initialize engine dependency glfw " 
            "`glfw.init`" } };
    }
    
    return engine {};
}

engine::engine() noexcept 
    : _main_instance(true) {}

engine::~engine() {
    if (_main_instance) {
        glfwTerminate();
    }
}

engine::engine(engine&& other) noexcept {
    if (this != &other) {
        _main_instance = other._main_instance;
        other._main_instance = false;
    }
}

engine& engine::operator=(engine&& other) noexcept {
    if (this != &other) {
        _main_instance = other._main_instance;
        other._main_instance = false;
    }
    return *this;
}

auto engine::poll_events() noexcept -> void {
    glfwPollEvents();
}

auto engine::wait_events(f64 timeout) noexcept -> void {
    if (timeout != 0.0f) {
        glfwWaitEventsTimeout(timeout);
    }
    else {
        glfwWaitEvents();
    }
}

} // namespace sol