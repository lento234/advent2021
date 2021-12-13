// Advent of Code: Day 13
// Lento Manickathan
#include <algorithm>
#include <fmt/ranges.h>
#include <string>
#include <tuple>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

struct Origami
{
    size_t x_max = 0, y_max = 0;
    size_t size = 0, n_dots = 0;

    std::vector<uint16_t> x_coordinates;
    std::vector<uint16_t> y_coordinates;
    std::vector<std::string> grid;

    Origami() = default;

    Origami(utils::Text<std::string>& input)
    {
        for (auto& line : input)
        {
            if (line[0] != 'f' && line[0] != 'a' && line[0] != 'y' && line[0] != 'x')
            {
                std::vector<uint16_t> xy_pair = utils::split_numbers<uint16_t>(line, ',');
                x_coordinates.push_back(xy_pair[0]);
                y_coordinates.push_back(xy_pair[1]);
            }
        }
        x_max = *std::max_element(x_coordinates.begin(), x_coordinates.end());
        y_max = *std::max_element(y_coordinates.begin(), y_coordinates.end());
        size = x_coordinates.size();
    }

    void fold_up(uint16_t y)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (y_coordinates[i] > y)
                y_coordinates[i] = 2 * y - y_coordinates[i];
        }
        y_max = y-1;
    }

    void fold_left(uint16_t x)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (x_coordinates[i] > x)
                x_coordinates[i] = 2 * x - x_coordinates[i];
        }
        x_max = x-1;
    }

    void make_grid()
    {
        grid = std::vector<std::string>(y_max + 1, std::string(x_max + 1, '.'));
        for (size_t i = 0; i < size; ++i)
            grid[y_coordinates[i]][x_coordinates[i]] = '#';

        n_dots = 0;
        for (auto& line : grid)
            n_dots += std::count(line.begin(), line.end(), '#');
    }

    void print(const std::string& style = "grid")
    {
        if (style == "raw")
        {
            for (size_t i = 0; i < size; ++i)
                fmt::print("{} {}\n", x_coordinates[i], y_coordinates[i]);
            fmt::print("Origami: size = {}, x_max = {} y_max = {}\n\n", size, x_max, y_max);
        }
        else
        {
            make_grid();
            fmt::print("{}\n", fmt::join(grid, "\n"));
            fmt::print("Origami: size = {}, x_max = {}, y_max = {}, number of # = {}\n\n", size, x_max, y_max, n_dots);
        }
    }
};

static int64_t problem1(utils::Text<std::string>& input)
{
    Origami origami(input);

    size_t initial_size = origami.size;

    for (size_t i = initial_size; i < initial_size+3; ++i)
    {
        auto& line = input[i];
        if (line[0] == 'y')
            origami.fold_up(std::stoi(line.substr(2)));
        else if (line[0] == 'x')
            origami.fold_left(std::stoi(line.substr(2)));
    }
    // origami.print(); // origami.make_grid() and print;
    origami.make_grid();

    // Answer
    int64_t answer = origami.n_dots;

    return answer;
}

static std::string problem2(utils::Text<std::string>& input)
{
    Origami origami(input);

    size_t initial_size = origami.size;

    for (size_t i = initial_size; i < input.size(); ++i)
    {
        auto& line = input[i];
        if (line[0] == 'y')
            origami.fold_up(std::stoi(line.substr(2)));
        else if (line[0] == 'x')
            origami.fold_left(std::stoi(line.substr(2)));
    }
    origami.print(); // origami.make_grid() and print;
    
    // Answer
    int64_t answer = origami.n_dots;

    return answer;
}

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 13;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {:02d} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    int64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint32_t>(test_answer1, 17));

    // int64_t test_answer2 = problem2(test_input);
    // fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
    //            test_answer2,
    //            utils::pass_or_fail<uint32_t>(test_answer2, 0));

    // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // // Problem 2
    // fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
