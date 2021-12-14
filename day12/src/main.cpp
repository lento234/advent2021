// Advent of Code: Day 12
// Lento Manickathan

#include <chrono>
#include <fmt/ranges.h>
#include <map>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

#include "core.h"

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
    graph["start"]->find_all_paths_to("end", 1);

    // Answer
    uint64_t answer = graph["start"]->n_routes;

    return answer;
}

static uint64_t problem2(utils::Text<std::string>& input)
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
    graph["start"]->find_all_paths_to("end", 2);

    // Answer
    uint64_t answer = graph["start"]->n_routes;

    return answer;
}

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

    uint64_t test_answer2 = problem2(test_input);
    fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
               test_answer2,
               utils::pass_or_fail<uint64_t>(test_answer2, 36));

    // Real input
    auto input = utils::Text<std::string>("input.txt");

    // Problem 1
    fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // Problem 2
    fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
