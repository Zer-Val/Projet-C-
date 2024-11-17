#include "MT.h"

// M�thode pour obtenir une instance unique de MT
MT& MT::getInstance() {
    static MT instance;
    return instance;
}

// M�thode pour g�n�rer un nombre al�atoire uniforme entre 0 et 1
double MT::rand_unif() {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(getInstance().mt);
}

// M�thode pour g�n�rer un nombre al�atoire normal avec une moyenne de 0 et un �cart-type de 1
double MT::rand_norm() {
    std::normal_distribution<double> dist(0.0, 1.0);
    return dist(getInstance().mt);
}

// Constructeur priv� pour emp�cher la cr�ation d'instances en dehors de la classe
MT::MT() : mt(std::random_device{}()) {}