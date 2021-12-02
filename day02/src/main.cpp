// Advent of Code: Day 2
// Lento Manickathan
#include <chrono>
#include <fstream>
#include <vector>
#include <string>
#include <fmt/ranges.h>

#include <util.h>

static int32_t problem1(std::string filename)
{
    // Read file
    auto text = Text<std::string>(filename);

    uint8_t cmd;
    int32_t unit, horz = 0, vert = 0;

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
    int32_t answer = horz * vert;
    
    return answer;
}

// static uint32_t problem2(std::string filename)
// {
//     // Read file
//     auto text = Text<uint32_t>(filename);
    
//     // Answer
//     uint32_t answer = 0;

//     // Check sum
//     uint32_t prev_sum = -1, new_sum;
//     for (size_t i=1; i<text.size()-1; ++i)
//     {
//         new_sum = text[i-1] + text[i] + text[i+1];
//         if (new_sum > prev_sum)
//             answer++;
//         prev_sum = new_sum;
//     }

//     return answer;
// }

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    constexpr uint8_t day = 2;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    int32_t test_answer1 = problem1("test_input.txt");
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n", 
        test_answer1, pass_or_fail(test_answer1, 150));
    
    // uint32_t test_answer2 = problem2("test_input.txt");
    // fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n", 
    //     test_answer2, pass_or_fail(test_answer2, 5));
    
    // // Problem 1
    // uint32_t answer1 = problem1("input.txt");
    // fmt::print(">> Problem 1: answer = {}\n", answer1);

    // // Problem 2
    // uint32_t answer2 = problem2("input.txt");
    // fmt::print(">> Problem 2: answer = {}\n", answer2);
    
    // Summary
    auto end = std::chrono::high_resolution_clock::now();
    fmt::print("\n>> [Summary] Total elapsed = {} μs\n\n",
        std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    
}
