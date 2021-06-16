#pragma once

#include "fmt/format.h"
#include "orchid/common/common.h"

namespace orchid
{

#if USE_INTERNAL_LOG == 100
enum level_enum
{
    trace = 0,
    debug = 1,
    info = 2,
    warn = 3,
    err = 4,
    critical = 5,
    off = 6,
};
#endif

void ORCHID_LOG_(int level, const std::string& log);
template <typename... Args>
void ORCHID_LOG(int level, const char* fmt, const Args&... args)
{
    ORCHID_LOG_(level, fmt::format(fmt, args...));
}
// has module name: "[%Y-%m-%d %T.%e][%t][%l][%n] %v"

} // namespace orchid