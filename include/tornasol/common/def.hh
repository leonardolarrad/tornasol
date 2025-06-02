#pragma once
#include <cassert>
#include <memory>
#include <utility>
#include <cstdint>
#include <cstddef>

#define TORNASOL_ASSERT(condition) assert(condition)

#if !defined(TORNASOL_EXPORT)
    #if defined(TORNASOL_SHARED)
        #if defined(_WIN32)
            #if defined(_TORNASOL_BUILD_SHARED)
                #define TORNASOL_EXPORT __declspec(dllexport)
            #else
                #define TORNASOL_EXPORT __declspec(dllimport)
            #endif
        #else
            #define TORNASOL_EXPORT __attribute__((visibility("default")))
        #endif
    #else
        #define TORNASOL_EXPORT
    #endif
#endif

namespace tornasol {

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

template <class T>
using unique = std::unique_ptr<T>;

template <class T>
using shared = std::shared_ptr<T>;

template <class T>
using weak = std::weak_ptr<T>;

} // namespace tornasol