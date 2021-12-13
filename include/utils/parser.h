#pragma once

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace utils
{
inline bool contains(const std::string& str, const std::string& match)
{
    return str.find(match) != std::string::npos;
}

template <typename T>
inline bool is_inside(const std::vector<T>& list, const T& item)
{
    return std::find(list.begin(), list.end(), item) != list.end();
}

inline std::vector<std::string> split_string(const std::string& str, const char& delim)
{
    std::vector<std::string> result;
    std::stringstream ss(str);

    for (std::string token; getline(ss, token, delim);)
        result.push_back(token);
    return result;
}

template <typename T>
inline std::vector<T> split_numbers(const std::string& str, const char& delim)
{
    std::vector<T> result;
    std::stringstream ss(str);

    for (std::string token; getline(ss, token, delim);)
        result.push_back(std::stoi(token));
    return result;
}

template <typename T>
inline std::string pass_or_fail(const T& answer, const T& truth)
{
    return answer == truth ? "\x1B[1m\x1B[32mPASS\033[0m" : "\x1B[1m\x1B[31mFAIL\033[0m (=" + std::to_string(truth) + ")";
}

template <typename T>
struct Text
{
    std::vector<T> raw;

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

    inline size_t size() const { return raw.size(); }

    void print() const
    {
        fmt::print("  {}\n\n", fmt::join(raw, "\n  "));
    }

    const T& operator[](const size_t& i) { return raw[i]; }

    auto begin() { return raw.begin(); }
    auto end() { return raw.end(); }
};

} // namespace utils
