#pragma once

#include "orchid/common/common.h"

namespace orchid
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

    virtual const std::string& configPath() const = 0;

    /**
     * @return const std::string& an inline YAML bootstrap config that
     merges into the config loaded in configPath().
     */
    // virtual const std::string& configYaml() const PURE;

    virtual Mode mode() const = 0;

    /**
     * @return spdlog::level::level_enum the default log level for the server.
     */
    virtual int logLevel() const = 0;

    /**
     * @return const std::string& the log format string.
     */
    virtual const std::string& logFormat() const = 0;

    /**
     * @return const std::string& the log file path.
     */
    virtual const std::string& logPath() const = 0;

    virtual int consoleLevel() const = 0;

    virtual bool interactive() const = 0;
};

} // namespace orchid