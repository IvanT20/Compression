#include "huffmanTree.hpp"

bool Node::isLeaf()
{
    return !left_ && !right_;
}