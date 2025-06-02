#pragma once
#include "./def.hh"
#include <glm/glm.hpp>

namespace tornasol {

template <class T, uarch N>
using vec = glm::vec<N, T>;

using fvec2 = vec<f32, 2>;
using fvec3 = vec<f32, 3>;
using fvec4 = vec<f32, 4>;

using ivec2 = vec<i32, 2>;
using ivec3 = vec<i32, 3>;
using ivec4 = vec<i32, 4>;

} // namespace tornasol