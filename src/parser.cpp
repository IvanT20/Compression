#include <fstream>
#include <cstddef>
#include "parser.hpp"

void Parser::parse()
{
    std::ifstream file(filePath_);

    if (file.is_open())
    {
        char c;

        while (file.get(c))
        {
            ++charFrequency_[static_cast<unsigned char>(c)];
        }
    }
}

const std::array<std::uint32_t, 256>& Parser::getCharFrequency() const
{
    return charFrequency_;
}