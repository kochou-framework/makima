#ifndef MAKIMA_TYPE_HPP
#define MAKIMA_TYPE_HPP

#include <arm_neon.h>

#include <span>

namespace
{
// TODO move to ktl::reflection
template < typename T, typename... TYPES >
concept is_one_of = (std::is_same_v< T, TYPES > || ...);
} // namespace

namespace makima
{
using f16 = float16_t;
using f32 = float32_t;

struct alignas(8) vec4x16
{
    float16x4_t _dont_use_directly;
};

struct alignas(16) vec4x32
{
    float32x4_t _dont_use_directly;
};

struct alignas(8) mat4x16
{
    vec4x16 _dont_use_directly[4];
};

struct alignas(16) mat4x32
{
    vec4x32 _dont_use_directly[4];
};

template < typename T >
concept on_leash_type = is_one_of< T, f16, f32, vec4x16, vec4x32 >;

template < typename FUNC, typename... ARGS >
concept on_leash_func = std::is_void_v< std::invoke_result_t< FUNC, ARGS... > >;
} // namespace makima

#endif
