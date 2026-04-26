#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <string>
#include <array>
#include <utility>
#include <cstdint>

class Compressor
{

public:

    Compressor(std::string filePath, const std::array<std::uint32_t, 256>& charFrequency, const std::array<std::string, 256>& codes)
        : filePath_(std::move(filePath)), charFrequency_(charFrequency), codes_(codes){}

    void compress();

private:

    std::string filePath_;
    std::array<std::uint32_t, 256> charFrequency_{};
    std::array<std::string, 256> codes_{};
};

#endif