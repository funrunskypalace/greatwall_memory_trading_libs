#pragma once

#include <atomic>
#include <memory>
#include <thread>

#include "orchid/common/exception.h"
#include "orchid/common/pure.h"

namespace orchid
{

/// ÿ��ģ��(DLL/EXE)��Ӧ�ø��Ե���orchid_init�����Լ�����־�ļ���
void orchid_init(const char* logPathName, const char* loggerName, int logLevel,
                 int consoleLevel, const std::string& logFormat);

using thread_ptr = std::shared_ptr<std::thread>;
} // namespace orchid

#include "orchid/common/logger.h"