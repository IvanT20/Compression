#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <array>
#include <string>

class Node
{

public:

    explicit Node(int count, char character)   // For leaf nodes
        : count_(count), character_(character){}

    explicit Node(Node* left, Node* right, int count) // For internal nodes
        : left_(left), right_(right), count_(count){}

    bool isLeaf() const;
    int getCount() const;
    char getChar() const;
    Node* left() const;
    Node* right() const;

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
    void createCoding();
    void printTree() const;

private:

    void createCodingHelper(Node* node, std::string code);

    Node* root_ = nullptr;
    std::array<std::string, 256> codes_{};
};

#endif