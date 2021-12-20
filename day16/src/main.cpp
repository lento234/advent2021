// Advent of Code: Day 16
// Lento Manickathan
#include <bitset>
#include <fmt/ranges.h>
#include <map>
#include <string>
#include <vector>

#include <utils/parser.h>
#include <utils/timer.h>

static inline std::string hex_to_bin(const char& c)
{
    uint8_t value = 0;
    if (c >= '0' && c <= '9')
        value = c - '0';
    else if (c >= 'A' && c <= 'F')
        value = c - 'A' + 10;

    return std::bitset<4>(value).to_string();
}

struct BITS
{
    std::string binary;
    std::string hex;

    uint8_t version;
    uint8_t type_id;
    bool is_literal = false;
    uint8_t length_type_id = 4;

    // std::string message;

    // if type == 4, number == literal
    // if type == 0, total length in bits of sub-packets contained by this packet
    // if type == 1, then `number of sub-packets`
    int64_t length = 0;

    std::vector<std::string> value;

    BITS(const std::string& hex)
      : hex(hex)
    {
        // Convert hex to binary
        for (auto& c : hex)
            binary += hex_to_bin(c);

        // Decode header: version and type
        version = std::bitset<3>(binary.substr(0, 3)).to_ulong();
        type_id = std::bitset<3>(binary.substr(3, 3)).to_ulong();

        if (type_id == 4)
            is_literal = true;
        else
        {
            length_type_id = std::bitset<3>(binary.substr(6, 1)).to_ulong();
            if (length_type_id == 0)
                length = std::bitset<std::numeric_limits<uint32_t>::digits>(binary.substr(7, 15)).to_ulong();
            else if (length_type_id == 1)
                length = std::bitset<std::numeric_limits<uint32_t>::digits>(binary.substr(7, 11)).to_ulong();
        }
    }

    void decode_message()
    {
        if (type_id == 4)
        {
            std::string message;
            size_t k = 1;
            do {
                k = k + 5; // k == 6
                message += binary.substr(k + 1, 4);
            } while (binary[k] - '0');

            //value.push_back(std::bitset<std::numeric_limits<uint32_t>::digits>(message).to_ulong());
            value.push_back(std::bitset<std::numeric_limits<uint32_t>::digits>(message).to_string());
        }
        else
        {
            if (length_type_id == 0)
            {
                std::string message;
                size_t k = 17;
                do {
                    k = k + 5; // k == 24
                    message += binary.substr(k + 1, 4);
                } while (binary[k] - '0');
                //value.push_back(std::bitset<std::numeric_limits<uint32_t>::digits>(message).to_ulong());
                value.push_back(message);
            }
        }
    }

    void print()
    {
        fmt::print("Packet info:\n");
        fmt::print("hex             : {}\n", hex);
        fmt::print("binary          : {}\n", binary);
        fmt::print("version         : {}\n", version);
        fmt::print("type            : {}\n", type_id);
        fmt::print("literal         : {}\n", is_literal);
        fmt::print("length type id  : {}\n", length_type_id);
        fmt::print("packet length   : {}\n", length);
        fmt::print("message         : {}\n", value);
    }
};

static int64_t problem1(utils::Text<std::string>& input)
{
    // Print input
    input.print();

    // // String (hex) to binar
    // std::string input_bin;
    // for (auto& c : input[0])
    //     input_bin.insert(input_bin.size(), hex_to_bin(c));
    // fmt::print("Binary: {}\n", input_bin);

    // std::map<std::string, uint32_t> decode;
    // decode["version"] = std::bitset<3>(input_bin.substr(0, 3)).to_ulong();
    // decode["type"] = std::bitset<3>(input_bin.substr(3, 3)).to_ulong();

    // // Decode literal
    // std::string message = "";
    // // If type == 4, the represents a literal value.
    // if (decode["type"] == 4)
    // {
    //     size_t k = 1;
    //     do {
    //         k = k + 5;
    //         message += input_bin.substr(k + 1, 4);
    //     } while (input_bin[k] - '0');
    // }
    // // After type ID bit, and (15-bit or 11-bit field)
    // // Sub-packets appear
    // decode["message"] = std::bitset<std::numeric_limits<uint32_t>::digits>(message).to_ulong();

    // 0,1,2 -> packet version
    // 3,4,5 -> type ID
    //

    // Decode bits
    BITS bits(input[0]);
    // bits.decode_message();
    bits.print();

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

    constexpr uint8_t day = 16;

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
