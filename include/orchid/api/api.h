#pragma once

#include <memory>
#include <string>

#include "orchid/common/time.h"
#include "orchid/event/dispatcher.h"
#include "orchid/filesystem/filesystem.h"
#include "orchid/server/process_context.h"
#include "orchid/thread/thread.h"

namespace orchid
{
namespace api
{

/**
 * "Public" API that different components use to interact with the various
 * system abstractions.
 */
class Api
{
public:
    static std::unique_ptr<Api> createApi(thread::ThreadFactory& thread_factory,
                                          frm_event::TimeSystem& time_system,
                                          filesystem::Instance& file_system);

    virtual ~Api() = default;

    /**
     * Allocate a dispatcher.
     * @return frm_event::DispatcherPtr which is owned by the caller.
     */
    virtual frm_event::DispatcherPtr allocateDispatcher() PURE;

    /**
     * @return a reference to the ThreadFactory
     */
    virtual thread::ThreadFactory& threadFactory() PURE;

    /**
     * @return a reference to the filesystem::Instance
     */
    virtual filesystem::Instance& fileSystem() PURE;

    /**
     * @return a reference to the TimeSource
     */
    virtual TimeSource& timeSource() PURE;

    /**
     * @return an optional reference to the ProcessContext
     */
    virtual ProcessContextOptRef processContext() PURE;
};

using ApiPtr = std::unique_ptr<Api>;

} // namespace api
} // namespace orchid
