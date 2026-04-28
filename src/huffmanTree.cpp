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

std::uint64_t Node::getCount() const
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

HuffmanTree::HuffmanTree(const std::array<std::uint32_t, 256>& charFrequency)
{
    std::priority_queue<Node*, std::vector<Node*>, Comparator> tree;

    for (std::size_t i = 0; i < charFrequency.size(); ++i)
    {
        if (charFrequency[i] != 0)
        {
            Node* node = new Node(charFrequency[i], static_cast<unsigned char>(i));
            tree.push(node);
        }
    }

    while (tree.size() > 1)
    {
        Node* nodeOne = tree.top();
        tree.pop();
        Node* nodeTwo = tree.top();
        tree.pop();
        Node* parent = new Node(nodeOne, nodeTwo, nodeOne->getCount() + nodeTwo->getCount());
        tree.push(parent);
    }

    if (!tree.empty())
    {
        root_ = tree.top();
    }
}

HuffmanTree::~HuffmanTree()
{
    if (!root_) return;

    std::stack<Node*> stack;
    stack.push(root_);

    while (!stack.empty())
    {
        Node* current = stack.top();
        stack.pop();

        if (current->left()) stack.push(current->left());
        if (current->right()) stack.push(current->right());

        delete current;
    }

    root_ = nullptr;
}

static void generateCodesHelper(Node* node, std::array<std::string, 256>& codes, std::string& code)
{
    if (!node) return;
    if (node->isLeaf())
    {
        codes[static_cast<unsigned char>(node->getChar())] = code;
        return;
    }

    code.push_back('0');
    generateCodesHelper(node->left(), codes, code);
    code.pop_back();

    code.push_back('1');
    generateCodesHelper(node->right(), codes, code);
    code.pop_back();
}

std::array<std::string, 256> HuffmanTree::generateCodes() const
{
    std::array<std::string, 256> codes{};
    std::string code = "";

    if (root_ && root_->isLeaf())
    {
        codes[static_cast<unsigned char>(root_->getChar())] = '0';
        return codes;
    }

    generateCodesHelper(root_, codes, code);
    return codes;
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

bool HuffmanTree::empty() const
{
    return !root_;
}