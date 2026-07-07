#include <makima/component.hpp>

ktl::errc
makima::fp16_support::ensure(kochou::shared_context _sctx) noexcept
{
    ktl::errc rc = ktl::errc::success;

    rc = kochou::ensure< kochou::extension< ktl::api::extension::khr_shader_float_16int_8 > >(_sctx);
    if (rc != ktl::errc::success)
    {
        kochou::log::error("failed ensure khr_shader_float_16int_8");
        return rc;
    }

    rc = kochou::ensure< kochou::extension< ktl::api::extension::khr_16bit_storage > >(_sctx);
    if (rc != ktl::errc::success)
    {
        kochou::log::error("failed ensure khr_16bit_storage");
        return rc;
    }

    return rc;
}

ktl::errc
makima::fp16_support::should(kochou::shared_context _sctx) noexcept
{
    ktl::errc rc = ktl::errc::success;

    rc = kochou::should< kochou::extension< ktl::api::extension::khr_shader_float_16int_8 > >(_sctx);
    if (rc != ktl::errc::success)
    {
        kochou::log::error("failed should khr_shader_float_16int_8");
        return rc;
    }

    rc = kochou::should< kochou::extension< ktl::api::extension::khr_16bit_storage > >(_sctx);
    if (rc != ktl::errc::success)
    {
        kochou::log::error("failed should khr_16bit_storage");
        return rc;
    }

    return rc;
}

bool
makima::fp16_support::allowed(kochou::shared_context _sctx) noexcept
{
    return kochou::allowed< kochou::extension< ktl::api::extension::khr_shader_float_16int_8 > >(_sctx) &&
           kochou::allowed< kochou::extension< ktl::api::extension::khr_16bit_storage > >(_sctx);
}
