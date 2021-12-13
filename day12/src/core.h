#pragma once

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

    std::map<value_t, std::shared_ptr<Node>> neighbours;
    static std::vector<nodelist_t> routes;

    Node() = default;

    Node(value_t name) : name(name)
    {
        if (std::isupper(name[0]))
            is_big_cave = true;
    }

    void add_neighbour(std::shared_ptr<Node> new_neighbour)
    {
        if (name != "end" && ((neighbours.find(new_neighbour->name) == neighbours.end()) && new_neighbour->name != "start"))
            neighbours[new_neighbour->name] = new_neighbour;
    }

    nodelist_t get_neighbour_names()
    {
        nodelist_t neighbour_name_list;
        for (auto& [node_name, neightbour_node] : this->neighbours)
            neighbour_name_list.push_back(neightbour_node->name);
        return neighbour_name_list;
    }

    void find_all_paths_to(const value_t& destination)
    {
        nodelist_t path = {name};

        for (auto& [next_node_name, next_node] : neighbours)
        {
            nodelist_t new_path = path;
            new_path.push_back(next_node_name);
            next_node->travel(new_path, destination);
        }
    }

    void travel(nodelist_t path, const value_t& destination)
    {
        for (auto& [next_node_name, next_node] : this->neighbours)
        {
            if (next_node_name == destination)
            {
                nodelist_t final_path(path);
                final_path.push_back(next_node_name);
                routes.push_back(final_path);
            }
            else if (!utils::is_inside<std::string>(path, next_node_name) || next_node->is_big_cave)
            {
                nodelist_t new_path = path;
                new_path.push_back(next_node_name);
                next_node->travel(new_path, destination);
            }
        }
    }
};

// Linker
std::vector<Node::nodelist_t> Node::routes;