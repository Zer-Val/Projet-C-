#include "BinaryTree.h"
#include <cmath>    // For pow function
#include <iostream> // For cout
#include <iomanip>  // For setw

// Implementation of the setDepth method
template <typename T>
void BinaryTree<T>::setDepth(int depth) {
    _depth = depth;
    _tree.resize(_depth + 1);
    for (int i = 0; i <= _depth; ++i) {
        _tree[i].resize(i + 1);
    }
}

// Implementation of the initializeBinomialModel method
template <typename T>
void BinaryTree<T>::initializeBinomialModel(T initialPrice, T upFactor, T downFactor) {
    setDepth(_depth); // Set the depth and initialize tree structure
    _tree[0][0] = initialPrice; // Set the initial price at the root node

    // Populate the tree using the binomial model
    for (int level = 1; level <= _depth; ++level) {
        for (int i = 0; i <= level; ++i) {
            if (i == 0) {
                // Up movement from the first node in the previous level
                _tree[level][i] = _tree[level - 1][i] * upFactor;
            } else if (i == level) {
                // Down movement from the last node in the previous level
                _tree[level][i] = _tree[level - 1][i - 1] * downFactor;
            } else {
                // General case: we can arrive at this node from an up or down movement
                _tree[level][i] = _tree[level - 1][i - 1] * downFactor;
            }
        }
    }
}

// Implementation of the displayPyramid method
template <typename T>
void BinaryTree<T>::displayPyramid() const {
    for (int i = 0; i <= _depth; ++i) {
        // Print leading spaces to center the row of values
        for (int space = 0; space < (_depth - i); ++space) {
            std::cout << "   "; // Three spaces for better alignment
        }

        // Print values for the current level
        for (int j = 0; j <= i; ++j) {
            std::cout << std::setw(5) << _tree[i][j]; // Print each value with a fixed width
            if (j < i) {
                std::cout << "      "; // Extra space between values
            }
        }
        std::cout << std::endl;

        // Print connecting slashes for each level, except the last one
        if (i < _depth) {
            for (int space = 0; space < (_depth - i - 1); ++space) {
                std::cout << "   "; // Leading spaces for centering
            }
            for (int j = 0; j <= i; ++j) {
                std::cout << "  /      \\"; // Slash pattern between nodes
                if (j < i) {
                    std::cout << "   "; // Space between each pair of slashes
                }
            }
            std::cout << std::endl;
        }
    }
}

// Implementation of the display method
template <typename T>
void BinaryTree<T>::display() const {
    for (int i = 0; i <= _depth; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << std::setw(5) << _tree[i][j];
            if (j < i) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

// Explicit instantiation of the template class for specific types, if needed
template class BinaryTree<int>;
template class BinaryTree<double>;
template class BinaryTree<float>;
