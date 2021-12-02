// Advent of Code: Day 2
// Lento Manickathan
#include <chrono>
#include <fstream>
#include <vector>
#include <string>
#include <fmt/ranges.h>

#include <util.h>

static int64_t problem1(std::string filename)
{
    // Read file
    auto text = Text<std::string>(filename);

    uint8_t cmd;
    int64_t unit, horz=0, vert=0;

    for (size_t i=0; i<text.size()-1; i=i+2)
    {
        cmd = text[i][0];
        unit = std::stoi(text[i+1]);

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
    int64_t answer = horz * vert;
    
    return answer;
}


int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    constexpr uint8_t day = 2;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    int64_t test_answer1 = problem1("test_input.txt");
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n", 
        test_answer1, pass_or_fail(test_answer1, 150));
    
    // uint32_t test_answer2 = problem2("test_input.txt");
    // fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n", 
    //     test_answer2, pass_or_fail(test_answer2, 5));
    
    // // Problem 1
    int64_t answer1 = problem1("input.txt");
    fmt::print(">> Problem 1: answer = {}\n", answer1);

    // // Problem 2
    // uint32_t answer2 = problem2("input.txt");
    // fmt::print(">> Problem 2: answer = {}\n", answer2);
    
    // Summary
    auto end = std::chrono::high_resolution_clock::now();
    fmt::print("\n>> [Summary] Total elapsed = {} μs\n\n",
        std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    
}
