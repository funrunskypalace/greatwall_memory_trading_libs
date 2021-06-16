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
    ///��ȡ��Ӧ�Ĳ���ֵ
    bool getValue(const std::string& section, const std::string& name,
        char* buffer, size_t bufsiz);
    bool getValue(const std::string& section, const std::string& name,
        std::string& value);
    bool getInt(const std::string& section, const std::string& name,
                int32_t& value);
    bool getInt(const std::string& section, const std::string& name,
                int64_t& value);

    /// ����Ҫ��ȡ���ļ�����
    bool initialize(const std::string& file);

    /// �����ȡ������
    std::string print();

protected:
    /// ����������ļ�
    void parse(const std::string& ini);

    /// �޳��ո���ַ�
    static void trimStr(std::string& str, const char* space = " \t\r\n");

private:
    ///�洢��ȡ������
    std::map<std::string, std::map<std::string, std::string>> _valueMap;
};

} // namespace utility
} // namespace orchid