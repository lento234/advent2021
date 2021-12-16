// Advent of Code: Day 15
// Lento Manickathan
#include <fmt/ranges.h>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

using pair_t = std::pair<size_t, uint64_t>;

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

static uint64_t problem1(utils::Text<std::string>& input)
{
    // Initilize grid
    size_t n_rows = input.size();
    size_t n_cols = input[0].size();
    std::vector<uint8_t> grid = parse_grid(input);

    // fmt::print("Grid size: {}x{}\n", n_rows, n_cols);
    // input.print();
    // fmt::print("Grid size: {}\n", grid);

    // Make queue of position and cost
    std::unordered_map<size_t, uint64_t> cost_init = {{0, 0}};
    std::vector<uint64_t> cost_map(n_rows * n_cols, std::numeric_limits<uint64_t>::max());
    cost_map[0] = 0;
    std::priority_queue<pair_t, std::vector<pair_t>, std::greater<pair_t>> queue(cost_init.begin(), cost_init.end());


    while (!queue.empty())
    {
        auto [k, cost] = queue.top();
        queue.pop();

        std::vector<size_t> neighbours = get_neighbours(k, n_rows, n_cols);

        for (auto neighbour : neighbours)
        {
            uint64_t new_cost = cost + grid[neighbour];
            if (new_cost < cost_map[neighbour])
            {
                cost_map[neighbour] = new_cost;
                queue.push({neighbour, new_cost});
            }
        }
        // fmt::print("{}: cost = {}, neighbours = {}\n", k, cost_map[k], neighbours);
    }

    // Answer
    uint64_t answer = cost_map[n_rows * n_cols - 1];

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

    uint64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint64_t>(test_answer1, 40));

    // int64_t test_answer2 = problem2(test_input);
    // fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
    //            test_answer2,
    //            utils::pass_or_fail<uint32_t>(test_answer2, 0));

    // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // // Problem 2
    // fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
