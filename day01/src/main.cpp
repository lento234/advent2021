// Advent of Code: Day 1
// Lento Manickathan
#include <fstream>
#include <vector>
#include <string>
#include <fmt/ranges.h>

static uint32_t problem1(std::string filename)
{
    // Read file
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("Failed to open!");

    // Number of valid depths
    uint32_t n = 0;

    // Check number of increasing depths
    uint32_t old_depth = -1, new_depth;
    while (file >> new_depth)
    {
        if (new_depth > old_depth)
            n++;
        old_depth = new_depth;
    }
    
    return n;
}

int main()
{
    // Header info
    constexpr int day = 1;
    fmt::print("//////////////////////////////\n");
    fmt::print("    Advent of Code : Day {}   \n", day);
    fmt::print("//////////////////////////////\n\n");

    // Test input
    uint32_t test_answer1 = problem1("test_input.txt");
    fmt::print(">> Test answer 1: {}\n", test_answer1);
    fmt::print(">> Test 1: {}\n", (test_answer1 == 7) ? "PASSED" : "FAILED");

}
