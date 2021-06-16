#pragma once

#include "orchid/common/common.h"

#include "absl/types/optional.h"

namespace orchid
{

/**
 * Represents some other part of the process.
 */
class ProcessObject
{
public:
    virtual ~ProcessObject() = default;
};

using ProcessObjectOptRef =
    absl::optional<std::reference_wrapper<ProcessObject>>;

/**
 * Context passed to filters to access resources from non-orchid parts of the
 * process.
 */
class ProcessContext
{
public:
    virtual ~ProcessContext() = default;

    /**
     * @return the ProcessObject for this context.
     */
    virtual ProcessObject& get() const PURE;
};

using ProcessContextOptRef =
    absl::optional<std::reference_wrapper<ProcessContext>>;

} // namespace orchid
