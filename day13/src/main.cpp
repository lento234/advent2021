// Advent of Code: Day 13
// Lento Manickathan
#include <algorithm>
#include <fmt/ranges.h>
#include <string>
#include <tuple>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

#include "core.h"

static int64_t problem1(utils::Text<std::string>& input)
{
    Origami origami(input);

    size_t initial_size = origami.size;

    for (size_t i = initial_size; i < initial_size + 3; ++i)
    {
        auto& line = input[i];
        if (line[0] == 'y')
            origami.fold_up(std::stoi(line.substr(2)));
        else if (line[0] == 'x')
            origami.fold_left(std::stoi(line.substr(2)));
    }
    // origami.print(); // origami.make_grid() and print;
    origami.make_grid();

    // Answer
    int64_t answer = origami.n_dots;

    return answer;
}

static void problem2(utils::Text<std::string>& input)
{
    Origami origami(input);

    size_t initial_size = origami.size;

    for (size_t i = initial_size; i < input.size(); ++i)
    {
        auto& line = input[i];
        if (line[0] == 'y')
            origami.fold_up(std::stoi(line.substr(2)));
        else if (line[0] == 'x')
            origami.fold_left(std::stoi(line.substr(2)));
    }
    origami.print(); // origami.make_grid() and print;
}

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 13;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {:02d} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    int64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint32_t>(test_answer1, 17));

    fmt::print(">> [Test] Problem 2: answer = \n");
    problem2(test_input);

    // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // Problem 2
    fmt::print(">> Problem 2: answer = \n");
    problem2(input);
}
