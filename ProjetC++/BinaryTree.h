#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>

template <typename T>
class BinaryTree {
public:
    BinaryTree() : _depth(0) {}

    void setDepth(int depth);
    void setNode(int level, int index, T value);
    T getNode(int level, int index) const;
    void initializeBinomialModel(T initialPrice, T upFactor, T downFactor);
    void displayPyramid() const;
    void display() const;

private:
    int _depth;
    std::vector<std::vector<T>> _tree;
};

#include "BinaryTree.cpp" // Inclure ici le fichier .cpp pour les templates

#endif // BINARYTREE_H
