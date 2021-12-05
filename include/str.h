#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace util
{
static inline bool contains(const std::string& str, const std::string& match)
{
    return str.find(match) != std::string::npos;
}

static inline std::vector<std::string> split(const std::string& str, const char& delim)
{
    std::vector<std::string> result;
    std::stringstream ss(str);

    for (std::string token; getline(ss, token, delim);)
        result.push_back(token);
    return result;
}

} // namespace util
