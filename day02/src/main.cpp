// Advent of Code: Day 2
// Lento Manickathan
#include <chrono>
#include <fmt/ranges.h>
#include <fstream>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

static int64_t problem1(std::string filename)
{
    // Read file
    auto text = utils::Text<std::string>(filename);

    uint8_t cmd;
    int64_t unit, horz = 0, vert = 0;

    for (size_t i = 0; i < text.size() - 1; i = i + 2)
    {
        cmd = text[i][0];
        unit = std::stoi(text[i + 1]);

        // Accumulate
        if (cmd == 'f')
            horz += unit;
        else if (cmd == 'b')
            horz -= unit;
        else if (cmd == 'd')
            vert += unit;
        else
            vert -= unit;
    }

    // Answer
    return horz * vert;
}

static int64_t problem2(std::string filename)
{
    // Read file
    auto text = utils::Text<std::string>(filename);

    uint8_t cmd;
    int64_t unit, horz = 0, vert = 0, aim = 0;

    for (size_t i = 0; i < text.size() - 1; i = i + 2)
    {
        cmd = text[i][0];
        unit = std::stoi(text[i + 1]);

        // Accumulate
        if (cmd == 'f')
        {
            horz += unit;
            vert += unit * aim;
        }
        else if (cmd == 'b')
        {
            horz -= unit;
            vert -= unit * aim;
        }
        else if (cmd == 'd')
            aim += unit;
        else
            aim -= unit;
    }

    // Answer
    return horz * vert;
}

int main()
{
    auto timer = utils::Timer();

    constexpr uint8_t day = 2;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    int64_t test_answer1 = problem1("test_input.txt");
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint16_t>(test_answer1, 150));

    int32_t test_answer2 = problem2("test_input.txt");
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint16_t>(test_answer2, 900));

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1("input.txt"));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem2("input.txt"));

}
