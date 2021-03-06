#pragma once

namespace orchid
{
/**
 * Mixin class that makes derived classes not copyable. Like boost::noncopyable
 * without boost.
 */
class NonCopyable
{
protected:
    NonCopyable() = default;

private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator=(const NonCopyable&);
};
} // namespace orchid
