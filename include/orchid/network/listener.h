#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "orchid/api/io_error.h"
#include "orchid/common/exception.h"

namespace orchid
{
namespace Network
{

/**
 * A configuration for an individual listener.
 */
class ListenerConfig
{
public:
    virtual ~ListenerConfig() = default;

    /**
     * @return uint64_t the tag the listener should use for connection handler
     * tracking.
     */
    virtual uint64_t listenerTag() const PURE;

    /**
     * @return const std::string& the listener's name.
     */
    virtual const std::string& name() const PURE;
};

/**
 * Callbacks invoked by a listener.
 */
class ListenerCallbacks
{
public:
    virtual ~ListenerCallbacks() = default;
};

/**
 * An abstract socket listener. Free the listener to stop listening on the
 * socket.
 */
class Listener
{
public:
    virtual ~Listener() = default;

    /**
     * Temporarily disable accepting new connections.
     */
    virtual void disable() PURE;

    /**
     * Enable accepting new connections.
     */
    virtual void enable() PURE;
};

using ListenerPtr = std::unique_ptr<Listener>;

/**
 * Thrown when there is a runtime error creating/binding a listener.
 */
class CreateListenerException : public OrchidException
{
public:
    CreateListenerException(const std::string& what) : OrchidException(what) {}
};

} // namespace Network
} // namespace orchid
