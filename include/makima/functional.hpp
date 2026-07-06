#ifndef MAKIMA_FUNCTIONAL_HPP
#define MAKIMA_FUNCTIONAL_HPP

#include <concepts>
#include <span>

#include "common.hpp"
#include "type.hpp"

namespace
{
// TODO move to ktl::reflection
template < typename T, typename... TYPES >
concept is_one_of = (std::is_same_v< T, TYPES > || ...);
} // namespace

namespace makima
{
template < typename T >
concept on_leash_type = is_one_of< T, f16, f32, vec4x16, vec4x32 >;

template < typename FUNC, typename... ARGS >
concept on_leash_func = std::is_void_v< std::invoke_result_t< FUNC, ARGS... > >;

template < on_leash_type T, on_leash_func F >
MAKIMA_INLINE void foreach (std::span< T > _data, F && _func) noexcept
{
    MAKIMA_VALIDATE(_data.size() % 4 == 0);

    // TODO use ktl::usize
    for (size_t i = 0; i < _data.size() / 4; i += 4)
    {
        _func(_data + i);
    }
}

// sort
// stable_sort
// partition
} // namespace makima

#endif
