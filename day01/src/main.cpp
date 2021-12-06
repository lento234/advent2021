// Advent of Code: Day 1
// Lento Manickathan
#include <chrono>
#include <fmt/ranges.h>
#include <fstream>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

static uint32_t problem1(std::string filename)
{
    // Read file
    auto text = utils::Text<uint32_t>(filename);

    // Number of valid depths
    uint32_t answer = 0;

    // Check number of increasing depths
    uint32_t prev_depth = -1;
    for (auto depth : text)
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
    auto text = utils::Text<uint32_t>(filename);

    // Answer
    uint32_t answer = 0;

    // Check sum
    uint32_t prev_sum = -1, new_sum;
    for (size_t i = 1; i < text.size() - 1; ++i)
    {
        new_sum = text[i - 1] + text[i] + text[i + 1];
        if (new_sum > prev_sum)
            answer++;
        prev_sum = new_sum;
    }

    return answer;
}

int main()
{
    auto timer = utils::Timer();

    constexpr uint8_t day = 1;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    uint32_t test_answer1 = problem1("test_input.txt");
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint8_t>(test_answer1, 7));

    uint32_t test_answer2 = problem2("test_input.txt");
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint8_t>(test_answer2, 5));

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1("input.txt"));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem2("input.txt"));
}
