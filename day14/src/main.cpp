// Advent of Code: Day 14
// Lento Manickathan
#include <fmt/ranges.h>
#include <map>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

std::map<std::string, std::string> parse_rule(utils::Text<std::string>& input)
{
    std::map<std::string, std::string> rules;

    for (size_t i = 1; i < input.size() - 2; i = i + 3)
        rules[input[i]] = input[i + 2][0];

    return rules;
}

static int64_t problem1(utils::Text<std::string>& input)
{

    // Parse polymer
    std::string polymer = input[0];
    // Parse rules
    std::map<std::string, std::string> rules = parse_rule(input);

    // Number of steps
    size_t n_steps = 4;

    fmt::print("Template      : {}\n", polymer);

    for (size_t k = 1; k < n_steps+1; ++k)
    {
        std::string temp = polymer;

        for (size_t i = 0; i < polymer.size() - 1; i++)
            temp.insert(2 * i + 1, rules[polymer.substr(i, 2)]);
        polymer = temp;

        fmt::print("After step {:2d} : {}\n", k, polymer);
    }

    // Answer
    int64_t answer = 0;

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

    constexpr uint8_t day = 14;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {:02d} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    int64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint32_t>(test_answer1, 1588));

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
