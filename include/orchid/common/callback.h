#pragma once

#include "orchid/common/common.h"

namespace orchid
{
namespace Common
{

/**
 * Handle for a callback that can be removed. Destruction of the handle does NOT
 * remove the callback.
 */
class CallbackHandle
{
public:
    virtual ~CallbackHandle() = default;

    /**
     * Remove the callback. After this routine returns the callback will no
     * longer be called.
     */
    virtual void remove() PURE;
};

} // namespace Common
} // namespace orchid
