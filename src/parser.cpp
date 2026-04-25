#include <fstream>
#include <cstddef>
#include "parser.hpp"

void Parser::parse()
{
    std::ifstream file(filePath_);

    if (file.is_open())
    {
        std::string line;

        while (std::getline(file, line))
        {
            for (std::size_t i = 0; i < line.size(); ++i)
            {
                ++charFrequency_[static_cast<int>(line[i])];
            }
        }
    }
}

const std::array<int, 256>& Parser::getCharFrequency() const
{
    return charFrequency_;
}