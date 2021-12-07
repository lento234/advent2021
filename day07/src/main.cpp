// Advent of Code: Day 07
// Lento Manickathan
#include <chrono>
#include <fmt/ranges.h>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

static int64_t problem1(utils::Text<std::string>& input)
{
    std::vector<uint16_t> positions = utils::split_numbers<uint16_t>(input[0], ',');

    uint64_t least_cost = std::numeric_limits<uint64_t>::max();
    for (auto& i_pos : positions)
    {
        uint64_t cost = 0;
        for (auto& j_pos : positions)
            cost += std::abs(i_pos - j_pos);

        // Determine least cost
        least_cost = std::min(least_cost, cost);
    }

    // Answer
    int64_t answer = least_cost;

    return answer;
}

static int64_t problem2(utils::Text<std::string>& input)
{
    std::vector<uint16_t> positions = utils::split_numbers<uint16_t>(input[0], ',');

    uint64_t least_cost = std::numeric_limits<uint64_t>::max();
    for (auto& i_pos : positions)
    {
        uint64_t cost = 0;
        for (auto& j_pos : positions)
        {
            uint64_t i_cost = std::abs(i_pos - j_pos);
            for (uint64_t i = 1; i <= i_cost; ++i)
                cost += i;
        }
        // Determine least cost
        least_cost = std::min(least_cost, cost);
    }

    // Answer
    int64_t answer = least_cost;

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
               utils::pass_or_fail<uint32_t>(test_answer1, 37));

    int64_t test_answer2 = problem2(test_input);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint32_t>(test_answer2, 170)); // typo in the original question?

    // Read input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
