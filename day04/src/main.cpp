// Advent of Code: Day 04
// Lento Manickathan
#include <algorithm>
#include <chrono>
#include <fmt/ranges.h>
#include <sstream>
#include <string>
#include <vector>

#include <util.h>

struct Board
{
    const size_t n_rows = 5;
    const size_t n_cols = 5;

    std::vector<uint8_t> pieces;
    std::vector<bool> marked;

    Board(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end)
    {
        for (auto it = begin; it != end; ++it)
            pieces.push_back(std::stoi(*it));
        marked.resize(pieces.size(), false);
    }

    void mark(const uint8_t draw)
    {
        for (size_t i = 0; i < n_rows * n_cols; ++i)
            if (pieces[i] == draw)
                marked[i] = true;
    }

    bool bingo()
    {
        for (size_t i = 0; i < n_rows * n_cols; i += n_rows)
            if (marked[i] && marked[i + 1] && marked[i + 2] && marked[i + 3] && marked[i + 4])
                return true;
        for (size_t i = 0; i < n_cols; ++i)
            if (marked[i] && marked[i + n_cols] && marked[i + 2 * n_cols] && marked[i + 3 * n_cols] && marked[i + 4 * n_cols])
                return true;
        return false;
    }

    // Sum all non-marked pieces
    int64_t sum_non_bingo()
    {
        int64_t sum = 0;
        for (size_t i = 0; i < n_rows * n_cols; ++i)
        {
            if (!marked[i])
                sum += pieces[i];
        }
        return sum;
    }

    void print()
    {
        uint8_t i = 0;
        for (const auto& piece : pieces)
        {
            fmt::print("{} ", piece);
            if (++i % n_cols == 0)
                fmt::print("\n");
        }
        fmt::print("\n");
    }

    void print_marked()
    {
        uint8_t i = 0;
        for (const auto& m : marked)
        {
            fmt::print("{} ", m ? 'x' : '.');
            if (++i % n_cols == 0)
                fmt::print("\n");
        }
    }
};

static std::vector<uint8_t> parse_draws(std::string line)
{
    std::vector<uint8_t> draws;

    // Split line by comma
    std::istringstream line_stream(line);
    for (std::string draw; getline(line_stream, draw, ',');)
        draws.push_back(std::stoi(draw));

    return draws;
}

// return the bingo number and winning board
static std::pair<int64_t, Board> its_a_bingo(const std::vector<uint8_t>& draws, std::vector<Board>& boards)
{
    for (const auto& draw : draws)
    {
        for (auto& board : boards)
        {
            board.mark(draw);
            if (board.bingo())
                return {draw, board};
        }
    }
    return {-1, boards[0]};
}

inline bool check_if_not_inside(std::vector<size_t>& indices, size_t i)
{
    return std::find(indices.begin(), indices.end(), i) == indices.end();
}

// return the bingo number and winning board
static std::pair<int64_t, Board> its_a_final_bingo(const std::vector<uint8_t>& draws, std::vector<Board>& boards)
{
    std::vector<size_t> winner_boards_indices;
    std::vector<size_t> winner_draws;

    for (const auto& draw : draws)
    {
        for (size_t i = 0; i < boards.size(); ++i)
        {
            if (check_if_not_inside(winner_boards_indices, i))
            {
                boards[i].mark(draw);
                if (boards[i].bingo())
                {
                    winner_boards_indices.push_back(i);
                    winner_draws.push_back(draw);
                }
            }
        }
    }
    // return last winner index
    return {winner_draws.end()[-1], boards[winner_boards_indices.end()[-1]]};
}

static int64_t problem1(std::string filename)
{
    // Read file
    auto text = Text<std::string>(filename);

    // Store all draw numbers
    auto draws = parse_draws(text[0]);

    // Make boards
    std::vector<Board> boards;
    for (auto it = text.begin() + 1; it != text.end(); it = it + 25)
        boards.push_back(Board(it, it + 25));

    // Find bingo number and winning board
    auto [bingo, board] = its_a_bingo(draws, boards);

    // Sum up all non-bingo numbers
    int64_t sum_non_bingo = board.sum_non_bingo();

    // Answer
    int64_t answer = bingo * sum_non_bingo;

    return answer;
}

static int64_t problem2(std::string filename)
{
    // Read file
    auto text = Text<std::string>(filename);

    // Store all draw numbers
    auto draws = parse_draws(text[0]);

    // Make boards
    std::vector<Board> boards;
    for (auto it = text.begin() + 1; it != text.end(); it = it + 25)
        boards.push_back(Board(it, it + 25));

    // Find bingo number and winning board
    auto [bingo, board] = its_a_final_bingo(draws, boards);

    // Sum up all non-bingo numbers
    int64_t sum_non_bingo = board.sum_non_bingo();

    // Answer
    int64_t answer = bingo * sum_non_bingo;

    return answer;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    constexpr uint8_t day = 04;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    int64_t test_answer1 = problem1("test_input.txt");
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               pass_or_fail<uint16_t>(test_answer1, 4512));

    int64_t test_answer2 = problem2("test_input.txt");
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               pass_or_fail<uint16_t>(test_answer2, 1924));

    // Problem 1
    int64_t answer1 = problem1("input.txt");
    fmt::print(">> Problem 1: answer = {}\n", answer1);

    // Problem 2
    int64_t answer2 = problem2("input.txt");
    fmt::print(">> Problem 2: answer = {}\n", answer2);

    // Summary
    auto end = std::chrono::high_resolution_clock::now();
    fmt::print("\n>> [Summary] Total elapsed = {} μs\n\n",
               std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
}
