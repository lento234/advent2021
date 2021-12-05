// Advent of Code: Day 05
// Lento Manickathan
#include <chrono>
#include <fmt/ranges.h>
#include <sstream>
#include <string>
#include <vector>

#include <util.h>

#include "core.h"

static uint32_t problem1(std::string filename)
{
    // Read file
    auto text = Text<std::string>(filename);

    // Generate map and get points
    auto map = Map(text);
    auto points = map.points; // Get map points
    
    // Find number of points larger than 2
    uint32_t answer = 0;
    for (auto& point : points)
        if (point >= 2)
            answer++;
    
    return answer;
}

/*
static int64_t problem2(std::string filename)
{
    // Read file
    auto text = Text<std::string>(filename);

    // Answer
    int64_t answer = 0;

    return answer;
}
*/

int main()
{
    auto timeit = Timer();

    constexpr uint8_t day = 05;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    uint32_t test_answer1 = problem1("test_input.txt");
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               pass_or_fail(test_answer1, 5));

    /*
    int64_t test_answer2 = problem2("test_input.txt");
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               pass_or_fail(test_answer2, 0));

    // // Problem 1
    int64_t answer1 = problem1("input.txt");
    fmt::print(">> Problem 1: answer = {}\n", answer1);

    // // Problem 2
    int64_t answer2 = problem2("input.txt");
    fmt::print(">> Problem 2: answer = {}\n", answer2);
    */
}
