#pragma once

#include "orchid/common/logger.h"
#include "orchid/influxdb/Point.h"

namespace orchid { namespace influxdb {
class InfluxDBClient {
public:
    /// <summary>
    /// Initialize environment, like dotnet.
    /// </summary>
    /// <param name="configJson"></param>
    /// <returns></returns>
    virtual int intitalize(const std::string& configJson) PURE;
    virtual int open() PURE;
    virtual int write(const std::string& bucket, const std::string& org, const Point& point) PURE;
};
using InfluxDBClientPtr = std::unique_ptr<InfluxDBClient>;

class InfluxDBFactory {
public:
    static InfluxDBClientPtr get(const std::string& url, const std::string& token);
};
}} // namespace orchid::influxdb