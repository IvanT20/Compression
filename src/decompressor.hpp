#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <string>
#include <utility>

class Decompressor
{

public:

    explicit Decompressor(std::string filePath)
        : filePath_(std::move(filePath)){}

    void decompress();

private:

    std::string filePath_{};
};

#endif