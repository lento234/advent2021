<div align="center">

# 🎅🎄 Advent of Code 2021 ☃️❄️
 

![](https://img.shields.io/badge/stars%20⭐-26-gold.svg)

![GitHub Workflow Status](https://img.shields.io/github/workflow/status/lento234/advent2021/CMake)
![Last commit](https://img.shields.io/github/last-commit/lento234/advent2021)
[![GitHub license](https://img.shields.io/github/license/lento234/advent2021?color=blue)](https://github.com/lento234/advent2021/blob/main/LICENSE)

</div>


## Description

- [Advent of code 2021](https://adventofcode.com/2021/)
- [Awesome Advent of Code](https://github.com/Bogdanp/awesome-advent-of-code)


Advent of Code is an Advent calendar of small programming puzzles for a variety of skill sets and skill levels that can be solved in any programming language you like. People use them as a speed contest, interview prep, company training, university coursework, practice problems, or to challenge each other. 

## Calendar

|           M           |          T           |          W           |          T           |           F           |              S              |           S           |
| :-------------------: | :------------------: | :------------------: | :------------------: | :-------------------: | :-------------------------: | :-------------------: |
|                       |                      | [1](day01/README.md) | [2](day02/README.md) | [3](day03/README.md)  |    [4](day04/README.md)     | [5](day05/README.md)  |
| [6](day06/README.md)  | [7](day07/README.md) | [8](day08/README.md) | [9](day09/README.md) | [10](day10/README.md) |    [11](day11/README.md)    | [12](day12/README.md) |
| [13](day13/README.md) |          14          |          15          |          16          |          17           |             18              |          19           |
|          20           |          21          |          22          |          23          |          24           | [🎁](https://bit.ly/3pnrWiY) |                       |

## Benchmark

Performance benchmarked on `AMD Ryzen 9 3900X (24) @ 4.0GHz`, `GCC 11.1.0`, and with flags `-O3 -march=native`. Memory usage profiled using `valgrind`.


|            Day             | Problem                     | Runtime |   Memory | Performance (Runtime) graph (`█ == 250 μs`) |
| :------------------------: | :-------------------------- | ------: | -------: | :------------------------------------------ |
| [`01`](day01/src/main.cpp) | **Sonar Sweep**             |  229 μs |   138 kB | `█`                                         |
| [`02`](day02/src/main.cpp) | **Dive!**                   |  285 μs |   364 kB | `█`                                         |
| [`03`](day03/src/main.cpp) | **Binary Diagnostic**       |  302 μs |   685 kB | `█`                                         |
| [`04`](day04/src/main.cpp) | **Giant Squid**             | 1021 μs |   697 kB | `████`                                      |
| [`05`](day05/src/main.cpp) | **Hydrothermal Venture**    | 3.19 ms | 10.85 MB | `█████████████`                             |
| [`06`](day06/src/main.cpp) | **Lanternfish**             |   95 μs |   126 kB | `█`                                         |
| [`07`](day07/src/main.cpp) | **The Treachery of Whales** |  177 μs |   137 kB | `█`                                         |
| [`08`](day08/src/main.cpp) | **Seven Segment Search**    | 1483 μs |   363 kB | `██████`                                    |
| [`09`](day09/src/main.cpp) | **Smoke Basin**             |  359 μs |   201 kB | `██`                                        |
| [`10`](day10/src/main.cpp) | **Syntax Scoring**          |  218 μs |   255 kB | `█`                                         |
| [`11`](day11/src/main.cpp) | **Dumbo Octopus**           |  590 μs |    93 kB | `██`                                        |
| [`12`](day12/src/main.cpp) | **Passage Pathing**         |  126 ms |   510 MB | `█████████████████████████████████████████` |
| [`13`](day13/src/main.cpp) | **Transparent Origami**     |  1.3 ms |   784 kB | `█████`                                     |


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
