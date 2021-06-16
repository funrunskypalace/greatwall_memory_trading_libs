#pragma once

#include <sstream>
#include <stdexcept>
#include <string>

namespace orchid
{
/**
 * Base class for all orchid exceptions.
 */
class OrchidException : public std::runtime_error
{
public:
    OrchidException(const std::string& message) : std::runtime_error(message) {}
};

class CRuntimeError : public std::runtime_error
{
public:
    CRuntimeError(const char* file, int line, const std::string& what)
        : std::runtime_error(what)
    {
        std::ostringstream oss;
        oss << file << ":" << line << " " << what;
        err = oss.str();
    }

    ~CRuntimeError() throw() {}

    const char* what() const throw() { return err.c_str(); }

private:
    std::string err;
};

} // namespace orchid
