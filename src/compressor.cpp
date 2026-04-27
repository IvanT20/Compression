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
    std::array<std::string, 256> codes = tree.generateCodes();

    std::ofstream outputFile("compressed" + filePath_, std::ios::binary);
    outputFile.write(reinterpret_cast<const char*>(charFrequency.data()), sizeof(uint32_t) * charFrequency.size()); // Writing header information

    std::ifstream inputFile(filePath_);
    std::string buffer;
    char c;

    while (inputFile.get(c))
    {
        buffer += codes[static_cast<unsigned char>(c)];
    }

}