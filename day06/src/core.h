#pragma once

#include <fmt/core.h>
#include <string>
#include <vector>

struct Lanternfish_School
{
    using value_t = uint64_t;

    const uint8_t n_populations = 9;
    std::vector<value_t> population_density = std::vector<value_t>(n_populations, 0);

    size_t day = 0;
    size_t n_new_fishes = 0;

    Lanternfish_School() = default;

    Lanternfish_School(const std::vector<value_t>& initial_population)
    {
        for (auto& fish : initial_population)
            population_density[fish]++;
    }

    void evolve()
    {
        // It's a beautiful day at the lake.
        day++;

        // Let's multiply
        n_new_fishes = population_density[0];

        // Count down the clock.
        for (auto i = 0; i < n_populations - 1; ++i)
            population_density[i] = population_density[i + 1];
        population_density[6] += n_new_fishes;
        population_density[8] = n_new_fishes;
    }

    void print_density()
    {
        fmt::print("Lanternfish school [Day {:02d}]: Population density = {}\n", day, population_density);
    }

    void print_population()
    {
        std::vector<value_t> population;
        for (size_t i = 0; i < population_density.size(); ++i)
            population.resize(population.size() + population_density[i], i);
        fmt::print("Lanternfish school [Day {:02d}]: Population = {}\n", day, population);
    }

    size_t size() const
    {
        return population_density.size();
    }

    size_t population_size() const
    {
        value_t sum = 0;
        for (auto& fish : population_density)
            sum += fish;
        return sum;
    }
};