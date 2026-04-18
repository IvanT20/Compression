#include <iostream>
#include "parser.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./compressor [file]";
        return 0;
    }

    Parser parser(argv[1]);
    parser.parse();
}