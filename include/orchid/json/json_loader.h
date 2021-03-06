#pragma once

#if false

#include <list>
#include <string>

#include "orchid/api/api.h"
#include "orchid/json/json_object.h"

namespace orchid
{
namespace Json
{

class Factory
{
public:
    /**
     * Constructs a Json Object from a file.
     */
    static ObjectSharedPtr loadFromFile(const std::string& file_path,
                                        api::Api& api);

    /**
     * Constructs a Json Object from a string.
     */
    static ObjectSharedPtr loadFromString(const std::string& json);

    /**
     * Constructs a Json Object from a YAML string.
     */
    static ObjectSharedPtr loadFromYamlString(const std::string& yaml);

    static const std::string
    listAsJsonString(const std::list<std::string>& items);
};

} // namespace Json
} // namespace orchid

#endif