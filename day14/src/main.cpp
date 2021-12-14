// Advent of Code: Day 14
// Lento Manickathan
#include <algorithm>
#include <fmt/ranges.h>
#include <map>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

std::map<std::string, std::string> parse_rule(utils::Text<std::string>& input)
{
    std::map<std::string, std::string> rules;

    for (size_t i = 1; i < input.size(); i = i + 3)
        rules[input[i]] = input[i + 2][0];

    return rules;
}

#ifndef NDEBUG

static uint64_t problem_brute_force(utils::Text<std::string>& input)
{
    // Parse polymer
    std::string polymer = input[0];
    // Parse rules
    std::map<std::string, std::string> rules = parse_rule(input);

    // Number of steps
    size_t n_steps = 10;

    //fmt::print("Template      : {}\n", polymer);

    for (size_t k = 1; k < n_steps + 1; ++k)
    {
        std::string temp = polymer;

        for (size_t i = 0; i < polymer.size() - 1; i++)
            temp.insert(2 * i + 1, rules[polymer.substr(i, 2)]);
        polymer = temp;
        //fmt::print("After step {:2d} : {}\n", k, polymer);
    }

    // Get unique letters
    std::string polymer_unique = polymer;
    std::sort(polymer_unique.begin(), polymer_unique.end());
    auto last = std::unique(polymer_unique.begin(), polymer_unique.end());
    polymer_unique.erase(last, polymer_unique.end());

    // Count letters
    std::vector<size_t> counts;
    for (auto& c : polymer_unique)
        counts.push_back(std::count(polymer.begin(), polymer.end(), c));
    std::sort(counts.begin(), counts.end());

    // Answer
    uint64_t answer = counts.back() - counts.front();

    return answer;
}
#endif

static uint64_t problem(utils::Text<std::string>& input, const size_t& n_steps)
{
    // Parse polymer
    std::string polymer = input[0];

    // Parse rules
    std::map<std::string, std::string> rules = parse_rule(input);

    // Initialize bags from template polymer (bug, wrong way)
    std::map<std::string, size_t> bags;
    for (auto& [key, value] : rules)
    {
        for (size_t i=0; i<polymer.size()-1; i++)
            if (polymer.substr(i, 2) == key)
                bags[key]++;
    }

    // Polymerize n_step times
    for (size_t k = 1; k < n_steps + 1; ++k)
    {
        std::map<std::string, size_t> temp;
        // Polymerize
        for (auto& [key, value] : bags)
        {
            std::string keyL = key[0] + rules[key];
            std::string keyR = rules[key] + key[1];
            temp[keyL] += bags[key];
            temp[keyR] += bags[key];
        }
        bags = temp;
    }

    // Count letters
    std::map<char, size_t> counts;
    for (auto& [key, value] : bags)
        counts[key[0]] += value;
    counts[polymer.back()]++; // let's not forget the last one

    // Find min and max counts
    size_t min = std::numeric_limits<size_t>::max();
    size_t max = std::numeric_limits<size_t>::min();
    for (auto& [key, value] : counts)
    {
        min = std::min(min, value);
        max = std::max(max, value);
    }

    // Answer
    uint64_t answer = max-min;

    return answer;
}

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 14;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {:02d} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    //uint64_t test_answer1 = problem_brute_force(test_input);
    uint64_t test_answer1 = problem(test_input, 10);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint64_t>(test_answer1, 1588));

    uint64_t test_answer2 = problem(test_input, 40);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint64_t>(test_answer2, 2188189693529));

    // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem(input, 10));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem(input, 40));
}
