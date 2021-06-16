#pragma once

#include <string>
#include <map>

#include "orchid/common/logger.h"

namespace orchid
{
namespace utility
{

class IniReader
{
public:
    ///读取对应的参数值
    bool getValue(const std::string& section, const std::string& name,
        char* buffer, size_t bufsiz);
    bool getValue(const std::string& section, const std::string& name,
        std::string& value);
    bool getInt(const std::string& section, const std::string& name,
                int32_t& value);
    bool getInt(const std::string& section, const std::string& name,
                int64_t& value);

    /// 导入要读取的文件数据
    bool initialize(const std::string& file);

    /// 输出读取的内容
    std::string print();

protected:
    /// 解析输入的文件
    void parse(const std::string& ini);

    /// 剔除空格等字符
    static void trimStr(std::string& str, const char* space = " \t\r\n");

private:
    ///存储读取的数据
    std::map<std::string, std::map<std::string, std::string>> _valueMap;
};

} // namespace utility
} // namespace orchid