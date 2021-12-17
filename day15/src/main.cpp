// Advent of Code: Day 15
// Lento Manickathan
#include <fmt/ranges.h>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

using dtype_t = uint64_t;
using pair_t = std::pair<size_t, dtype_t>;

static std::vector<uint8_t> parse_grid(utils::Text<std::string>& input)
{
    size_t n_rows = input.size();
    size_t n_cols = input[0].size();

    // Initialize grid
    std::vector<uint8_t> grid(n_cols * n_rows, 0);
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_cols; ++j)
            grid[i * n_cols + j] = input[i][j] - '0';

    return grid;
}

static inline std::vector<size_t> get_neighbours(size_t k, size_t n_rows, size_t n_cols)
{
    std::vector<size_t> neighbours;
    size_t i = k / n_cols;
    size_t j = k % n_cols;

    if (i > 0)
        neighbours.push_back((i - 1) * n_cols + j);
    if (i < n_rows - 1)
        neighbours.push_back((i + 1) * n_cols + j);
    if (j > 0)
        neighbours.push_back(i * n_cols + j - 1);
    if (j < n_cols - 1)
        neighbours.push_back(i * n_cols + j + 1);

    return neighbours;
}

static uint64_t get_grid_p_period(std::vector<uint8_t>& grid, size_t neighbour, size_t n_rows, size_t n_cols, size_t p)
{
    size_t i = (neighbour / (n_cols * p)) % n_rows;
    size_t j = neighbour % n_cols;
    size_t p_i = neighbour / (n_rows * n_rows * p);
    size_t p_j = (neighbour % (n_cols * p)) / n_cols;

    uint64_t value = (grid[i * n_cols + j] + p_i + p_j) % 9;
    return value == 0 ? 9 : value;
}

static dtype_t problem1(utils::Text<std::string>& input)
{
    // Initilize grid
    size_t n_rows = input.size();
    size_t n_cols = input[0].size();
    std::vector<uint8_t> grid = parse_grid(input);

    // Make queue of position and cost
    auto cmp = [](const pair_t& a, const pair_t& b) {
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

        for (auto neighbour : neighbours)
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

static dtype_t problem2(utils::Text<std::string>& input)
{
    // Period repeats
    size_t p = 5;

    // Initilize grid
    size_t n_rows = input.size();
    size_t n_cols = input[0].size();
    std::vector<uint8_t> grid = parse_grid(input);

    // Make queue of position and cost
    auto cmp = [](const pair_t& a, const pair_t& b) {
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

        for (auto neighbour : neighbours)
        {
            // dtype_t new_cost = cost + grid[neighbour];
            dtype_t new_cost = cost + get_grid_p_period(grid, neighbour, n_rows, n_cols, p);
            if (new_cost < cost_map[neighbour])
            {
                cost_map[neighbour] = new_cost;
                queue.push({neighbour, new_cost});
            }
        }
        // fmt::print("{}: cost = {}, neighbours = {}\n", k, cost_map[k], neighbours);
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

    dtype_t test_answer2 = problem2(test_input);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<dtype_t>(test_answer2, 315));

    // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
