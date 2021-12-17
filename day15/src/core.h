#pragma once

#include <vector>

#include <utils/parser.h>

using dtype_t = uint16_t;
using pair_t = std::pair<size_t, dtype_t>;

static std::vector<uint8_t> parse_grid(utils::Text<std::string>& input)
{
    size_t n_rows = input.size();
    size_t n_cols = input[0].size();

    // Initialize grid
    std::vector<uint8_t> grid(n_cols * n_rows, 0);
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_cols; ++j)
            grid[i * n_cols + j] = input[i][j] - '0';

    return grid;
}

static inline std::vector<size_t> get_neighbours(const size_t& k, const size_t& n_rows, const size_t& n_cols)
{
    std::vector<size_t> neighbours;
    size_t i = k / n_cols;
    size_t j = k % n_cols;

    if (i > 0)
        neighbours.push_back((i - 1) * n_cols + j);
    if (i < n_rows - 1)
        neighbours.push_back((i + 1) * n_cols + j);
    if (j > 0)
        neighbours.push_back(i * n_cols + j - 1);
    if (j < n_cols - 1)
        neighbours.push_back(i * n_cols + j + 1);

    return neighbours;
}

static inline uint64_t get_grid_p_period(
  std::vector<uint8_t>& grid, const size_t& neighbour, const size_t& n_rows, const size_t& n_cols, const size_t& p)
{
    size_t i = (neighbour / (n_cols * p)) % n_rows;
    size_t j = neighbour % n_cols;
    size_t p_i = neighbour / (n_rows * n_rows * p);
    size_t p_j = (neighbour % (n_cols * p)) / n_cols;

    uint64_t value = (grid[i * n_cols + j] + p_i + p_j) % 9;
    return value == 0 ? 9 : value;
}