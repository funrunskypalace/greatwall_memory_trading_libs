#pragma once

#include "orchid/common/common.h"
#include <memory>

namespace orchid
{

/**
 * All singletons must derive from this type.
 */
class Singleton
{
public:
    virtual ~Singleton() = default;
};

using SingletonPtr = std::shared_ptr<Singleton>;

} // namespace orchid
