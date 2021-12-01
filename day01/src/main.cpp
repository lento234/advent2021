// Advent of Code: Day 2
// Lento Manickathan

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <fmt/ranges.h>

/*
static int problem1(std::string filename)
{
    // Read file
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("Failed to open!");

    int total_valid = 0;

    std::string range, letter, word;
    while (file >> range >> letter >> word)
    {
        // Inspect input
        //fmt::print("Range: {}, Letter: {}, Word: {}\n", range, letter, word);

        // Calculate min/max range
        int min = std::stoi(range);
        int max = std::stoi(range.substr(range.find('-')+1));
        //fmt::print("start: {}, end: {}\n", min, max);

        // Calculate number of items
        char token = letter[0];
        int count = 0;
        for (auto& s: word)
            if (s == token) count++;
        //fmt::print("counts: {}\n", count);
        
        if ( (count >= min) && (count <= max) )
            total_valid++;
    }
    file.close();

    return total_valid;
}

static int problem2(std::string filename)
{
    // Read file
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("Failed to open!");

    int total_valid = 0;

    std::string range, letter, word;
    while (file >> range >> letter >> word)
    {
        // Inspect input
        //fmt::print("Range: {}, Letter: {}, Word: {}\n", range, letter, word);

        // Calculate min/max range
        int min = std::stoi(range);
        int max = std::stoi(range.substr(range.find('-')+1));
        //fmt::print("start: {}, end: {}\n", min, max);

        // Calculate number of items
        char token = letter[0];
        bool is_valid = ((word[min-1] == token) ^ (word[max-1] == token)) ? true : false;
        //fmt::print("is_valid: {}\n", is_valid);
        
        if (is_valid)
            total_valid++;
    }
    file.close();

    return total_valid;
}
*/

int main()
{
    // Info
    const int day = 1;
    fmt::print("Advent of Code : Day {}\n", day);

    /*
    int test_answer = problem1("test_input.txt");
    fmt::print("Test answer 1: {}\n\n", test_answer);

    int answer1 = problem1("input.txt");
    fmt::print("Answer 1: {}\n\n", answer1);
    
    int answer2 = problem2("input.txt");
    fmt::print("Answer 2: {}\n\n", answer2);
    */
}
