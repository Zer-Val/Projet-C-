#include <vector>
#include <iostream>

#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class BinaryTree {
public:
    BinaryTree() : _depth(0) {}

    void setDepth(int depth);
    void setNode(int level, int index, T value);
    T getNode(int level, int index) const;
    void display() const;

    // Declaration for initializeBinomialModel
    void initializeBinomialModel(T initialPrice, T upFactor, T downFactor);

    // Declaration for displayPyramid with the missing semicolon
    void displayPyramid() const;

private:
    int _depth;
    std::vector<std::vector<T>> _tree;
};

#include "BinaryTree.cpp" // Include the .cpp file for templates

#endif // BINARYTREE_H
