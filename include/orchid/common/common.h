#pragma once

#include <atomic>
#include <memory>
#include <thread>

#include "orchid/common/exception.h"
#include "orchid/common/pure.h"

namespace orchid
{

/// 每个模块(DLL/EXE)都应该各自调用orchid_init创建自己的日志文件。
void orchid_init(const char* logPathName, const char* loggerName, int logLevel,
                 int consoleLevel, const std::string& logFormat);

using thread_ptr = std::shared_ptr<std::thread>;
} // namespace orchid

#include "orchid/common/logger.h"