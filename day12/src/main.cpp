// Advent of Code: Day 12
// Lento Manickathan
#include <algorithm>
#include <fmt/ranges.h>
#include <map>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

bool is_inside(const std::vector<std::string>& path, const std::string& name)
{
    return std::find(path.begin(), path.end(), name) != path.end();
}

struct Node
{
    using value_t = std::string;
    using nodelist_t = std::vector<value_t>;

    value_t name;
    bool is_big_cave = false;

    std::map<value_t, std::unique_ptr<Node>> neighbours;

    Node() = default;

    Node(value_t name) : name(name)
    {
        if (std::isupper(name[0]))
            is_big_cave = true;
    }

    void add_neighbour(std::unique_ptr<Node> node)
    {
        if (name != "end" && (neighbours.find(*node.name) == neighbours.end() && *node.name != "start"))
            neighbours[*node.name] = node;
    }

    nodelist_t get_neighbour_names()
    {
        nodelist_t neighbour_names;
        for (auto& [name, node] : neighbours)
            neighbour_names.push_back(name);
        return neighbour_names;
    }

    // void find_all_paths_to(std::vector<nodelist_t>& routes, const value_t& destination)
    // {
    //     // start the path from this node (`name`)
    //     nodelist_t path = {name};

    //     for (auto& [neighbour_name, neighbour_node] : neighbours)
    //         travel(routes, path, destination);
    // }

    /*
    void travel(std::vector<nodelist_t>& routes, nodelist_t path, const value_t& destination)
    {
        fmt::print("{}: {} -> {}, neighbours = {}\n", name, path, destination, get_neighbour_names());
        
        for (auto [neighbour_name, neighbour_node] : neighbours)
        {
            // if (neighbour_name == destination)
            // {
            //     // fmt::print("{}: {} -> {}, {}\n", name, path, destination);
            //     path.push_back(neighbour_name);
            //     routes.push_back(path);
            // }
            // if (!is_inside(path, neighbour_name) || neighbour_node.is_big_cave)
            // {
                path.push_back(neighbour_name);
                neighbour_node.travel(routes, path, destination);
            // }

        }
    }
    */
};

void travel(std::vector<Node::nodelist_t>& routes, Node::nodelist_t path, Node current_node, Node destination_node)
{
    fmt::print("{}: {} -> {}, neighbours = {}\n", current_node.name, path, destination_node.name, current_node.get_neighbour_names());

    for (auto [name, node] : current_node.neighbours)
    {
        if (name == destination_node.name)
        {
            path.push_back(name);
            routes.push_back(path);
        }
        else if (!is_inside(path, name) || node.is_big_cave)
        {
            path.push_back(name);
            travel(routes, path, node, destination_node);
        }
    }
}

static int64_t problem1(utils::Text<std::string>& input)
{
    input.print();

    // Store all nodes and paths as a graph
    std::map<std::string, Node> graph;
    for (auto& line : input)
    {
        // Split two nodes from the line string
        std::vector<std::string> inodes = utils::split_string(line, '-');
        // Make nodes
        for (auto& inode : inodes)
            if (graph.find(inode) == graph.end())
                graph[inode] = Node(inode);
        // Add neighbours to each other
        graph[inodes[0]].add_neighbour(graph[inodes[1]]); // node1 -> node2
        graph[inodes[1]].add_neighbour(graph[inodes[0]]); // node2 -> node1
    }
    // Debug
    fmt::print("Graph: size = {}\n\n", graph.size());
    for (auto& [name, node] : graph)
        fmt::print("{} : {}, big cave = {}\n", node.name, node.get_neighbour_names(), node.is_big_cave);
    fmt::print("\n");

    // Find all paths from start to end
    // std::vector<Node::nodelist_t> routes;
    // travel(routes, {graph["start"].name}, graph["start"], graph["end"]);

    // fmt::print("\n\nRoutes:\n");
    // fmt::print("{}\n", fmt::join(routes, "\n"));

    fmt::print("A: {}, neighbours = {}\n", graph["A"].name, graph["A"].get_neighbour_names());
    fmt::print("A: {}, neighbours = {}\n", graph["A"].name, graph["A"].get_neighbour_names())

    // Answer
    int64_t answer = 0;

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

    int64_t test_answer1 = problem1(test_input);
    fmt::print(">> [Test] Problem 1: answer = {} [{}]\n",
               test_answer1,
               utils::pass_or_fail<uint32_t>(test_answer1, 0));

    // int64_t test_answer2 = problem2(test_input);
    // fmt::print(">> [Test] Problem 2: answer = {} [{}]\n\n",
    //            test_answer2,
    //            utils::pass_or_fail<uint32_t>(test_answer2, 0));

    // // Real input
    // auto input = utils::Text<std::string>("input.txt");

    // // Problem 1
    // fmt::print(">> Problem 1: answer = {}\n", problem1(input));

    // // Problem 2
    // fmt::print(">> Problem 2: answer = {}\n", problem2(input));
}
