#pragma once

#include <memory>
#include <string>

#include "orchid/common/common.h"

#include "absl/strings/string_view.h"

namespace orchid
{
namespace AccessLog
{

class AccessLogFile
{
public:
    virtual ~AccessLogFile() = default;

    /**
     * Write data to the file.
     */
    virtual void write(absl::string_view) PURE;

    /**
     * Reopen the file.
     */
    virtual void reopen() PURE;

    /**
     * Synchronously flush all pending data to disk.
     */
    virtual void flush() PURE;
};

using AccessLogFileSharedPtr = std::shared_ptr<AccessLogFile>;

class AccessLogManager
{
public:
    virtual ~AccessLogManager() = default;

    /**
     * Reopen all of the access log files.
     */
    virtual void reopen() PURE;

    /**
     * Create a new access log file managed by the access log manager.
     * @param file_name specifies the file to create/open.
     * @return the opened file.
     */
    virtual AccessLogFileSharedPtr
    createAccessLog(const std::string& file_name) PURE;
};

using AccessLogManagerPtr = std::unique_ptr<AccessLogManager>;

} // namespace AccessLog
} // namespace orchid
