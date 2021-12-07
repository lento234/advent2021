#pragma once

#include <fmt/core.h>
#include <sstream>
#include <string>

#include <utils/parser.h>

struct Point
{
    using coor_t = uint16_t;

    coor_t x = 0, y = 0;

    Point() = default;

    Point(const std::string& line)
      : x(std::stoi(line.substr(0, line.find(",")))), y(std::stoi(line.substr(line.find(",") + 1)))
    {
    }

    Point(const coor_t& x, const coor_t& y)
      : x(x), y(y)
    {
    }

    void operator=(const Point& other)
    {
        x = other.x;
        y = other.y;
    }

    void print()
    {
        fmt::print("({}, {})\n", x, y);
    }

    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point& other) const
    {
        return !(*this == other);
    }

    bool operator<(const Point& other) const
    {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }

    bool operator>(const Point& other) const
    {
        if (x == other.x)
            return y > other.y;
        return x > other.x;
    }

    bool operator<=(const Point& other) const
    {
        return !(*this > other);
    }

    bool operator>=(const Point& other) const
    {
        return !(*this < other);
    }
};

struct Map
{
    using coor_t = uint16_t;

    bool has_diagonal = false;
    coor_t nx = 0, ny = 0;
    coor_t x_max = 0, y_max = 0;

    std::vector<Point> points_coo;
    std::vector<coor_t> points;

    Map() = default;

    Map(utils::Text<std::string>& text, bool has_diagonal = false)
      : has_diagonal(has_diagonal)
    {
        store_point(text); // Store all the points as coordinates
        fill();            // Fill the map with the points
    }

    void store_point(utils::Text<std::string>& text)
    {
        for (size_t i = 0; i < text.size(); i = i + 3)
        {
            auto p0 = Point(text[i]);
            auto p1 = Point(text[i + 2]);

            // Update max
            if (p0.x > x_max)
                x_max = p0.x;
            if (p1.x > x_max)
                x_max = p0.x;
            if (p0.y > y_max)
                y_max = p0.y;
            if (p1.x > x_max)
                y_max = p0.y;

            if (p0.x == p1.x)
            {
                auto inc = p0.y < p1.y ? 1 : -1;
                for (coor_t y = p0.y; y != p1.y + inc; y = y + inc)
                    points_coo.emplace_back(Point(p0.x, y));
            }
            if (p0.y == p1.y)
            {
                auto inc = p0.x < p1.x ? 1 : -1;
                for (coor_t x = p0.x; x != p1.x + inc; x = x + inc)
                    points_coo.emplace_back(Point(x, p0.y));
            }
            if (has_diagonal && (abs(p0.x - p1.x) == abs(p0.y - p1.y)))
            {
                auto inc_x = p0.x < p1.x ? 1 : -1;
                auto inc_y = p0.y < p1.y ? 1 : -1;
                for (coor_t x = p0.x, y = p0.y; x != p1.x + inc_x && y != p1.y + inc_y; x = x + inc_x, y = y + inc_y)
                    points_coo.emplace_back(Point(x, y));
            }
        }

        nx = x_max + 1;
        ny = y_max + 1;
    }

    void fill()
    {
        points.resize(nx * ny, 0);
        for (auto& p : points_coo)
            ++points[p.x + nx * p.y];
    }

    void draw()
    {
        for (coor_t y = 0; y < ny; y++)
        {
            for (coor_t x = 0; x < nx; x++)
            {
                if (points[x + ny * y] == 0)
                    fmt::print(".");
                else
                    fmt::print("{}", points[x + ny * y]);
            }
            fmt::print("\n");
        }
    }

    void raw_print()
    {
        fmt::print("Map contains {} points:\n", points_coo.size());
        for (auto& point : points_coo)
            point.print();
        fmt::print("Max point: ({}, {})\n", x_max, y_max);
    }
};