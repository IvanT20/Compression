#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <string>
#include <utility>

class Compressor
{

public:

    explicit Compressor(std::string filePath)
        : filePath_(std::move(filePath)){}

    void compress();

private:

    std::string filePath_{};
};

#endif