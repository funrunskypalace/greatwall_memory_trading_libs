#pragma once

#include <chrono>
#include <functional>
#include <memory>

#include "orchid/common/common.h"
#include "orchid/common/time.h"

namespace orchid
{

class ScopeTrackedObject;

namespace frm_event // ±‹√‚”ÎLibEventµƒevent struct≥ÂÕª
{

class Dispatcher;

/**
 * Callback invoked when a timer event fires.
 */
using TimerCb = std::function<void()>;

/**
 * An abstract timer event. Free the timer to unregister any pending timeouts.
 * Must be freed before the dispatcher is torn down.
 */
class Timer
{
public:
    virtual ~Timer() = default;

    /**
     * Disable a pending timeout without destroying the underlying timer.
     */
    virtual void disableTimer() PURE;

    /**
     * Enable a pending timeout. If a timeout is already pending, it will be
     * reset to the new timeout.
     *
     * @param ms supplies the duration of the alarm in milliseconds.
     * @param object supplies an optional scope for the duration of the alarm.
     */
    virtual void enableTimer(const std::chrono::milliseconds& ms,
                             const ScopeTrackedObject* object = nullptr) PURE;

    /**
     * Enable a pending high resolution timeout. If a timeout is already
     * pending, it will be reset to the new timeout.
     *
     * @param us supplies the duration of the alarm in microseconds.
     * @param object supplies an optional scope for the duration of the alarm.
     */
    virtual void enableHRTimer(const std::chrono::microseconds& us,
                               const ScopeTrackedObject* object = nullptr) PURE;
    /**
     * Return whether the timer is currently armed.
     */
    virtual bool enabled() PURE;
};

using TimerPtr = std::unique_ptr<Timer>;

class Scheduler
{
public:
    virtual ~Scheduler() = default;

    /**
     * Creates a timer.
     */
    virtual TimerPtr createTimer(const TimerCb& cb,
                                 Dispatcher& dispatcher) PURE;
};

using SchedulerPtr = std::unique_ptr<Scheduler>;

/**
 * Interface providing a mechanism to measure time and set timers that run
 * callbacks when the timer fires.
 */
class TimeSystem : public TimeSource
{
public:
    static std::unique_ptr<TimeSystem> createTimeSystem();

    ~TimeSystem() override = default;

    using Duration = MonotonicTime::duration;

    /**
     * Creates a timer factory. This indirection enables thread-local
     * timer-queue management, so servers can have a separate timer-factory in
     * each thread.
     */
    virtual SchedulerPtr createScheduler(Scheduler& base_scheduler) PURE;

    /**
     * @return current nano time in int64_t (unix-timestamp * 1e9 + nano-part)
     */
    virtual int64_t nowInNano() PURE;
};

} // namespace frm_event
} // namespace orchid
