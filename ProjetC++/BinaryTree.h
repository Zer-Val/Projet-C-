#include <vector>
#include <iostream>
#include <iomanip>  // For setw

template <typename T>
class BinaryTree 
{
    public:
        BinaryTree() : _depth(0) {}

        void setDepth(int depth);
        void setNode(int level, int index, T value);
        T getNode(int level, int index) const;
        void display() const;

        // Declaration for initializeBinomialModel BONUS
        void initializeBinomialModel(T initialPrice, T upFactor, T downFactor);

    private:
        int _depth;
        std::vector<std::vector<T>> _tree;
};

template <typename T>
void BinaryTree<T>::setDepth(int depth) 
{
	_depth = depth + 1; // Add one to the depth to account for the root node
    _tree.resize(_depth);
    for (int i = 0; i < _depth; ++i) 
    {
        _tree[i].resize(i + 1);
    }
}

template <typename T>
void BinaryTree<T>::setNode(int level, int index, T value) 
{
    if (level < _depth && index <= level) 
    {
        _tree[level][index] = value;
    }
}

template <typename T>
T BinaryTree<T>::getNode(int level, int index) const 
{
    if (level < _depth && index <= level) 
    {
        return _tree[level][index];
    }
    throw std::out_of_range("Invalid indices");
}

template <typename T>
void BinaryTree<T>::display() const 
{

    if (_depth == 0) return;
    else 
    {

        for (int i = 0; i < _depth && i < _tree.size(); ++i) 
        {
            for (int j = 0; j <= i && j < _tree[i].size(); ++j) 
            {
                std::cout << _tree[i][j] << " ";
            }
            std::cout << std::endl;
        }
        for (int e = 0; e < 2; e++) 
        {
            std::cout << std::endl;
        }
        for (int i = 0; i < _depth; ++i) 
        {
			// Find the number of leading spaces for the current level
            int leadingSpaces = 3 * (_depth - (1 + i));

			// Print the leading spaces for the current level
            for (int space = 0; space < leadingSpaces; ++space) 
            {
                std::cout << " ";
            }
			
            for (int j = 0; j <= i; ++j) // Print the values for the current level
            {
				std::cout << std::setw(2) << _tree[i][j]; // Print the value
                if (j < i) 
                {
                    for (int space = 0; space < 3; ++space) 
                    {
						std::cout << " "; // Blank spaces between each number
                    }
                    if (_tree[i][j] < 99 && std::floor(_tree[i][j]) == _tree[i][j]) 
                    {
						std::cout << " "; // Additional space for two-digit numbers
                    }
                }
            }
            std::cout << std::endl;

            
            if (i < _depth - 1) 
            {
                int slashLeadingSpaces = 3 * (_depth - (i + 1)) - 1;

                // Print the leading spaces for the current level before the first /
                for (int space = 0; space < slashLeadingSpaces; ++space) 
                {
                    std::cout << " ";
                }

                for (int j = 0; j <= i; ++j) 
                {
                    std::cout << "/";
                    for (int space = 0; space < 3; ++space) 
                    {
						std::cout << " "; // Print spaces between each pair of / and \ //
                    }
                    std::cout << "\\";
                    if (j < i) {
                        for (int space = 0; space < 1; ++space) {
							std::cout << " "; // Print additional space between each pair of / and \ //
                        }
                    }
                }
                std::cout << std::endl;
            }
        }

		std::cout << std::endl;
    }
}

// BONUS 

// Implementation of the initializeBinomialModel method
template <typename T>
void BinaryTree<T>::initializeBinomialModel(T initialPrice, T upFactor, T downFactor) 
{
    setDepth(_depth - 1); // Set the depth and initialize tree structure
    _tree[0][0] = initialPrice; // Set the initial price at the root node

    // Populate the tree using the binomial model
    for (int level = 1; level < _depth; ++level) 
    {
        for (int i = 0; i <= level; ++i) 
        {
            if (i == 0) 
            {
                // Up movement from the first node in the previous level
                _tree[level][i] = _tree[level - 1][i] * upFactor;
            }
            else if (i == level) 
            {
                // Down movement from the last node in the previous level
                _tree[level][i] = _tree[level - 1][i - 1] * downFactor;
            }
            else 
            {
                // General case: we can arrive at this node from an up or down movement
                _tree[level][i] = _tree[level - 1][i - 1] * downFactor;
            }
        }
    }
}
