
#include <iomanip>    // For setw and setprecision
#include <iostream>   // For cout
#include <stdexcept>  // For out_of_range exception

// Method definitions
template <typename T>
void BinaryTree<T>::setDepth(int depth) {
    _depth = depth;
    _tree.resize(_depth + 1);
    for (int i = 0; i <= _depth; ++i) {
        _tree[i].resize(i + 1);
    }
}

// Set the value of a specific node in the tree
template <typename T>
void BinaryTree<T>::setNode(int level, int index, T value) {
    if (level <= _depth && index <= level) {
        _tree[level][index] = value;
    }
}

// Get the value of a specific node in the tree
template <typename T>
T BinaryTree<T>::getNode(int level, int index) const {
    if (level <= _depth && index <= level) {
        return _tree[level][index];
    }
    throw std::out_of_range("Invalid node access in BinaryTree.");
}

// Initialize the binomial model
template <typename T>
void BinaryTree<T>::initializeBinomialModel(T initialPrice, T upFactor, T downFactor) {
    setDepth(_depth);
    _tree[0][0] = initialPrice;

    for (int level = 1; level <= _depth; ++level) {
        for (int i = 0; i <= level; ++i) {
            if (i == 0) {
                _tree[level][i] = _tree[level - 1][i] * upFactor;
            } else if (i == level) {
                _tree[level][i] = _tree[level - 1][i - 1] * downFactor;
            } else {
                _tree[level][i] = _tree[level - 1][i - 1] * downFactor;
            }
        }
    }
}

// Display the pyramid structure
template <typename T>
void BinaryTree<T>::displayPyramid() const {
    const int width = 7;       // Define the width of each cell for alignment
    const int slashWidth = 5;  // Width dedicated to each slash section

    for (int i = 0; i <= _depth; ++i) {
        // Print leading spaces to center the row of values, plus one extra space for alignment
        std::cout << " " << std::string((_depth - i) * width / 2, ' ');

        // Print values for the current level
        for (int j = 0; j <= i; ++j) {
            std::cout << std::setw(width) << std::fixed << std::setprecision(2) << _tree[i][j];
        }
        std::cout << std::endl;

        // Print connecting slashes for each level, except the last one
        if (i < _depth) {
            // Print leading spaces to center the slashes under the numbers, plus one extra space for alignment
            std::cout << " " << std::string((_depth - i - 1) * width / 2 + (width - slashWidth) / 2, ' ');

            // Print the /   \ pattern for each pair in the level
            for (int j = 0; j <= i; ++j) {
                std::cout << " /   \\ ";
                if (j < i) {
                    std::cout << std::string(width - slashWidth, ' ');  // Adjust space between pairs
                }
            }

            std::cout << std::endl;
        }
    }
}
