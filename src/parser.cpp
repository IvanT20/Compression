#include <fstream>
#include <cstddef>
#include <stdexcept>
#include <cstring>
#include "parser.hpp"

void Parser::parseUncompressed()
{
    std::ifstream file(filePath_, std::ios::binary);

    if (file.is_open())
    {
        char c;

        while (file.get(c))
        {
            ++charFrequency_[static_cast<unsigned char>(c)];
        }
    }
}

void Parser::parseCompressed()
{
    std::ifstream file(filePath_, std::ios::binary);

    if (file.is_open())
    {
        char buffer[1024]{};
        file.read(buffer, sizeof(buffer));

        if (!file) throw std::runtime_error("Failed to read frequency table\n");

        std::memcpy(charFrequency_.data(), buffer, charFrequency_.size() * sizeof(std::uint32_t));
        file.read(buffer, sizeof(std::uint8_t));
        std::memcpy(&padding_, buffer, sizeof(padding_));

        data_.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    }
}

const std::array<std::uint32_t, 256>& Parser::getCharFrequency() const
{
    return charFrequency_;
}