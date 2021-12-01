// Advent of Code: Day 1
// Lento Manickathan
#include <chrono>
#include <fstream>
#include <vector>
#include <string>
#include <fmt/ranges.h>

inline std::string passed_or_failed(uint32_t answer, uint32_t truth)
{
    return answer == truth ? "\x1B[1m\x1B[32mPASS\033[0m" : "\x1B[1m\x1B[31mFAIL\033[0m (=" + std::to_string(truth) + ")";
}

static uint32_t problem1(std::string filename)
{
    // Read file
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("Failed to open!");

    // Number of valid depths
    uint32_t answer = 0;

    // Check number of increasing depths
    uint32_t old_depth = -1, new_depth;
    while (file >> new_depth)
    {
        if (new_depth > old_depth)
            answer++;
        old_depth = new_depth;
    }
    
    return answer;
}

static uint32_t problem2(std::string filename)
{
    // Read file
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("Failed to open!");
    
    // Answer
    uint32_t answer = 0;

    return answer;
}

int main()
{
    // Header info
    constexpr int day = 1;
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");
    
    // Test input
    uint32_t test_answer1 = problem1("test_input.txt");
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n", test_answer1, 
                passed_or_failed(test_answer1, 7));
    uint32_t test_answer2 = problem2("test_input.txt");
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n", test_answer2, 
                passed_or_failed(test_answer1, 5));
    
    // Problem 1
    auto start = std::chrono::high_resolution_clock::now();
    uint32_t answer1 = problem1("input.txt");
    auto end = std::chrono::high_resolution_clock::now();
    fmt::print(">> Problem 1: answer = {} [{} μs]\n", answer1, 
                std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    

}
