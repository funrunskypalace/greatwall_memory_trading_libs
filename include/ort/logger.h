#pragma once

#include "ort/pre.h"

#if USE_INTERNAL_LOG == 200
enum level_enum {
    trace = 0,
    debug = 1,
    info = 2,
    warn = 3,
    err = 4,
    critical = 5,
    off = 6,
};
#endif

#include "fmt/core.h"

ORAPI void OR_LOG_(int level, const std::string& log);
template <typename... Args> void OR_LOG(int level, const char* fmt, const Args&... args)
{
    OR_LOG_(level, fmt::format(fmt, args...));
}
