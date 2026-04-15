#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <array>
#include <utility>

class Parser
{

public:

    explicit Parser(std::string filePath)
        : filePath_(std::move(filePath)){}

    void parse();

private:

    std::string filePath_;
    std::array<int, 256> charFrequency_;
};

#endif