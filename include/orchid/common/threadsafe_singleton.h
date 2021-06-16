#pragma once

#include <memory>

#include "orchid/common/assert.h"

#include "absl/base/call_once.h"

namespace orchid
{

/**
 * ThreadSafeSingleton allows easy global cross-thread access to a non-const object.
 *
 * This singleton class should be used for singletons which must be globally
 * accessible but can not be marked as const. All functions in the singleton class
 * *must* be threadsafe.
 *
 * Note that there is heavy resistance in  to adding this type of singleton
 * if data will persist with state changes across tests, as it becomes difficult
 * to write clean unit tests if a state change in one test will persist into
 * another test. Be wary of using it. A example of acceptable usage is OsSyscallsImpl,
 * where the functions are not strictly speaking const, but affect the OS rather than the
 * class itself. An example of unacceptable usage upstream would be for
 * globally accessible stat counters, it would have the aforementioned problem
 * where state "leaks" across tests.
 *
 * */
template <class T>
class ThreadSafeSingleton
{
public:
    static T& get()
    {
        absl::call_once(ThreadSafeSingleton<T>::create_once_, &ThreadSafeSingleton<T>::Create);
        return *ThreadSafeSingleton<T>::instance_;
    }

protected:
    template <typename A>
    friend class TestThreadsafeSingletonInjector;

    static void Create() { instance_ = new T(); }

    static absl::once_flag create_once_;
    static T* instance_;
};

template <class T>
absl::once_flag ThreadSafeSingleton<T>::create_once_;

template <class T>
T* ThreadSafeSingleton<T>::instance_ = nullptr;

// An instance of a singleton class which has the same thread safety properties
// as ThreadSafeSingleton, but must be created via initialize prior to access.
//
// As with ThreadSafeSingleton the use of this class is generally discouraged.
template <class T>
class InjectableSingleton
{
public:
    static T& get()
    {
        RELEASE_ASSERT(loader_ != nullptr, "InjectableSingleton used prior to initialization");
        return *loader_;
    }

    static T* getExisting() { return loader_; }

    static void initialize(T* value)
    {
        RELEASE_ASSERT(value != nullptr, "InjectableSingleton initialized with non-null value.");
        RELEASE_ASSERT(loader_ == nullptr, "InjectableSingleton initialized multiple times.");
        loader_ = value;
    }
    static void clear() { loader_ = nullptr; }

protected:
    static T* loader_;
};

template <class T>
T* InjectableSingleton<T>::loader_ = nullptr;

template <class T>
class ScopedInjectableLoader
{
public:
    ScopedInjectableLoader(std::unique_ptr<T>&& instance)
    {
        instance_ = std::move(instance);
        InjectableSingleton<T>::initialize(instance_.get());
    }
    ~ScopedInjectableLoader() { InjectableSingleton<T>::clear(); }

private:
    std::unique_ptr<T> instance_;
};

} // namespace orchid