#ifndef MAKIMA_TYPE_HPP
#define MAKIMA_TYPE_HPP

#include <arm_neon.h>

#include <span>

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

// std::bit_cast ???
} // namespace makima

#endif
