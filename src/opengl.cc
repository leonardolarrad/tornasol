#include <GLFW/glfw3.h>
#include "tornasol/core/opengl.hh"

namespace tornasol {
    
auto get_opengl_load_proc() noexcept -> opengl_load_proc {
    return (opengl_load_proc) glfwGetProcAddress;
}

}