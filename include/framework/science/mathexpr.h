#pragma once

#include "framework/common/common.h"

namespace framework { namespace science {

typedef enum ComparerType {
    Invalid = 0,
    LessEqual = 1,
    GreaterEqual = 2,
    Equal = 3,
    NotEqual = 4,
    LessThan = 5,
    GreaterThan = 6
} ComparerType;

class DiffObject {
public:
    DiffObject(double rvalue, ComparerType comparer);
    bool compare(double lvalue, double precision = 0.0000001) const;
    bool isValid() const;
    double rvalue() const;
    int direction() const;
    const char* directionStr() const;

private:
    double rvalue_ = {0};
    ComparerType comparer_ = {Invalid};
};
using DiffObjectPtr = std::unique_ptr<DiffObject>;

DiffObjectPtr parse_diff_expr(const std::string& expr);

bool meet_diff(double lvalue, const std::string& expr, double precision = 0.0000001);
}} // namespace framework::science
