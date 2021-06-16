#pragma once

#include "orchid/api/v2/lds.pb.h"
#include "orchid/network/listener.h"
#include "orchid/server/guarddog.h"

#include "common/protobuf/protobuf.h"

namespace orchid
{
namespace server
{

/**
 * Factory for creating listener components.
 */
class ListenerComponentFactory
{
public:
    virtual ~ListenerComponentFactory() = default;

    /**
     * @return uint64_t a listener tag usable for connection handler tracking.
     */
    virtual uint64_t nextListenerTag() PURE;
};

/**
 * A manager for all listeners and all threaded connection handling workers.
 */
class ListenerManager
{
public:
    virtual ~ListenerManager() = default;

    virtual bool addOrUpdateListener(const orchid::api::v2::Listener& config,
                                     const std::string& version_info,
                                     bool modifiable) PURE;

    /**
     * @return std::vector<std::reference_wrapper<Network::ListenerConfig>> a
     * list of the currently loaded listeners. Note that this routine returns
     * references to the existing listeners. The references are only valid in
     * the context of the current call stack and should not be stored.
     */
    virtual std::vector<std::reference_wrapper<Network::ListenerConfig>>
    listeners() PURE;

    /**
     * @return uint64_t the total number of connections owned by all listeners
     * across all workers.
     */
    virtual uint64_t numConnections() PURE;

    /**
     * Remove a listener by name.
     * @param name supplies the listener name to remove.
     * @return TRUE if the listener was found and removed. Note that when this
     * routine returns TRUE, the listener has not necessarily been actually
     * deleted right away. The listener will be drained and fully removed at
     * some later time.
     */
    virtual bool removeListener(const std::string& name) PURE;

    /**
     * Start all workers accepting new connections on all added listeners.
     * @param guard_dog supplies the guard dog to use for thread watching.
     */
    virtual void startWorkers(GuardDog& guard_dog) PURE;

    /**
     * Stop all listeners from accepting new connections without actually
     * removing any of them. This is used for server draining.
     */
    virtual void stopListeners() PURE;

    /**
     * Stop all threaded workers from running. When this routine returns all
     * worker threads will have exited.
     */
    virtual void stopWorkers() PURE;
};

} // namespace server
} // namespace orchid
