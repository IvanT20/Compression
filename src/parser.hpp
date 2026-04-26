#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <array>
#include <cstdint>
#include <utility>

class Parser
{

public:

    explicit Parser(std::string filePath)
        : filePath_(std::move(filePath)){}

    void parse();
    const std::array<std::uint32_t, 256>& getCharFrequency() const;

private:

    std::string filePath_;
    std::array<std::uint32_t, 256> charFrequency_{};
};

#endif