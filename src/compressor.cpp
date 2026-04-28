#include <fstream>
#include <iostream>
#include "compressor.hpp"
#include "parser.hpp"
#include "huffmanTree.hpp"

void Compressor::compress()
{
    Parser parser(filePath_);
    parser.parse();
    const auto& charFrequency = parser.getCharFrequency();
    HuffmanTree tree(charFrequency);

    if (tree.empty()) return;

    std::array<std::string, 256> codes = tree.generateCodes();
    std::ofstream outputFile("compressed_" + filePath_, std::ios::binary | std::ios::out);

    if (!outputFile.is_open()) return;

    outputFile.write(reinterpret_cast<const char*>(charFrequency.data()), sizeof(uint32_t) * charFrequency.size()); // Writing header information

    std::ifstream inputFile(filePath_, std::ios::binary);

    if (!inputFile.is_open()) return;

    std::uint8_t byte = 0;
    std::uint8_t padding = 0;
    int bitCount = 0;
    char c;

    std::streampos paddingPos = outputFile.tellp();
    outputFile.write(reinterpret_cast<const char*>(&padding), sizeof(std::uint8_t)); // Placeholder for now since we don't know how much padding is needed

    while (inputFile.get(c))
    {
        const std::string& code = codes[static_cast<unsigned char>(c)];

        for (char bit : code)
        {
            byte <<= 1;

            if (bit == '1')
            {
                byte |= 1;
            }

            ++bitCount;

            if (bitCount == 8)
            {
                outputFile.write(reinterpret_cast<const char*>(&byte), sizeof(std::uint8_t));
                byte = 0;
                bitCount = 0;
            }
        }
    }

    if (bitCount > 0)   // Didn't fill full byte
    {
        padding = 8 - bitCount;
        byte <<= padding;
        outputFile.write(reinterpret_cast<const char*>(&byte), sizeof(std::uint8_t));
    }

    outputFile.clear();
    outputFile.seekp(paddingPos, std::ios::beg);
    outputFile.write(reinterpret_cast<const char*>(&padding), sizeof(std::uint8_t));
}