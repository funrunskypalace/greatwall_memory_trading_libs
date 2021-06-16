#pragma once

#if defined(__linux__)

#include <sched.h>

#include "orchid/api/os_sys_calls_common.h"
#include "orchid/common/common.h"

namespace orchid
{
namespace api
{

class LinuxOsSysCalls
{
public:
    virtual ~LinuxOsSysCalls() = default;

    /**
     * @see sched_getaffinity (man 2 sched_getaffinity)
     */
    virtual SysCallIntResult sched_getaffinity(pid_t pid, size_t cpusetsize,
                                               cpu_set_t* mask) PURE;
};

using LinuxOsSysCallsPtr = std::unique_ptr<LinuxOsSysCalls>;

} // namespace api
} // namespace orchid

#endif
