#include "BinaryTree.h"

template <typename T>
void BinaryTree<T>::setDepth(int depth) {
    _depth = depth;
    _tree.resize(_depth + 1);
    for (int i = 0; i <= _depth; ++i) {
        _tree[i].resize(i + 1);
    }
}

template <typename T>
void BinaryTree<T>::setNode(int level, int index, T value) {
    if (level >= 0 && level <= _depth && index >= 0 && index <= level) {
        _tree[level][index] = value;
    }
    else {
        throw std::out_of_range("Indices out of range");
    }
}

template <typename T>
T BinaryTree<T>::getNode(int level, int index) const {
    if (level >= 0 && level <= _depth && index >= 0 && index <= level) {
        return _tree[level][index];
    }
    else {
        throw std::out_of_range("Indices out of range");
    }
}

template <typename T>
void BinaryTree<T>::display() const {
    int max_width = 4; // Largeur maximale pour chaque valeur
    for (int i = 0; i <= _depth; ++i) {
        int spaces = (1 << (_depth - i)) - 1; // Espaces avant le premier élément
        int between = (1 << (_depth - i + 1)) - 1; // Espaces entre les éléments
        std::cout << std::setw(spaces * max_width) << ""; // Espaces initiaux
        for (int j = 0; j <= i; ++j) {
            std::cout << std::setw(max_width) << _tree[i][j];
            if (j < i) {
                std::cout << std::setw(between * max_width) << ""; // Espaces entre les éléments
            }
        }
        std::cout << std::endl;
    }
}

// Instanciations explicites des templates pour les types utilisés
template class BinaryTree<int>;
template class BinaryTree<double>;
template class BinaryTree<std::string>;