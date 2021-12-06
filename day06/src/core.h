#pragma once

#include <fmt/core.h>
#include <omp.h>
#include <string>
#include <vector>

struct Lanternfish_School
{
    using val_t = uint8_t;

    std::vector<val_t>* population = new std::vector<val_t>();

    size_t day = 0;
    size_t n_new_fishes = 0;

    Lanternfish_School(const std::vector<val_t>& initial_population)
    {
        for (auto& fish : initial_population)
            population->emplace_back(fish);
    }

    void next_day()
    {
        // It's a beautiful day at the lake.
        day++;

        // Let's multiply.
        population->resize(population->size() + n_new_fishes, 9);

        // Count down the clock.
        n_new_fishes = 0;
#pragma omp parallel for reduction(+ \
                                   : n_new_fishes)
        for (auto& fish : *population)
        {
            if (fish == 0)
                fish = 6;
            else if (--fish == 0)
                n_new_fishes++;
        }
    }

    void print()
    {
        fmt::print("Lanternfish school [Day {:02d}]: {}\n", day, *population);
    }

    size_t size() const
    {
        return population->size();
    }
};