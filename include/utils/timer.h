#pragma once

#include <chrono>
#include <fmt/core.h>

namespace utils
{
template <typename T = std::chrono::microseconds>
class Timer
{
public:
    std::chrono::time_point<std::chrono::system_clock> start;
    using time_t = T;
    std::string unit = "us";

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
        if (typeid(T).name() == typeid(std::chrono::microseconds).name())
            unit = "μs";
        else if (typeid(T).name() == typeid(std::chrono::milliseconds).name())
            unit = "ms";
        else if (typeid(T).name() == typeid(std::chrono::seconds).name())
            unit = "s";
        else if (typeid(T).name() == typeid(std::chrono::minutes).name())
            unit = "min";
        else if (typeid(T).name() == typeid(std::chrono::hours).name())
            unit = "h";
    }

    ~Timer()
    {
        auto end = std::chrono::high_resolution_clock::now();
        fmt::print("\n>> [Summary] Total elapsed = {} {}\n\n",
                   std::chrono::duration_cast<time_t>(end - start).count(),
                   unit);
    }
};

} // namespace utils