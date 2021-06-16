#pragma once

#ifndef WIN32
#include <sys/mman.h> // for mode_t

#endif

#include "orchid/api/os_sys_calls_common.h"
#include "orchid/common/common.h"

namespace orchid
{
namespace api
{

class HotRestartOsSysCalls
{
public:
    virtual ~HotRestartOsSysCalls() = default;

#if __linux__
    /**
     * @see shm_open (man 3 shm_open)
     */
    virtual SysCallIntResult shmOpen(const char* name, int oflag,
                                     mode_t mode) PURE;

    /**
     * @see shm_unlink (man 3 shm_unlink)
     */
    virtual SysCallIntResult shmUnlink(const char* name) PURE;
#endif
};

using HotRestartOsSysCallsPtr = std::unique_ptr<HotRestartOsSysCalls>;

} // namespace api
} // namespace orchid
