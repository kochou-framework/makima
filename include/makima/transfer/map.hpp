#ifndef MAKIMA_TRANSFER_MAP_HPP
#define MAKIMA_TRANSFER_MAP_HPP

#include <kochou/kochou.hpp>

#include "f16_component.hpp"

#include <makima/common.hpp>
#include <makima/type.hpp>

namespace makima
{
// uniform
// gpu memory?

// ???
template < on_leash_type T >
MAKIMA_INLINE void
map_uniform(kochou::shared_context _sctx) noexcept
{
    // ???
}

template < on_leash_type T >
MAKIMA_INLINE void
map_uniform_safe(kochou::shared_context _sctx) noexcept
{
    if (!kochou::allowed< fp16_support > && std::same_as< T, f16 >)
    {
        return ktl::errc::memory_map_failed;
    }
    // ???
}
} // namespace makima

#endif
