#include <fstream>
#include <vector>
#include "parser.hpp"
#include "huffmanTree.hpp"
#include "decompressor.hpp"

static void decode(const HuffmanTree& tree, const std::vector<std::uint8_t>& data, std::uint8_t padding, std::ofstream& file)
{
    const Node* current = tree.root();

    for (std::size_t i = 0; i < data.size() - 1; ++i)
    {
        std::uint8_t byte = data[i];

        for (int j = 7; j >= 0; --j)
        {
            int bit = (byte >> j) & 1;

            if (bit == 1)
            {
                current = current->right();
            }
            else
            {
                current = current->left();
            }

            if (current->isLeaf())
            {
                file.put(current->getChar());
                current = tree.root();
            }
        }
    }

    if (padding)
    {
        std::uint8_t byte = data.back();

        for (int i = 7; i >= padding; --i)
        {
            int bit = (byte >> i) & 1;

            if (bit == 1)
            {
                current = current->right();
            }
            else
            {
                current = current->left();
            }

            if (current->isLeaf())
            {
                file.put(current->getChar());
                current = tree.root();
            }
        }
    }
}

void Decompressor::decompress()
{
    Parser parser(filePath_);
    parser.parseCompressed();
    HuffmanTree tree(parser.getCharFrequency());
    std::ofstream outputFile(filePath_, std::ios::binary);

    if (!outputFile.is_open()) throw std::runtime_error("Failed to create output file\n");

    decode(tree, parser.getData(), parser.getPadding(), outputFile);
}