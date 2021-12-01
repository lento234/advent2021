// Advent of Code: Day 1
// Lento Manickathan
#include <chrono>
#include <fstream>
#include <vector>
#include <string>
#include <fmt/ranges.h>

#include <util.h>

static uint32_t problem1(std::string filename)
{
    // Read file
    auto text = Message<uint32_t>(filename);

    // Number of valid depths
    uint32_t answer = 0;

    // Check number of increasing depths
    uint32_t prev_depth = -1;
    for (auto depth : text.content)
    {
        // Check if new depth is higher, then is valid
        if (depth > prev_depth)
            answer++;
        prev_depth = depth;
    }

    return answer;
}

static uint32_t problem2(std::string filename)
{
    // Read file
    auto text = Message<uint32_t>(filename);
    
    // Answer
    uint32_t answer = 0;

    // Check sum
    uint32_t prev_sum = -1, new_sum;
    for (size_t i=1; i<text.size()-1; ++i)
    {
        new_sum = text.content[i-1] + text.content[i] + text.content[i+1];
        if (new_sum > prev_sum)
            answer++;
        prev_sum = new_sum;
    }

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
                passed_or_failed(test_answer2, 5));
    
    // Problem 1
    auto start = std::chrono::high_resolution_clock::now();
    uint32_t answer1 = problem1("input.txt");
    auto end = std::chrono::high_resolution_clock::now();
    fmt::print(">> Problem 1: answer = {} [{} μs]\n", answer1, 
                std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    

    // Problem 2
    start = std::chrono::high_resolution_clock::now();
    uint32_t answer2 = problem2("input.txt");
    end = std::chrono::high_resolution_clock::now();
    fmt::print(">> Problem 2: answer = {} [{} μs]\n", answer2, 
                std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    
}
