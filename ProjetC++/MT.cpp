#include "MT.h"

// Méthode pour obtenir une instance unique de MT
MT& MT::getInstance() {
    static MT instance;
    return instance;
}

// Méthode pour générer un nombre aléatoire uniforme entre 0 et 1
double MT::rand_unif() {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(getInstance().mt);
}

// Méthode pour générer un nombre aléatoire normal avec une moyenne de 0 et un écart-type de 1
double MT::rand_norm() {
    std::normal_distribution<double> dist(0.0, 1.0);
    return dist(getInstance().mt);
}

// Constructeur privé pour empêcher la création d'instances en dehors de la classe
MT::MT() : mt(std::random_device{}()) {}