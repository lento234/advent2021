// Advent of Code: Day 10
// Lento Manickathan
#include <chrono>
#include <fmt/ranges.h>
#include <list>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

// Depth-first search
static inline int32_t dfs(std::list<char>& nodes, char* c)
{
    if (*c == '\0')
        return 0;
    if (*c == '(' || *c == '[' || *c == '{' || *c == '<')
    {
        nodes.push_back(*c);
        return dfs(nodes, ++c);
    }
    else if (*c == ')' && nodes.back() != '(')
        return 3;
    else if (*c == ']' && nodes.back() != '[')
        return 57;
    else if (*c == '}' && nodes.back() != '{')
        return 1197;
    else if (*c == '>' && nodes.back() != '<')
        return 25137;
    else
    {
        nodes.pop_back();
        return dfs(nodes, ++c);
    }
    throw std::runtime_error("Oh no!");
}

static uint64_t problem1(utils::Text<std::string>& input)
{
    // Answer
    uint64_t answer = 0;
    for (auto& line : input)
    {
        std::list<char> nodes;
        answer += dfs(nodes, &line.front());
    }
    // std::string line = input[0];

    // std::vector<char> nodes;
    // fmt::print("{}\n", dfs(nodes, &line.front())); //, *line+1));

    return answer;
}

static uint64_t problem2(utils::Text<std::string>& input)
{
    // Answer
    uint64_t answer = 0;

    return answer;
}

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 10;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {:02d} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    uint64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint64_t>(test_answer1, 26397));

    uint64_t test_answer2 = problem2(test_input);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint64_t>(test_answer2, 288957));

    // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // // Problem 2
    // fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
