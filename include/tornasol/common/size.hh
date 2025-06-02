#pragma once
#include "./def.hh"

namespace tornasol {

template <class T> requires (std::integral<T> || std::floating_point<T>)
struct size2 {
    T width, height;
    
    bool operator == (const size2<T>& other) const = default;
    bool operator != (const size2<T>& other) const = default;
};

template <class T>
size2<T> operator + (const size2<T>& left, const size2<T>& right) 
{
    return {
        left.width  + right.width,
        left.height + right.height
    };
}

template <class T>
size2<T> operator - (const size2<T>& left, const size2<T>& right) 
{
    return {
        left.width  - right.width,
        left.height - right.height
    };
}

template <class T>
size2<T> operator * (const size2<T>& left, const size2<T>& right) 
{
    return {
        left.width  * right.width,
        left.height * right.height
    };
}

template <class T>
size2<T> operator / (const size2<T>& left, const size2<T>& right) 
{
    return {
        left.width  / right.width,
        left.height / right.height
    };
}

template <class T>
size2<T> operator * (const size2<T>& size, T scalar) 
{
    return {
        size.width  * scalar,
        size.height * scalar
    };
}

template <class T>
size2<T> operator * (T scalar, const size2<T>& size) 
{
    return {
        scalar * size.width,
        scalar * size.height
    };
}

template <class T>
size2<T> operator / (const size2<T>& size, T scalar) 
{
    return {
        size.width  / scalar,
        size.height / scalar
    };
}

template <class T>
size2<T> operator / (T scalar, const size2<T>& size) 
{
    return {
        scalar / size.width,
        scalar / size.height
    };
}

using isize2 = size2<i32>;
using usize2 = size2<u32>;
using fsize2 = size2<f32>;

} // namespace tornasol