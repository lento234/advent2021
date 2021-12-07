// Advent of Code: Day 07
// Lento Manickathan
#include <chrono>
#include <fmt/ranges.h>
#include <numeric>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

/*
static int64_t problem1_naive(utils::Text<std::string>& input)
{
    std::vector<int64_t> positions = utils::split_numbers<int64_t>(input[0], ',');

    int64_t least_cost = std::numeric_limits<int64_t>::max();
    for (auto& i_pos : positions)
    {
        int64_t cost = 0;
        for (auto& j_pos : positions)
            cost += std::abs(i_pos - j_pos);

        // Determine least cost
        least_cost = std::min(least_cost, cost);
    }

    // Answer
    int64_t answer = least_cost;

    return answer;
}
*/

// Best on median: https://en.wikipedia.org/wiki/Median#Optimality_property
static int64_t problem1(utils::Text<std::string>& input)
{
    std::vector<int64_t> positions = utils::split_numbers<int64_t>(input[0], ',');

    std::sort(positions.begin(), positions.end());
    int64_t best_pos = positions[positions.size() / 2]; // median

    // Answer
    int64_t answer = 0;
    for (auto& pos : positions)
        answer += std::abs(pos - best_pos);

    return answer;
}

// static int64_t problem2_naive(utils::Text<std::string>& input)
// {
//     std::vector<int64_t> positions = utils::split_numbers<int64_t>(input[0], ',');

//     int64_t least_cost = std::numeric_limits<int64_t>::max();
//     for (auto& i_pos : positions)
//     {
//         int64_t cost = 0;
//         for (auto& j_pos : positions)
//         {
//             int64_t i_cost = std::abs(i_pos - j_pos);
//             for (int64_t i = 1; i <= i_cost; ++i)
//                 cost += i;
//         }

//         // Determine least cost
//         least_cost = std::min(least_cost, cost);
//     }

//     // Answer
//     int64_t answer = least_cost;

//     return answer;
// }

// Source : https://www.reddit.com/r/adventofcode/comments/rar7ty/comment/hnk6gz0
static int64_t problem2(utils::Text<std::string>& input)
{
    std::vector<int64_t> positions = utils::split_numbers<int64_t>(input[0], ',');

    int64_t mean_pos = std::accumulate(positions.begin(), positions.end(), 0) / positions.size();

    // Answer
    int64_t l = 0, r = 0, d_l, d_r;
    for (auto& pos : positions)
    {
        d_l = std::abs(pos - mean_pos);
        d_r = std::abs(pos - mean_pos + 1);
        // https://en.wikipedia.org/wiki/Triangular_number
        l += d_l * (d_l + 1) / 2;
        r += d_r * (d_r + 1) / 2;
    }

    // Answer
    int64_t answer = std::min(l, r);

    return answer;
}

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 07;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    int64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<int64_t>(test_answer1, 37));

    int64_t test_answer2 = problem2(test_input);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<int64_t>(test_answer2, 170)); // typo in the original question?

    // Read input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
