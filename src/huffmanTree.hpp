#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <array>

class Node
{

public:

    explicit Node(int count, char character)   // For leaf nodes
        : count_(count), character_(character){}

    explicit Node(Node* left, Node* right, int count) // For internal nodes
        : left_(left), right_(right), count_(count){}

    bool isLeaf() const;

private:

    Node* left_ = nullptr;
    Node* right_ = nullptr;
    int count_{};
    char character_{};
};

class HuffmanTree
{

public:

    explicit HuffmanTree(const std::array<int, 256>& charFrequency);

private:

    Node* root = nullptr;
};

#endif