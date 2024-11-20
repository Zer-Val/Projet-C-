#include <iostream>
#include "BinaryTree.h" 

int main() {
    BinaryTree<double> tree;
    int depth = 10;
    double initialPrice = 100.0; // Starting price for the asset
    double upFactor = 1.1;       // Factor for an upward movement
    double downFactor = 0.9;     // Factor for a downward movement

    tree.setDepth(depth); // Set the depth for the binomial model

    // Initialize the tree with the binomial model
    tree.initializeBinomialModel(initialPrice, upFactor, downFactor);

    // Display the tree in the standard format
    std::cout << "Standard Display of the Binomial Model:\n";
    tree.display();

    // Display the tree in the pyramid format
    std::cout << "\nPyramid Display of the Binomial Model:\n";
    tree.displayPyramid();

    return 0;
}
