#include <fstream>
#include "compressor.hpp"

void Compressor::compress()
{
    std::ifstream inputFile(filePath_);
    std::ofstream outputFile("compressed_" + filePath_, std::ios::binary);

    if (!inputFile.is_open() || !outputFile.is_open()) return;

    outputFile.write(reinterpret_cast<const char*>(charFrequency_.data()), charFrequency_.size() * sizeof(std::uint32_t));

}