// Advent of Code: Day 06
// Lento Manickathan
#include <chrono>
#include <fmt/ranges.h>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

#include "core.h"

static int64_t problem(std::string filename, const size_t& n_days)
{
    // Read file
    auto text = utils::Text<std::string>(filename);

    // Parse initial population
    auto initial_population = utils::split_numbers<uint64_t>(text[0], ',');

    // Initialize the lanternfish school
    auto lanternfish_school = Lanternfish_School(initial_population);

    // Run the simulation
    for (size_t i = 0; i < n_days; ++i)
        lanternfish_school.evolve();

    // Answer
    int64_t answer = lanternfish_school.population_size();

    return answer;
}

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 06;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    int64_t test_answer1 = problem("test_input.txt", 80);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint32_t>(test_answer1, 5934));

    int64_t test_answer2 = problem("test_input.txt", 256);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint64_t>(test_answer2, 26984457539));

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem("input.txt", 80));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem("input.txt", 256));
}
