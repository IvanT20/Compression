#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <array>
#include <string>
#include <cstdint>

class Node
{

public:

    explicit Node(std::uint32_t count, char character)   // For leaf nodes
        : count_(count), character_(character){}

    explicit Node(Node* left, Node* right, std::uint32_t count) // For internal nodes
        : left_(left), right_(right), count_(count){}

    bool isLeaf() const;
    std::uint64_t getCount() const;
    char getChar() const;
    Node* left() const;
    Node* right() const;

private:

    Node* left_ = nullptr;
    Node* right_ = nullptr;
    std::uint32_t count_{};
    char character_{};
};

class HuffmanTree
{

public:

    explicit HuffmanTree(const std::array<std::uint32_t, 256>& charFrequency);
    std::array<std::string, 256> generateCodes();
    void printTree() const;

private:

    void generateCodesHelper(Node* node, std::string code);

    Node* root_ = nullptr;
};

#endif