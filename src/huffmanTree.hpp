#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <array>
#include <string>
#include <cstdint>

class Node
{

public:

    explicit Node(std::uint32_t count, unsigned char character)   // For leaf nodes
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
    unsigned char character_{};
};

struct HuffmanCode
{
    std::uint64_t bits{};
    std::uint8_t length{};
};

class HuffmanTree
{

public:

    explicit HuffmanTree(const std::array<std::uint32_t, 256>& charFrequency);
    ~HuffmanTree();
    std::array<HuffmanCode, 256> generateCodes() const;
    void printTree() const;
    bool empty() const;
    const Node* root() const;

private:

    Node* root_ = nullptr;
};

#endif