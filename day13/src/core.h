#pragma once

#include <fmt/ranges.h>
#include <string>
#include <tuple>
#include <vector>

#include <utils/parser.h>

struct Origami
{
    using string_t = std::string;
    size_t x_max = 0, y_max = 0;
    size_t size = 0, n_dots = 0;

    std::tuple<std::vector<uint16_t>, std::vector<uint16_t>> coordinates;
    std::vector<string_t> grid;

    Origami() = default;

    Origami(utils::Text<std::string>& input)
    {
        auto& [x_coordinates, y_coordinates] = coordinates;
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
        auto& [x_coordinates, y_coordinates] = coordinates;
        for (size_t i = 0; i < size; i++)
        {
            if (y_coordinates[i] > y)
                y_coordinates[i] = 2 * y - y_coordinates[i];
        }
        y_max = y - 1;
    }

    void fold_left(uint16_t x)
    {
        auto& [x_coordinates, y_coordinates] = coordinates;
        for (size_t i = 0; i < size; i++)
        {
            if (x_coordinates[i] > x)
                x_coordinates[i] = 2 * x - x_coordinates[i];
        }
        x_max = x - 1;
    }

    void make_grid()
    {
        auto& [x_coordinates, y_coordinates] = coordinates;
        grid = std::vector<string_t>(y_max + 1, string_t(x_max + 1, ' '));
        for (size_t i = 0; i < size; ++i)
            grid[y_coordinates[i]][x_coordinates[i]] = '#';

        n_dots = 0;
        for (auto& line : grid)
            n_dots += std::count(line.begin(), line.end(), '#');
    }

    void print(const std::string& style = "grid")
    {
        auto& [x_coordinates, y_coordinates] = coordinates;
        if (style == "raw")
        {
            for (size_t i = 0; i < size; ++i)
                fmt::print("{} {}\n", x_coordinates[i], y_coordinates[i]);
            fmt::print("Origami: size = {}, x_max = {} y_max = {}\n\n", size, x_max, y_max);
        }
        else
        {
            make_grid();
            // Plot using fmt
            fmt::print("\n    {}\n\n", fmt::join(grid, "\n    "));
        }
    }
};
