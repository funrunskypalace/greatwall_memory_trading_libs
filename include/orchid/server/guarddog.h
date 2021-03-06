#pragma once

#include "orchid/common/common.h"
#include "orchid/server/watchdog.h"

namespace orchid
{
namespace server
{

/**
 * The GuardDog runs a background thread which scans a number of shared WatchDog
 * objects periodically to verify that they have been recently touched. If some
 * of the watched items have not responded the GuardDog will take action ranging
 * from stats counter increments to killing the entire process (if a deadlock is
 * suspected).
 *
 * The lifespan of the GuardDog thread is tied to the lifespan of this object.
 */
class GuardDog
{
public:
    virtual ~GuardDog() = default;

    /**
     * Get a WatchDog object pointer to a new WatchDog.
     *
     * After this method returns the WatchDog object must be touched
     * periodically to avoid triggering the GuardDog. If no longer needed use
     * the stopWatching() method to remove it from the list of watched objects.
     *
     * @param thread_id a thread::ThreadId containing the system thread id
     */
    virtual WatchDogSharedPtr createWatchDog(thread::ThreadId thread_id) PURE;

    /**
     * Tell the GuardDog to forget about this WatchDog.
     * After calling this method it is no longer necessary to touch the WatchDog
     * object.
     *
     * @param wd A WatchDogSharedPtr obtained from createWatchDog.
     */
    virtual void stopWatching(WatchDogSharedPtr wd) PURE;
};

} // namespace server
} // namespace orchid
