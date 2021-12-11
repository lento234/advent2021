// Advent of Code: Day 11
// Lento Manickathan
#include <fmt/ranges.h>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

#include "core.h"

static uint64_t problem1(utils::Text<std::string>& input)
{
    Dumbopus dumbopus(input.raw);

    size_t n_steps = 100;
    uint64_t answer = 0;
    for (size_t i = 0; i < n_steps; ++i)
    {
        dumbopus.evolve();
        answer += dumbopus.count_flashes();
    }

    return answer;
}

static uint64_t problem2(utils::Text<std::string>& input)
{
    Dumbopus dumbopus(input.raw);

    size_t answer = 0;
    while (dumbopus.count_flashes() != 100)
    {
        dumbopus.evolve();
        answer++;
    }
    return answer;
}

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 11;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {:02d} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    uint64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint64_t>(test_answer1, 1656));

    uint64_t test_answer2 = problem2(test_input);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint64_t>(test_answer2, 195));

    // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
