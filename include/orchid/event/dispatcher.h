#pragma once

#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "orchid/common/common.h"
#include "orchid/event/timer.h"

namespace orchid
{
namespace frm_event // 避免与LibEvent的event struct冲突
{

/**
 * Callback invoked when a dispatcher post() runs.
 */
using PostCb = std::function<void()>;

/**
 * Abstract event dispatching loop.
 */
class Dispatcher
{
public:
    virtual ~Dispatcher() = default;

    virtual TimeSource& timeSource() PURE;

    /**
     * Clear any items in the deferred deletion queue.
     */
    // virtual void clearDeferredDeleteList() PURE;

    /**
     * Allocate a timer. @see Timer for docs on how to use the timer.
     * @param cb supplies the callback to invoke when the timer fires.
     */
    virtual frm_event::TimerPtr createTimer(TimerCb cb) PURE;

    /**
     * Exit the event loop.
     */
    virtual void exit() PURE;

    /**
     * 给dispatcher发送一个functor。跨线程安全。这个functor将在dispatcher的线程/事件循环
     * 中执行，可能是在调用者不同的其他线程。
     */
    virtual void post(PostCb callback) PURE;

    /**
     * Run the event loop. This will not return until exit() is called either
     * from within a callback or from a different thread.
     * @param type specifies whether to run in blocking mode (run() will not
     * return until exit() is called) or non-blocking mode where only active
     * events will be executed and then run() will return.
     */
    enum class RunType
    {
        Block,       // Executes any events that have been activated, then exit.
        NonBlock,    // Waits for any pending events to activate, executes them,
                     // then exits. Exits immediately if there are no pending or
                     // active events.
        RunUntilExit // Runs the event-loop until loopExit() is called, blocking
                     // until there are pending or active events.
    };
    virtual void run(RunType type) PURE;

    /**
     * Validates that an operation is thread-safe with respect to this
     * dispatcher; i.e. that the current thread of execution is on the same
     * thread upon which the dispatcher loop is running.
     */
    virtual bool isThreadSafe() const PURE;

    /**
     * Sets a tracked object, which is currently operating in this Dispatcher.
     * This should be cleared with another call to setTrackedObject() when the
     * object is done doing work. Calling setTrackedObject(nullptr) results in
     * no object being tracked.
     *
     * This is optimized for performance, to avoid allocation where we do scoped
     * object tracking.
     *
     * @return The previously tracked object or nullptr if there was none.
     */
    virtual const ScopeTrackedObject*
    setTrackedObject(const ScopeTrackedObject* object) PURE;

    /**
     * Returns a recently cached MonotonicTime value.
     */
    virtual MonotonicTime approximateMonotonicTime() const PURE;

    /**
     * Updates approximate monotonic time to current value.
     */
    virtual void updateApproximateMonotonicTime() PURE;
};

using DispatcherPtr = std::unique_ptr<Dispatcher>;

} // namespace frm_event
} // namespace orchid
