#ifndef MAKIMA_OPERATIONS_HPP
#define MAKIMA_OPERATIONS_HPP

#include <span>

#include "common.hpp"
#include "type.hpp"

namespace makima
{
void
batch_init(std::span< f16 > _src, std::span< vec4x16 > _dst)
{
    MAKIMA_VALIDATE(src.size() / 4 > _dst.size());
    // что то будет
}

// BASE
// approx_sin
// approx_cos
// approx_tan
// approx_ctg
// batch_approx_sin
// batch_approx_cos
// batch_approx_tan
// batch_approx_ctg

// VEC
// dot
// cross
// lenght
// distance
// normalize
// normalize
// reflect
// refract
// faceforward

// MAT
} // namespace makima

#endif
