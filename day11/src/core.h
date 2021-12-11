#pragma once

#include <fmt/ranges.h>
#include <string>
#include <vector>

class Dumbopus
{
private:
    std::vector<std::vector<uint8_t>> grid;
    size_t nrows = 0, ncols = 0;
    size_t n_flashes = 0;

    void flash(size_t i, size_t j)
    {
        n_flashes++;
        grid[i][j] = 0;
        for (int8_t k = -1; k < 2; ++k)
            for (int8_t l = -1; l < 2; ++l)
                if (grid[i + k][j + l] != 0 && ++grid[i + k][j + l] > 9)
                    flash(i + k, j + l);
    }

public:
    Dumbopus(const std::vector<std::string>& input)
    {
        nrows = input.size();
        ncols = input[0].size();
        grid.resize(nrows + 2, std::vector<uint8_t>(ncols + 2, 0));

        for (size_t i = 0; i < nrows; ++i)
            for (size_t j = 0; j < ncols; ++j)
                grid[i + 1][j + 1] = input[i][j] - '0';
    }

    void evolve()
    {
        for (size_t i = 1; i < nrows + 1; ++i)
            for (size_t j = 1; j < ncols + 1; ++j)
                grid[i][j]++;

        n_flashes = 0;
        for (size_t i = 1; i < nrows + 1; ++i)
            for (size_t j = 1; j < ncols + 1; ++j)
                if (grid[i][j] > 9)
                    flash(i, j);
    }

    size_t count_flashes() const { return n_flashes; }

    void print()
    {
        for (size_t i = 1; i < nrows + 1; ++i)
        {
            for (size_t j = 1; j < ncols + 1; ++j)
                fmt::print("{:2} ", grid[i][j]);
            fmt::print("\n");
        }
        fmt::print("Number of flashes: {}\n\n", n_flashes);
    }
};