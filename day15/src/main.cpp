// Advent of Code: Day 15
// Lento Manickathan
#include <fmt/ranges.h>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

#include "core.h"

static dtype_t problem1(utils::Text<std::string>& input)
{
    // Initilize grid
    const size_t n_rows = input.size();
    const size_t n_cols = input[0].size();
    std::vector<uint8_t> grid = parse_grid(input);

    // Make queue of position and cost
    auto cmp = [](const pair_t& a, const pair_t& b)
    {
        return a.second > b.second;
    };
    std::priority_queue<pair_t, std::vector<pair_t>, decltype(cmp)> queue(cmp);
    queue.push({0, 0}); // start risk not counted

    // Initialize cost map
    std::vector<dtype_t> cost_map(n_rows * n_cols, std::numeric_limits<dtype_t>::max());
    cost_map[0] = 0;

    // Dijkstra's Algorithm
    while (!queue.empty())
    {
        auto [k, cost] = queue.top();
        queue.pop();

        std::vector<size_t> neighbours = get_neighbours(k, n_rows, n_cols);

        for (auto& neighbour : neighbours)
        {
            dtype_t new_cost = cost + grid[neighbour];
            if (new_cost < cost_map[neighbour])
            {
                cost_map[neighbour] = new_cost;
                queue.push({neighbour, new_cost});
            }
        }
    }

    // Answer
    dtype_t answer = cost_map.back();

    return answer;
}

static dtype_t problem2(utils::Text<std::string>& input, const size_t& p)
{
    // Initilize grid
    const size_t n_rows = input.size();
    const size_t n_cols = input[0].size();
    std::vector<uint8_t> grid = parse_grid(input);

    // Make queue of position and cost
    auto cmp = [](const pair_t& a, const pair_t& b)
    {
        return a.second > b.second;
    };
    std::priority_queue<pair_t, std::vector<pair_t>, decltype(cmp)> queue(cmp);
    queue.push({0, 0}); // start risk not counted

    // Initialize cost map
    std::vector<dtype_t> cost_map(n_rows * p * n_cols * p, std::numeric_limits<dtype_t>::max());
    cost_map[0] = 0;

    while (!queue.empty())
    {
        auto [k, cost] = queue.top();
        queue.pop();

        std::vector<size_t> neighbours = get_neighbours(k, n_rows * p, n_cols * p);

        for (auto& neighbour : neighbours)
        {
            dtype_t new_cost = cost + get_grid_p_period(grid, neighbour, n_rows, n_cols, p);
            if (new_cost < cost_map[neighbour])
            {
                cost_map[neighbour] = new_cost;
                queue.push({neighbour, new_cost});
            }
        }
    }

    // Answer
    dtype_t answer = cost_map.back();

    return answer;
}

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 15;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {:02d} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    dtype_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<dtype_t>(test_answer1, 40));

    dtype_t test_answer2 = problem2(test_input, 5);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<dtype_t>(test_answer2, 315));

    // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem2(input, 5));
}
