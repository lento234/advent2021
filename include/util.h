#pragma once

#include <chrono>
#include <fmt/ranges.h>
#include <fstream>
#include <string>
#include <vector>

inline std::string pass_or_fail(uint32_t answer, uint32_t truth)
{
    return answer == truth ? "\x1B[1m\x1B[32mPASS\033[0m" : "\x1B[1m\x1B[31mFAIL\033[0m (=" + std::to_string(truth) + ")";
}

class Timer
{
public:
    std::chrono::time_point<std::chrono::system_clock> start;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        auto end = std::chrono::high_resolution_clock::now();
        fmt::print("\n>> [Summary] Total elapsed = {} μs\n\n",
                   std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
};

template <typename T>
struct Text
{
    std::vector<T> raw;

    //inline std::vector<std::string> read_file(const std::string& filename)
    Text(const std::string& filename)
    {
        // Read file
        std::ifstream file(filename);
        if (!file.is_open())
            throw std::runtime_error("Failed to open file!");

        // Buffer file
        T buffer;
        while (file >> buffer)
            raw.push_back(buffer);
        file.close();
    }

    inline size_t size() { return raw.size(); }

    void print()
    {
        fmt::print("  {}\n\n", fmt::join(raw, "\n  "));
    }

    T& operator[](const size_t i) { return raw[i]; }

    auto begin() { return raw.begin(); }
    auto end() { return raw.end(); }
};