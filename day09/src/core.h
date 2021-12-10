#pragma once

#include <string>
#include <vector>

static inline bool stencil_min(const std::vector<std::string>& height, const size_t& i, const size_t& j)
{
    // clang-format off
    return ((height[i][j] < height[i    ][j + 1]) 
         && (height[i][j] < height[i    ][j - 1])
         && (height[i][j] < height[i + 1][j    ])
         && (height[i][j] < height[i - 1][j    ]));
    // clang-format on
}

static inline uint16_t spread(const std::vector<std::string>& height,
                              std::vector<std::string>& visited,
                              const size_t& i,
                              const size_t& j)
{
    if ((height[i][j] == '9') || (visited[i][j] == '1'))
        return 0;
    else
    {
        visited[i][j] = '1';
        // clang-format off
        return 1 + spread(height, visited, i-1, j) 
                 + spread(height, visited, i+1, j) 
                 + spread(height, visited, i, j-1)
                 + spread(height, visited, i, j+1);
        // clang-format on
    }
}