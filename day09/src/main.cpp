// Advent of Code: Day 09
// Lento Manickathan
#include <chrono>
#include <fmt/ranges.h>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

static inline bool stencil_min(const std::vector<std::string>& height, const size_t& i, const size_t& j)
{
    // clang-format off
    return (((height[i][j] - '0') < (height[i][j + 1] - '0')) 
         && ((height[i][j] - '0') < (height[i][j - 1] - '0'))
         && ((height[i][j] - '0') < (height[i + 1][j] - '0'))
         && ((height[i][j] - '0') < (height[i - 1][j] - '0')));
    // clang-format on
}

static uint32_t problem1(utils::Text<std::string>& input)
{
    std::vector<std::string> height(input.raw);

    // Pad height with extra row and column and buffer value
    char buffer = '9';
    size_t ncols = input[0].size();

    // Pad top and bottom
    height.insert(height.begin(), std::string(ncols, buffer));
    height.insert(height.end(), std::string(ncols, buffer));

    // Pad left and right
    for (auto& row : height)
    {
        row.insert(row.begin(), buffer);
        row.insert(row.end(), buffer);
    }

    // Answer (if min than 4 neighbours, then covert to int and add 1 to answer)
    uint32_t answer = 0;

    for (size_t i = 1; i < height.size() - 1; ++i)
        for (size_t j = 1; j < height[i].size() - 1; ++j)
            if (stencil_min(height, i, j))
                answer += height[i][j] - '0' + 1;

    return answer;
}

static uint32_t problem2(utils::Text<std::string>& input)
{
    // Answer
    uint32_t answer = 0;

    return answer;
}

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 9;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {:02d} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    uint32_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint32_t>(test_answer1, 15));

    uint32_t test_answer2 = problem2(test_input);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint32_t>(test_answer2, 1134));

    // Real input
    auto input = utils::Text<std::string>("input.txt");

    // // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // // Problem 2
    // fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
