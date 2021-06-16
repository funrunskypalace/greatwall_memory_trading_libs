#pragma once

#include <functional>
#include <limits>
#include <memory>
#include <string>

#include "orchid/common/common.h"

#include "absl/base/thread_annotations.h"

#ifndef ABSL_LOCKABLE
#define ABSL_LOCKABLE LOCKABLE
#define ABSL_EXCLUSIVE_LOCK_FUNCTION EXCLUSIVE_LOCK_FUNCTION
#define ABSL_UNLOCK_FUNCTION UNLOCK_FUNCTION
#define ABSL_EXCLUSIVE_TRYLOCK_FUNCTION EXCLUSIVE_TRYLOCK_FUNCTION
#define ABSL_SHARED_TRYLOCK_FUNCTION SHARED_TRYLOCK_FUNCTION
#define ABSL_ASSERT_EXCLUSIVE_LOCK ASSERT_EXCLUSIVE_LOCK
#define ABSL_ASSERT_SHARED_LOCK ASSERT_SHARED_LOCK
#define ABSL_NO_THREAD_SAFETY_ANALYSIS NO_THREAD_SAFETY_ANALYSIS
#endif

namespace orchid
{
namespace thread
{

/**
 * An id for a thread.
 */
class ThreadId
{
public:
    ThreadId() : id_(std::numeric_limits<int64_t>::min()) {}
    explicit ThreadId(int64_t id) : id_(id) {}

    std::string debugString() const { return std::to_string(id_); }
    bool isEmpty() const { return *this == ThreadId(); }
    friend bool operator==(ThreadId lhs, ThreadId rhs)
    {
        return lhs.id_ == rhs.id_;
    }
    friend bool operator!=(ThreadId lhs, ThreadId rhs)
    {
        return lhs.id_ != rhs.id_;
    }
    template <typename H> friend H AbslHashValue(H h, ThreadId id)
    {
        return H::combine(std::move(h), id.id_);
    }

private:
    int64_t id_;
};

class Thread
{
public:
    virtual ~Thread() = default;

    /**
     * Join on thread exit.
     */
    virtual void join() PURE;
};

using ThreadPtr = std::unique_ptr<Thread>;

/**
 * Interface providing a mechanism for creating threads.
 */
class ThreadFactory
{
public:
    static std::unique_ptr<ThreadFactory> createThreadFactory();

    virtual ~ThreadFactory() = default;

    /**
     * Create a thread.
     * @param thread_routine supplies the function to invoke in the thread.
     */
    virtual ThreadPtr createThread(std::function<void()> thread_routine) PURE;

    /**
     * Return the current system thread ID
     */
    virtual ThreadId currentThreadId() PURE;
};

/**
 * Like the C++11 "basic lockable concept" but a pure virtual interface vs. a
 * template, and with thread annotations.
 */
class ABSL_LOCKABLE BasicLockable
{
public:
    virtual ~BasicLockable() = default;

    virtual void lock() ABSL_EXCLUSIVE_LOCK_FUNCTION() PURE;
    virtual bool tryLock() ABSL_EXCLUSIVE_TRYLOCK_FUNCTION(true) PURE;
    virtual void unlock() ABSL_UNLOCK_FUNCTION() PURE;
};

} // namespace thread
} // namespace orchid
