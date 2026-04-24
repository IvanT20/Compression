#include <queue>
#include <vector>
#include <cstddef>
#include <iostream>
#include <stack>
#include "huffmanTree.hpp"

struct Comparator
{
    bool operator()(const Node* a, const Node* b) const
    {
        return a->getCount() > b->getCount();
    }
};

bool Node::isLeaf() const
{
    return !left_ && !right_;
}

int Node::getCount() const
{
    return count_;
}

char Node::getChar() const
{
    return character_;
}

Node* Node::left() const
{
    return left_;
}

Node* Node::right() const
{
    return right_;
}

HuffmanTree::HuffmanTree(const std::array<int, 256>& charFrequency)
{
    std::priority_queue<Node*, std::vector<Node*>, Comparator> tree;

    for (std::size_t i = 0; i < charFrequency.size(); ++i)
    {
        if (charFrequency[i] != 0)
        {
            Node* node = new Node(charFrequency[i], static_cast<char>(i));
            tree.push(node);
        }
    }

    while (tree.size() > 1)
    {
        Node* parent = nullptr;
        Node* nodeOne = tree.top();
        tree.pop();
        Node* nodeTwo = tree.top();
        tree.pop();
        parent = new Node(nodeTwo, nodeOne, nodeOne->getCount() + nodeTwo->getCount());
        tree.push(parent);
    }

    if (!tree.empty())
    {
        root_ = tree.top();
    }
}

void HuffmanTree::printTree() const // For testing purposes
{
    std::stack<Node*> stack;
    stack.push(root_);

    while (!stack.empty())
    {
        Node* current = stack.top();
        stack.pop();

        if (!current->isLeaf())
        {
            stack.push(current->right());
            stack.push(current->left());
        }
        else
        {
            std::cout << current->getChar() << ": " << current->getCount() << '\n';;
        }
    }
}