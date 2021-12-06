#pragma once

#include <fmt/core.h>
#include <string>

struct Lanternfish_School
{
    using val_t = uint8_t;
    using vec_t = std::vector<val_t>;

    vec_t population;

    size_t day = 0;
    size_t n_new_fishes = 0;

    Lanternfish_School(const vec_t& initial_population)
      : population(initial_population)
    {
    }

    void next_day()
    {
        for (size_t i = 0; i < n_new_fishes; ++i)
            population.push_back(9);
        n_new_fishes = 0;

        #pragma omp parallel for reduction(+:n_new_fishes)
        for (auto& fish : population)
        {
            if (fish == 0)
                fish = 7;
            if (--fish == 0)
                n_new_fishes++;
        }
        day++;
    }

    void print()
    {
        fmt::print("Lanternfish school [Day {:02d}]: {}\n", day, population);
    }

    size_t size() const
    {
        return population.size();
    }
};