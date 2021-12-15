// Advent of Code: Day 15
// Lento Manickathan
#include <fmt/ranges.h>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

static std::vector<uint8_t> parse_grid(utils::Text<std::string>& input)
{
    size_t n_rows = input.size();
    size_t n_cols = input[0].size();
    std::vector<uint8_t> grid(n_rows * n_cols, 0);
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_cols; ++j)
            grid[i * n_cols + j] = input[i][j] - '0';

    return grid;
}

static uint64_t problem1(utils::Text<std::string>& input)
{
    // input.print();
    std::vector<uint8_t> grid = parse_grid(input);
    size_t n_rows = input.size();
    size_t n_cols = input[0].size();

    fmt::print("{}\n", grid);

    uint64_t sum = 0;
    for (size_t k = 0; k < grid.size(); ++k)
    {
        if (grid[k])
    }

    fmt::print("\n");

    // Answer
    uint64_t answer = 0;

    return answer;
}

// static int64_t problem2(utils::Text<std::string>& input)
// {
//     // Answer
//     int64_t answer = 0;

//     return answer;
// }

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 15;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {:02d} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    uint64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint64_t>(test_answer1, 40));

    // int64_t test_answer2 = problem2(test_input);
    // fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
    //            test_answer2,
    //            utils::pass_or_fail<uint32_t>(test_answer2, 0));

    // // Real input
    // auto input = utils::Text<std::string>("input.txt");

    // // Problem 1
    // fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // // Problem 2
    // fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
