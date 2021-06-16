#pragma once

#include "framework/common/common.h"

namespace framework { namespace trade {

class ExecutorFunc {
public:
    virtual bool operator()(double price, int direction) PURE;
};
using ExecutorFuncPtr = std::shared_ptr<ExecutorFunc>;

}} // namespace framework::trade