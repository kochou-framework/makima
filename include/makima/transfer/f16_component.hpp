#ifndef MAKIMA_TRANSFER_F16_COMPONENT_HPP
#define MAKIMA_TRANSFER_F16_COMPONENT_HPP

#include <kochou/kochou.hpp>

namespace makima
{
struct fp16_support
{
    ktl::errc
    ensure(kochou::shared_context _sctx) noexcept;

    ktl::errc
    should(kochou::shared_context _sctx) noexcept;

    bool
    allowed(kochou::shared_context _sctx) noexcept;
};
} // namespace makima

#endif
