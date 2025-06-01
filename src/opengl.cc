#include "GLFW/glfw3.h"
#include "tornasol/core/opengl_proc.hh"

namespace sol {
    
auto get_opengl_load_proc() noexcept -> opengl_load_proc {
    return (opengl_load_proc) glfwGetProcAddress;
}

}