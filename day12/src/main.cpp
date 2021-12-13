// Advent of Code: Day 12
// Lento Manickathan
#include <algorithm>
#include <fmt/ranges.h>
#include <map>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

#include "core.h"

// struct Node
// {
//     using value_t = std::string;
//     using nodelist_t = std::vector<value_t>;

//     value_t name;
//     bool is_big_cave = false;

//     nodelist_t neighbours;

//     Node() = default;

//     Node(value_t name) : name(name)
//     {
//         if (std::isupper(name[0]))
//             is_big_cave = true;
//     }

//     void add_neighbour(value_t neighbour_name)
//     {
//         if (name != "end" && (!utils::is_inside<value_t>(neighbours, neighbour_name) && neighbour_name != "start"))
//             neighbours.push_back(neighbour_name);
//     }
// };

// void travel(
//   std::map<std::string, Node>& graph,
//   std::vector<Node::nodelist_t>& routes,
//   Node::nodelist_t path,
//   const std::string& destination)
// {
//     std::string& location = path.back();

//     for (auto next_location : graph[location].neighbours)
//     {
//         if (next_location == destination)
//         {
//             std::vector<std::string> final_path = path;
//             final_path.push_back(next_location);
//             routes.push_back(final_path);
//         }
//         else if (!utils::is_inside<std::string>(path, next_location) || graph[next_location].is_big_cave)
//         {
//             std::vector<std::string> new_path = path;
//             new_path.push_back(next_location);
//             travel(graph, routes, new_path, destination);
//         }
//     }
// }

// static uint64_t problem1(utils::Text<std::string>& input)
// {
//     // Store all nodes and paths as a graph
//     std::map<std::string, Node> graph;
//     for (auto& line : input)
//     {
//         // Split two nodes from the line string
//         std::vector<std::string> node_pairs = utils::split_string(line, '-');

//         // Make nodes
//         for (auto& node : node_pairs)
//             if (graph.find(node) == graph.end())
//                 graph[node] = Node(node);

//         // Add neighbours to each other
//         graph[node_pairs[0]].add_neighbour(node_pairs[1]); // node1 -> node2
//         graph[node_pairs[1]].add_neighbour(node_pairs[0]); // node2 -> node1
//     }

//     // Find all paths from start to end
//     std::vector<Node::nodelist_t> routes;
//     std::vector<Node::value_t> path = {"start"};
//     travel(graph, routes, path, "end");

//     // Answer
//     int64_t answer = routes.size();

//     return answer;
// }

static uint64_t problem1(utils::Text<std::string>& input)
{
    // Store all nodes and paths as a graph
    std::map<std::string, std::shared_ptr<Node>> graph;
    for (auto& line : input)
    {
        // Split two nodes from the line string
        std::vector<std::string> node_pairs = utils::split_string(line, '-');

        // Make nodes
        for (auto& node : node_pairs)
            if (graph.find(node) == graph.end())
                graph[node] = std::make_shared<Node>(Node(node));

        // Add neighbours to each other
        graph[node_pairs[0]]->add_neighbour(graph[node_pairs[1]]); // node1 -> node2
        graph[node_pairs[1]]->add_neighbour(graph[node_pairs[0]]); // node2 -> node1
    }

    // Find all paths from start to end
    graph["start"]->find_all_paths_to("end");

    // Answer
    int64_t answer = graph["start"]->routes.size();

    return answer;
}

// static int64_t problem2(utils::Text<std::string>& input)
// {
//     // Answer
//     int64_t answer = 0;

//     return answer;
// }

int main()
{
    auto timeit = utils::Timer();

    constexpr uint8_t day = 12;

    // Header info
    fmt::print("\n🎄 Advent of Code: Day {:02d} 🎄\n", day);
    fmt::print("---------------------------\n\n");

    // Test input
    auto test_input = utils::Text<std::string>("test_input.txt");

    uint64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint64_t>(test_answer1, 10));

    // uint64_t test_answer2 = problem2(test_input);
    // fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
    //            test_answer2,
    //            utils::pass_or_fail<uint64_t>(test_answer2, 36));

    // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // // Problem 2
    // fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
