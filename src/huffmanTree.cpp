#include "huffmanTree.hpp"

bool Node::isLeaf() const
{
    return !left_ && !right_;
}

explicit HuffmanTree::HuffmanTree(const std::array<int, 256>& charFrequency)
{
    
}