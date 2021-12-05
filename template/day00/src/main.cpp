// Advent of Code: Day 00
// Lento Manickathan
#include <chrono>
#include <fmt/ranges.h>
#include <string>
#include <vector>

#include <util.h>

static int64_t problem1(std::string filename)
{
    // Read file
    auto text = Text<std::string>(filename);

    // Answer
    int64_t answer = 0;

    return answer;
}

/*
static int64_t problem2(std::string filename)
{
    // Read file
    auto text = Text<std::string>(filename);

    // Answer
    int64_t answer = 0;

    return answer;
}
*/

int main()
{
    auto timeit = Timer();

    constexpr uint8_t day = 00;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    int64_t test_answer1 = problem1("test_input.txt");
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               pass_or_fail(test_answer1, 0));

    /*
    int64_t test_answer2 = problem2("test_input.txt");
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               pass_or_fail(test_answer2, 0));

    // // Problem 1
    int64_t answer1 = problem1("input.txt");
    fmt::print(">> Problem 1: answer = {}\n", answer1);

    // // Problem 2
    int64_t answer2 = problem2("input.txt");
    fmt::print(">> Problem 2: answer = {}\n", answer2);
    */  
}
