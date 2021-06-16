#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "orchid/common/common.h"

#include "common/singleton/threadsafe_singleton.h"
#include "orchid/common/assert.h"

#include "absl/container/flat_hash_map.h"
#include "absl/types/optional.h"

namespace orchid
{

namespace runtime
{

/**
 * Random number generator. Implementations should be thread safe.
 */
class RandomGenerator
{
public:
    virtual ~RandomGenerator() = default;

    /**
     * @return uint64_t a new random number.
     */
    virtual uint64_t random() PURE;

    /**
     * @return std::string containing uuid4 of 36 char length.
     * for example, 7c25513b-0466-4558-a64c-12c6704f37ed
     */
    virtual std::string uuid() PURE;
};

using RandomGeneratorPtr = std::unique_ptr<RandomGenerator>;

} // namespace runtime
} // namespace orchid
