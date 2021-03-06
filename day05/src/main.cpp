// Advent of Code: Day 05
// Lento Manickathan
#include <fmt/ranges.h>
#include <sstream>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

#include "core.h"

static uint32_t problem1(const std::string& filename)
{
    // Read file
    auto text = utils::Text<std::string>(filename);

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

static uint32_t problem2(const std::string& filename)
{
    // Read file
    auto text = utils::Text<std::string>(filename);

    // Generate map and get points
    auto map = Map(text, true);
    auto points = map.points; // Get map points

    // Find number of points larger than 2
    uint32_t answer = 0;
    for (auto& point : points)
        if (point >= 2)
            answer++;

    return answer;
}

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 05;

    // Header info
    fmt::print("\nš Advent of Code: Day {} š\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    uint32_t test_answer1 = problem1("test_input.txt");
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint8_t>(test_answer1, 5));

    uint32_t test_answer2 = problem2("test_input.txt");
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint8_t>(test_answer2, 12));

    //Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1("input.txt"));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem2("input.txt"));
}
