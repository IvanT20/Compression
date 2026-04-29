#include <iostream>
#include <string>
#include "compressor.hpp"
#include "decompressor.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./compressor [flags] [file]\n\n";
        std::cout << "flags:\n-d for file decompression\nno flags for file compression\n";
        return 0;
    }

    if (argc == 3)
    {
        if (std::string(argv[1]) == "-d")
        {
            Decompressor decompressor(argv[2]);
            decompressor.decompress();
        }
    }
    else
    {
        Compressor compressor(argv[1]);
        compressor.compress();
    }
}