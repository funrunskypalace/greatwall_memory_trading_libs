#pragma once

#include <memory>

namespace orchid
{
namespace Grpc
{

/**
 * Captures grpc-related structures with cardinality of one per server.
 */
class Context
{
public:
    virtual ~Context() = default;

    enum class Protocol
    {
        Grpc,
        GrpcWeb
    };

    struct RequestNames;
};

using ContextPtr = std::unique_ptr<Context>;

} // namespace Grpc
} // namespace orchid
