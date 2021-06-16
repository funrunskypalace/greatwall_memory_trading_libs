#pragma once

#include <chrono>
#include <cstdint>
#include <list>
#include <memory>
#include <string>
#include <vector>

#include "orchid/common/common.h"

#include "absl/types/optional.h"

namespace orchid
{
namespace server
{
namespace Configuration
{

/**
 * The main server configuration.
 */
class Main
{
public:
    virtual ~Main() = default;

    /**
     * @return std::chrono::milliseconds the time interval after which we count
     * a nonresponsive thread event as a "miss" statistic.
     */
    virtual std::chrono::milliseconds wdMissTimeout() const PURE;

    /**
     * @return std::chrono::milliseconds the time interval after which we count
     * a nonresponsive thread event as a "mega miss" statistic.
     */
    virtual std::chrono::milliseconds wdMegaMissTimeout() const PURE;

    /**
     * @return std::chrono::milliseconds the time interval after which we kill
     * the process due to a single nonresponsive thread.
     */
    virtual std::chrono::milliseconds wdKillTimeout() const PURE;

    /**
     * @return std::chrono::milliseconds the time interval after which we kill
     * the process due to multiple nonresponsive threads.
     */
    virtual std::chrono::milliseconds wdMultiKillTimeout() const PURE;
};

/**
 * Admin configuration.
 */
class Admin
{
public:
    virtual ~Admin() = default;

    /**
     * @return const std::string& the admin access log path.
     */
    virtual const std::string& accessLogPath() PURE;

    /**
     * @return const std::string& profiler output path.
     */
    virtual const std::string& profilePath() PURE;
};

/**
 * Initial configuration values that are needed before the main configuration
 * load.
 */
class Initial
{
public:
    virtual ~Initial() = default;

    /**
     * @return Admin& the admin config.
     */
    virtual Admin& admin() PURE;

    /**
     * @return absl::optional<std::string> the path to look for flag files.
     */
    virtual absl::optional<std::string> flagsPath() PURE;
};

} // namespace Configuration
} // namespace server
} // namespace orchid
