#include <iostream>
#include "parser.hpp"
#include "huffmanTree.hpp"
#include "compressor.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./compressor [file]";
        return 0;
    }

    Parser parser(argv[1]);
    parser.parse();
    HuffmanTree tree(parser.getCharFrequency());
    tree.createCoding();
    tree.printTree();
    Compressor compressor(argv[1], parser.getCharFrequency(), tree.getCodes());
    compressor.compress();
}