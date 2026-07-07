#ifndef MAKIMA_FUNCTIONAL_HPP
#define MAKIMA_FUNCTIONAL_HPP

#include <concepts>
#include <span>

#include "common.hpp"
#include "type.hpp"

namespace makima
{
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
