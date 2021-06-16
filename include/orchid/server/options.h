#pragma once

#include <chrono>
#include <cstdint>
#include <string>

#include "orchid/common/common.h"
#include "orchid/config/bootstrap/v2/bootstrap.pb.h"

#include "spdlog/spdlog.h"

namespace orchid
{
namespace server
{

enum class Mode
{
    Serve,
    Validate,
    InitOnly,
};

class Options
{
public:
    virtual ~Options() = default;

    /**
     * @return uint64_t the base ID for the server. This is required for
     * system-wide things like shared memory, domain sockets, etc. that are used
     * during hot restart. Setting the base ID to a different value will allow
     * the server to run multiple times on the same host if desired.
     */
    virtual uint64_t baseId() const PURE;

    /**
     * @return the number of worker threads to run in the server.
     */
    virtual uint32_t concurrency() const PURE;

    virtual const std::string& configPath() const PURE;

    /**
     * @return const std::string& an inline YAML bootstrap config that merges
     *                            into the config loaded in configPath().
     */
    virtual const std::string& configYaml() const PURE;

    /**
     * @return const orchid::config::bootstrap::v2::Bootstrap& a bootstrap proto
     * object that merges into the config last, after configYaml and configPath.
     */
    virtual const orchid::config::bootstrap::v2::Bootstrap&
    configProto() const PURE;

    /**
     * @return the restart epoch. 0 indicates the first server start, 1 the
     * second, and so on.
     */
    virtual uint64_t restartEpoch() const PURE;

    virtual server::Mode mode() const PURE;

    /**
     * @return std::chrono::milliseconds the duration in msec between log
     * flushes.
     */
    virtual std::chrono::milliseconds fileFlushIntervalMsec() const PURE;

    /**
     * @return spdlog::level::level_enum the default log level for the server.
     */
    virtual spdlog::level::level_enum logLevel() const PURE;

    /**
     * @return const std::string& the log format string.
     */
    virtual const std::string& logFormat() const PURE;

    /**
     * @return const std::string& the log file path.
     */
    virtual const std::string& logPath() const PURE;

    /**
     * @return bool indicating whether the hot restart functionality has been
     * disabled via cli flags.
     */
    virtual bool hotRestartDisabled() const PURE;

    /**
     * @return bool indicating whether system signal listeners are enabled.
     */
    virtual bool signalHandlingEnabled() const PURE;

    /**
     * @return whether to use the old libevent evbuffer-based Buffer
     * implementation.
     */
    virtual bool libeventBufferEnabled() const PURE;

    /**
     * @return bool indicating whether cpuset size should determine the number
     * of worker threads.
     */
    virtual bool cpusetThreadsEnabled() const PURE;

    /**
     * @return bool allow unknown fields in the static configuration?
     */
    virtual bool allowUnknownStaticFields() const PURE;

    /**
     * @return bool allow unknown fields in the dynamic configuration?
     */
    virtual bool rejectUnknownDynamicFields() const PURE;
};

} // namespace server
} // namespace orchid
