#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <array>
#include <cstdint>
#include <utility>

class Parser
{

public:

    explicit Parser(std::string filePath)
        : filePath_(std::move(filePath)){}

    void parseUncompressed();
    void parseCompressed();
    const std::array<std::uint32_t, 256>& getCharFrequency() const;

private:

    std::string filePath_;
    std::array<std::uint32_t, 256> charFrequency_{};
    std::vector<std::uint8_t> data_{};
    std::uint8_t padding_{};
};

#endif