#pragma once
#include "./def.hh"
#include <glm/glm.hpp> 

namespace tornasol {

template <class T, uarch N, uarch M>
using mat = glm::mat<N, M, T>;

using fmat2 = mat<f32, 2, 2>;
using fmat3 = mat<f32, 3, 3>;
using fmat4 = mat<f32, 4, 4>;

using imat2 = mat<i32, 2, 2>;
using imat3 = mat<i32, 3, 3>;
using imat4 = mat<i32, 4, 4>;

} // namespace tornasol