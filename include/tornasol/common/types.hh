#pragma once
#include <memory>
#include <utility>
#include <cstdint>
#include <cstddef>
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

using fvec2 = glm::fvec2;
using fvec3 = glm::fvec3;
using fvec4 = glm::fvec4;

using ivec2 = glm::ivec2;
using ivec3 = glm::ivec3;
using ivec4 = glm::ivec4;

template <class T>
using unique = std::unique_ptr<T>;

template <class T>
using shared = std::shared_ptr<T>;

template <class T>
using weak = std::weak_ptr<T>;

}