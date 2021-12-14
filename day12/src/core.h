#pragma once

#include <algorithm>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <utils/parser.h>

struct Node
{
    using value_t = std::string;
    using nodelist_t = std::vector<value_t>;

    value_t name;
    bool is_big_cave = false;
    size_t n_neighbours = 0;

    std::map<value_t, std::shared_ptr<Node>> neighbours;
    static size_t n_routes;

    Node() = default;

    Node(value_t name) : name(name)
    {
        if (std::isupper(name[0]))
            is_big_cave = true;
    }

    void add_neighbour(std::shared_ptr<Node> new_neighbour)
    {
        if (name != "end" && ((neighbours.find(new_neighbour->name) == neighbours.end()) && new_neighbour->name != "start"))
        {
            neighbours[new_neighbour->name] = new_neighbour;
            n_neighbours++;
        }
    }

    nodelist_t get_neighbour_names()
    {
        nodelist_t neighbour_name_list;
        for (auto& [node_name, neightbour_node] : this->neighbours)
            neighbour_name_list.push_back(neightbour_node->name);
        return neighbour_name_list;
    }

    void find_all_paths_to(const value_t& destination, int8_t max_revisits = 1)
    {
        n_routes = 0;
        for (auto& [next_node_name, next_node] : neighbours)
            next_node->travel({next_node_name}, destination, max_revisits);
    }

    void travel(nodelist_t path, const value_t& destination, int8_t max_revisits)
    {
        for (auto& [next_node_name, next_node] : this->neighbours)
        {
            if (next_node_name == destination)
                n_routes++;
            else if (next_node->is_big_cave)
                next_node->travel(path, destination, max_revisits);
            else if (std::count(path.begin(), path.end(), next_node_name) < max_revisits) // number of times we can visit a small case
            {
                // We can visit this cave
                nodelist_t new_path = path;
                new_path.push_back(next_node_name);

                if (std::count(path.begin(), path.end(), next_node_name))
                    next_node->travel(new_path, destination, max_revisits-1);
                else
                    next_node->travel(new_path, destination, max_revisits);          
            }
        }
    }
};

// Linker
size_t Node::n_routes = 0;