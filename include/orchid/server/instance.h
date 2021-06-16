#pragma once

#include <chrono>
#include <cstdint>
#include <string>

#include "orchid/api/api.h"
#include "orchid/common/common.h"
#include "orchid/event/dispatcher.h"
#include "orchid/grpc/context.h"
#include "orchid/init/manager.h"
#include "orchid/protobuf/message_validator.h"
#include "orchid/runtime/runtime.h"
#include "orchid/server/hot_restart.h"
#include "orchid/server/lifecycle_notifier.h"
#include "orchid/server/listener_manager.h"
#include "orchid/server/options.h"
#include "orchid/singleton/manager.h"
#include "orchid/thread_local/thread_local.h"

namespace orchid
{
namespace server
{

/**
 * An instance of the running server.
 */
class Instance
{
public:
    virtual ~Instance() = default;

    virtual orchid::config::bootstrap::v2::Bootstrap& bootstrap() PURE;

    /**
     * @return api::Api& the API used by the server.
     */
    virtual api::Api& api() PURE;

    /**
     * @return frm_event::Dispatcher& the main thread's dispatcher. This
     * dispatcher should be used for all singleton processing.
     */
    virtual frm_event::Dispatcher& dispatcher() PURE;

    virtual server::GuardDog& guardDog() PURE;

    /**
     * @return the server's init manager. This can be used for extensions that
     * need to initialize after cluster manager init but before the server
     * starts listening. All extensions should register themselves during
     * configuration load. initialize() will be called on each registered target
     * after cluster manager init but before the server starts listening. Once
     * all targets have initialized and invoked their callbacks, the server will
     * start listening.
     */
    virtual Init::Manager& initManager() PURE;

    /**
     * @return the server's listener manager.
     */
    virtual ListenerManager& listenerManager() PURE;

    /**
     * @return the server's CLI options.
     */
    virtual const Options& options() PURE;

    /**
     * @return RandomGenerator& the random generator for the server.
     */
    virtual runtime::RandomGenerator& random() PURE;

    /**
     * @return the server's hot restarter.
     */
    virtual HotRestart& hotRestart() PURE;

    /**
     * @return ServerLifecycleNotifier& the singleton lifecycle notifier for the
     * server.
     */
    virtual ServerLifecycleNotifier& lifecycleNotifier() PURE;

    /**
     * Shutdown the server gracefully.
     */
    virtual void shutdown() PURE;

    /**
     * @return whether the shutdown method has been called.
     */
    virtual bool isShutdown() PURE;

    /**
     * @return Singleton::Manager& the server-wide singleton manager.
     */
    virtual Singleton::Manager& singletonManager() PURE;

    /**
     * @return the time that the server started during the current hot restart
     * epoch.
     */
    virtual time_t startTimeCurrentEpoch() PURE;

    /**
     * @return the time that the server started the first hot restart epoch.
     */
    virtual time_t startTimeFirstEpoch() PURE;

    /**
     * @return ThreadLocal::Instance& the thread local storage engine for the
     * server. This is used to allow runtime lockless updates to configuration,
     * etc. across multiple threads.
     */
    virtual ThreadLocal::Instance& threadLocal() PURE;

    /**
     * @return the time source used for the server.
     */
    virtual TimeSource& timeSource() PURE;

    /**
     * @return ProtobufMessage::ValidationContext& validation context for
     * configuration messages.
     */
    virtual ProtobufMessage::ValidationContext& messageValidationContext() PURE;
};

} // namespace server
} // namespace orchid
