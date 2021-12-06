// Advent of Code: Day 03
// Lento Manickathan
#include <bitset>
#include <chrono>
#include <fmt/ranges.h>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

template <size_t N>
static std::string decode_text(utils::Text<std::string>& text)
{
    std::vector<size_t> counts(N, 0);

    for (auto line : text)
        for (size_t i = 0; i < N; ++i)
            counts[i] += line[i] - '0';

    std::string bits = "";
    for (size_t i = 0; i < N; ++i)
        bits += counts[i] >= (text.size() / 2) ? '1' : '0';

    return bits;
}

std::vector<std::string> radix_filter(std::vector<std::string> text, bool bit, size_t pos = 0)
{
    if (text.size() == 1)
        return text;

    std::vector<std::string> left, right;

    for (auto line : text)
    {
        if (line[pos] == '0')
            left.push_back(line);
        else
            right.push_back(line);
    }
    if (bit)
        return left.size() > right.size() ? radix_filter(left, bit, ++pos) : radix_filter(right, bit, ++pos);
    else
        return left.size() <= right.size() ? radix_filter(left, bit, ++pos) : radix_filter(right, bit, ++pos);
}

template <size_t N>
static int64_t problem1(std::string filename)
{
    // Read file
    auto text = utils::Text<std::string>(filename);

    // Decode text
    auto bits = decode_text<N>(text);

    auto gamma = std::bitset<N>(bits);          // Most common bits
    auto epsilon = std::bitset<N>(bits).flip(); // Least common bits

    // Answer
    int64_t answer = gamma.to_ulong() * epsilon.to_ulong();

    return answer;
}

template <size_t N>
static int64_t problem2(std::string filename)
{
    // Read file
    auto text = utils::Text<std::string>(filename);
    auto raw_text = text.raw;

    auto oxy = std::bitset<N>(radix_filter(raw_text, 1)[0]).to_ulong(); // sort by 1
    auto co2 = std::bitset<N>(radix_filter(raw_text, 0)[0]).to_ulong(); // sort by 0

    // Answer
    int64_t answer = oxy * co2;

    return answer;
}

int main()
{
    auto timer = utils::Timer();

    constexpr uint8_t day = 03;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    int64_t test_answer1 = problem1<5>("test_input.txt");
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint8_t>(test_answer1, 198));

    int64_t test_answer2 = problem2<5>("test_input.txt");
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint8_t>(test_answer2, 230));

    // // Problem 1
    int64_t answer1 = problem1<12>("input.txt");
    fmt::print(">> Problem 1: answer = {}\n", answer1);

    // Problem 2
    int64_t answer2 = problem2<12>("input.txt");
    fmt::print(">> Problem 2: answer = {}\n", answer2);

}
