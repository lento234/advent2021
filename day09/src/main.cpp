// Advent of Code: Day 09
// Lento Manickathan
#include <chrono>
#include <fmt/ranges.h>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

#include "core.h"

static uint32_t problem1(utils::Text<std::string>& input)
{
    std::vector<std::string> height = input.raw;

    // Pad height with extra row and column and buffer value
    size_t ncols = height[0].size();
    // Pad top and bottom
    height.insert(height.begin(), std::string(ncols, '9'));
    height.insert(height.end(), std::string(ncols, '9'));

    // Pad left and right
    for (auto& row : height)
    {
        row.insert(row.begin(), '9');
        row.insert(row.end(), '9');
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
    std::vector<std::string> height = input.raw;
    std::vector<std::string> visited(height.size(), std::string(height[0].size(), '0'));

    // Pad height with extra row and column and buffer value
    size_t ncols = height[0].size();

    // Pad top and bottom
    height.insert(height.begin(), std::string(ncols, '9'));
    height.insert(height.end(), std::string(ncols, '9'));
    visited.insert(visited.begin(), std::string(ncols, '1'));
    visited.insert(visited.end(), std::string(ncols, '1'));

    // Pad left and right
    for (size_t i = 0; i < height.size(); ++i)
    {
        height[i].insert(height[i].begin(), '9');
        height[i].insert(height[i].end(), '9');
        visited[i].insert(visited[i].begin(), '1');
        visited[i].insert(visited[i].end(), '1');
    }

    // Perform watershed and accumulated visited cells
    // https://en.wikipedia.org/wiki/Watershed_(image_processing)
    // Using breadth-first-search (BFS) or Meyer's flooding algorithm
    std::vector<uint16_t> size;
    for (size_t i = 1; i < visited.size() - 1; ++i)
        for (size_t j = 1; j < visited[i].size() - 1; ++j)
            if (stencil_min(height, i, j))
                size.push_back(spread(height, visited, i, j));
    std::sort(size.begin(), size.end(), std::greater<uint16_t>()); // sort size reversed

    // Answer
    uint32_t answer = size[0] * size[1] * size[2];

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

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
