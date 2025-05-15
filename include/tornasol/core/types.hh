#pragma once
#include <memory>
#include <string>
#include <cstdint>
#include <cstddef>
#include <iostream>
#include <format>
#include <cstdio>
#include <concepts>
#include <exception>
#include <stdexcept>

#include <glm/glm.hpp>

namespace sol {

using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using i8  = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using f32 = float;
using f64 = double;

using uarch = std::size_t;
using iarch = std::ptrdiff_t;

using vec2 = glm::fvec2;
using vec3 = glm::fvec3;
using vec4 = glm::fvec4;

using ivec2 = glm::ivec2;
using ivec3 = glm::ivec3;
using ivec4 = glm::ivec4;

}