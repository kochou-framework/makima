#ifndef MAKIMA_COMMON_HPP
#define MAKIMA_COMMON_HPP

#ifndef __ARM_NEON
static_assert(false && "unsupported platform (sorry)")
#endif

#define MAKIMA_INLINE __attribute__((always_inline))

#define MAKIMA_PAGESIZE 8096
#define MAKIMA_CACHELINE 128

#ifdef MAKIMA_VALIDATION
#define MAKIMA_VALIDATE(cond)                                                                                          \
    do                                                                                                                 \
    {                                                                                                                  \
        if (!(cond)) [[unlikely]]                                                                                      \
            MAKIMA_VALIDATION_TOOL();                                                                                  \
    } while (0)
#else
#define MAKIMA_VALIDATE(cond) ((void)0)
#endif

#endif
