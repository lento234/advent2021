// Advent of Code: Day 08
// Lento Manickathan
#include <algorithm>
#include <chrono>
#include <fmt/ranges.h>
#include <set>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

static uint8_t string_intersect_size(std::string a, std::string b)
{
    // Calculate string set difference
    std::string intersect;
    std::string set_a(a.begin(), a.end());
    std::string set_b(b.begin(), b.end());
    std::sort(set_a.begin(), set_a.end());
    std::sort(set_b.begin(), set_b.end());

    std::set_intersection(set_a.begin(), set_a.end(), set_b.begin(), set_b.end(), std::back_inserter(intersect));

    return intersect.size();
}

static uint64_t problem1(utils::Text<std::string>& input)
{
    // Answer
    uint64_t answer = 0;

    for (size_t i = 0; i < input.size(); i = i + 15)
    {
        for (size_t j = 0; j < 4; ++j)
        {
            size_t word_size = input[i + 11 + j].size();
            if (word_size == 2 || word_size == 3 || word_size == 4 || word_size == 7)
                answer++;
        }
    }
    return answer;
}

static uint64_t problem2(utils::Text<std::string>& input)
{
    // Sort only the first 10 words of each line for easy comparison
    // Such that:
    // Pos 0 = 1
    // 1 = 7
    // 2 = 4
    // 3 - 5 -> {2, 5, 3}
    // 6 - 8 -> {6, 9, 0}
    // 9 = 8
    for (size_t i = 0; i < input.size(); i = i + 15)
        // Sort based on word size
        std::sort(input.begin() + i, input.begin() + i + 10, [](std::string& a, std::string& b)
                  {
                      return a.size() < b.size();
                  });

    // // Print message
    // fmt::print("Print original sorted message:\n");
    // for (size_t i = 0; i < input.size(); ++i)
    // {
    //     size_t word_size = input[i].size();
    //     if (word_size == 1)
    //         fmt::print(" | ");
    //     else
    //         fmt::print("{} ", input[i]);

    //     if ((i + 1) % 15 == 0)
    //         fmt::print("\n");
    // }

    std::vector<std::uint8_t> decoded_input(input.size());

    for (size_t i = 0; i < input.size(); i = i + 15)
    {
        decoded_input[i] = 1;
        decoded_input[i + 1] = 7;
        decoded_input[i + 2] = 4;
        decoded_input[i + 9] = 8;

        // Decode Messages 2, 3, 5
        for (size_t j = 3; j < 6; ++j)
        {
            if (string_intersect_size(input[i], input[i + j]) == 2)
                decoded_input[i + j] = 3;
            else if (string_intersect_size(input[i + 2], input[i + j]) == 2)
                decoded_input[i + j] = 2;
            else
                decoded_input[i + j] = 5;
        }

        // Decode Messages 6, 9, 0
        for (size_t j = 6; j < 9; ++j)
        {
            if (string_intersect_size(input[i], input[i + j]) == 1)
                decoded_input[i + j] = 6;
            else if (string_intersect_size(input[i + 2], input[i + j]) == 4)
                decoded_input[i + j] = 9;
            else
                decoded_input[i + j] = 0;
        }
    }

    // Decode the four output value
    for (size_t i = 0; i < input.size(); i = i + 15)
        for (size_t j = 11; j < 15; ++j)
            for (size_t k = 0; k < 10; ++k)
                if (string_intersect_size(input[i + k], input[i + j]) == input[i + k].size())
                    decoded_input[i + j] = decoded_input[i + k];

    // // Print message
    // fmt::print("Decoded message:\n");
    // for (size_t i = 0; i < input.size(); ++i)
    // {
    //     size_t word_size = input[i].size();
    //     if (word_size == 1)
    //         fmt::print(" | ");
    //     else
    //         fmt::print("{} ", decoded_input[i]);

    //     if ((i + 1) % 15 == 0)
    //         fmt::print("\n");
    // }

    // Answer
    uint64_t answer = 0;

    for (size_t i = 0; i < input.size(); i = i + 15)
        answer += decoded_input[i + 11] * 1000 + decoded_input[i + 12] * 100 + decoded_input[i + 13] * 10 + decoded_input[i + 14];

    return answer;
}

int main()
{
    auto timeit = utils::Timer<std::chrono::milliseconds>();

    constexpr uint8_t day = 8;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    uint64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint64_t>(test_answer1, 26));

    uint64_t test_answer2 = problem2(test_input);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint64_t>(test_answer2, 61229));

    // // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
