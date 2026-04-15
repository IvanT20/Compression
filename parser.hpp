#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <utility>

class Parser
{

public:

    explicit Parser(std::string filePath)
        : filePath_(std::move(filePath)){}

private:

    std::string filePath_;

};

#endif