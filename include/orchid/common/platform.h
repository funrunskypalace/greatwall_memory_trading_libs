#pragma once

// NOLINT(namespace-orchid)
#ifdef _MSC_VER
#include <stdint.h>

#define PACKED_STRUCT(definition, ...)                                         \
    __pragma(pack(push, 1)) definition, ##__VA_ARGS__;                         \
    __pragma(pack(pop))

#ifdef _M_X64
using ssize_t = int64_t;
#else
//#error Orchid is not supported on 32-bit Windows
using ssize_t = int32_t;
#endif

#else
#define PACKED_STRUCT(definition, ...)                                         \
    definition, ##__VA_ARGS__ __attribute__((packed))

#endif
