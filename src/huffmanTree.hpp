#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

class Node
{

public:

    explicit Node(Node* left, Node* right, int count, char character);
    bool isLeaf();

private:

    Node* left_ = nullptr;
    Node* right_ = nullptr;
    int count_{};
    char character_{};
};

#endif