<div align="center">

# 🎅🎄 Advent of Code 2021 ☃️❄️
 

![](https://img.shields.io/badge/stars%20⭐-14-gold.svg)

![GitHub Workflow Status](https://img.shields.io/github/workflow/status/lento234/advent2021/CMake)
![Last commit](https://img.shields.io/github/last-commit/lento234/advent2021)
[![GitHub license](https://img.shields.io/github/license/lento234/advent2021?color=blue)](https://github.com/lento234/advent2021/blob/main/LICENSE)

</div>


## Description

- [Advent of code 2021](https://adventofcode.com/2021/)
- [Awesome Advent of Code](https://github.com/Bogdanp/awesome-advent-of-code)


Advent of Code is an Advent calendar of small programming puzzles for a variety of skill sets and skill levels that can be solved in any programming language you like. People use them as a speed contest, interview prep, company training, university coursework, practice problems, or to challenge each other. 

## Calendar

|          M           |          T           |          W           |          T           |          F           |              S              |          S           |
| :------------------: | :------------------: | :------------------: | :------------------: | :------------------: | :-------------------------: | :------------------: |
|                      |                      | [1](day01/README.md) | [2](day02/README.md) | [3](day03/README.md) |    [4](day04/README.md)     | [5](day05/README.md) |
| [6](day06/README.md) | [7](day07/README.md) |          8           |          9           |          10          |             11              |          12          |
|          13          |          14          |          15          |          16          |          17          |             18              |          19          |
|          20          |          21          |          22          |          23          |          24          | [🎁](https://bit.ly/3pnrWiY) |                      |

## Benchmark

Performance benchmarked on `AMD Ryzen 9 3900X (24) @ 4.0GHz`, `GCC 11.1.0`, and with flags `-O3 -march=native`. 


|            Day             | Problem                     | Runtime (μs) | Memory (kB) |
| :------------------------: | :-------------------------- | -----------: | ----------: |
| [`01`](day01/src/main.cpp) | **Sonar Sweep**             |          229 |         138 |
| [`02`](day02/src/main.cpp) | **Dive!**                   |          285 |         364 |
| [`03`](day03/src/main.cpp) | **Binary Diagnostic**       |          302 |         685 |
| [`04`](day04/src/main.cpp) | **Giant Squid**             |         1021 |         697 |
| [`05`](day05/src/main.cpp) | **Hydrothermal Venture**    |         3185 |       11096 |
| [`06`](day06/src/main.cpp) | **Lanternfish**             |           95 |         126 |
| [`07`](day07/src/main.cpp) | **The Treachery of Whales** |          427 |         137 |

## Build 

### Docker

Run directly from the docker image

    docker run --rm mrlento234/advent2021:latest

### From source

1. Build using `cmake` in the `build` directory:

        make build

2. Run all the days:

        make run

3. *Optional*: make and run a specific day `xx`:

        cd dayxx
        make build
        cd build && ./dayxx

#### Install dependencies

**Ubuntu**:
    
    apt install build-essential cmake libfmt-dev curl pandoc valgrind

**Arch Linux**:

    pacman -S base-devel cmake curl pandoc fmt

**MacOS**: 

    brew install cmake curl pandoc fmt
