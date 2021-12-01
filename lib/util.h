#pragma once

#include <string>
#include <vector>
#include <fstream>

inline std::string passed_or_failed(uint32_t answer, uint32_t truth)
{
    return answer == truth ? "\x1B[1m\x1B[32mPASS\033[0m" : "\x1B[1m\x1B[31mFAIL\033[0m (=" + std::to_string(truth) + ")";
}

template <typename T>
struct Message
{
    std::vector<T> content;
    size_t n_lines;
    
    //inline std::vector<std::string> read_file(const std::string& filename)
    Message(const std::string& filename)
    {
        // Read file
        std::ifstream file(filename);
        if (!file.good())
            throw std::runtime_error("Failed to open!");

        // Buffer file
        T buffer;
        while (file >> buffer)
            content.push_back(buffer);
        
        // Close the file.
        file.close();
       
    }

    inline size_t size() { return content.size(); }

};