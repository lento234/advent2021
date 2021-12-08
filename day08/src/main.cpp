// Advent of Code: Day 08
// Lento Manickathan
#include <chrono>
#include <fmt/ranges.h>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

static uint64_t problem1(utils::Text<std::string>& input)
{
    // Answer
    uint64_t answer = 0;

    for (size_t i = 0; i < input.size(); i = i + 15)
    {
        for (size_t j = 0; j < 4; ++j)
        {
            size_t word_size = input[i + 11 + j].size();
            if (word_size == 2 || word_size == 3 || word_size == 4 || word_size == 7)
                answer++;
        }
    }
    return answer;
}

static uint64_t problem2(utils::Text<std::string>& input)
{
    // Answer
    int64_t answer = 0;

    return answer;
}

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 8;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    uint64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint64_t>(test_answer1, 26));

    uint64_t test_answer2 = problem2(test_input);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint64_t>(test_answer2, 61229));

    // // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // // Problem 2
    // fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
