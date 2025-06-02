#pragma once
#include "tornasol/common/def.hh"

namespace tornasol {

using opengl_load_proc = void* (*)(char const*);

TORNASOL_EXPORT
auto get_opengl_load_proc() noexcept -> opengl_load_proc;

}