#pragma once

#include "orchid/api/v2/core/grpc_service.pb.h"
#include "orchid/grpc/async_client.h"

namespace orchid
{
namespace Grpc
{

// Per-service factory for Grpc::RawAsyncClients. This factory is thread aware
// and will instantiate with thread local state. Clients will use
// ThreadLocal::Instance::dispatcher() for event handling.
class AsyncClientFactory
{
public:
    virtual ~AsyncClientFactory() = default;

    /**
     * Create a gRPC::RawAsyncClient.
     * @return RawAsyncClientPtr async client.
     */
    virtual RawAsyncClientPtr create() PURE;
};

using AsyncClientFactoryPtr = std::unique_ptr<AsyncClientFactory>;

// Singleton gRPC client manager. Grpc::AsyncClientManager can be used to create
// per-service Grpc::AsyncClientFactory instances. All manufactured
// Grpc::AsyncClients must be destroyed before the AsyncClientManager can be
// safely destructed.
class AsyncClientManager
{
public:
    virtual ~AsyncClientManager() = default;

    /**
     * Create a Grpc::AsyncClients factory for a service. Validation of the
     * service is performed and will raise an exception on failure.
     * @param grpc_service orchid::api::v2::core::GrpcService configuration.
     * @param scope stats scope.
     * @param skip_cluster_check if set to true skips checks for cluster
     * presence and being statically configured.
     * @return AsyncClientFactoryPtr factory for grpc_service.
     * @throws OrchidException when grpc_service validation fails.
     */
    virtual AsyncClientFactoryPtr factoryForGrpcService(
        const orchid::api::v2::core::GrpcService& grpc_service,
        Stats::Scope& scope, bool skip_cluster_check) PURE;
};

using AsyncClientManagerPtr = std::unique_ptr<AsyncClientManager>;

} // namespace Grpc
} // namespace orchid
