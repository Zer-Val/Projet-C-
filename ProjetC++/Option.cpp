#include "Option.h"
#include <iostream>

// Constructeur qui initialise _expiry
Option::Option(double expiry) : _expiry(expiry) {}

// Méthode getter pour _expiry
double Option::getExpiry() const {
    return _expiry;
}

// Implémentation de la méthode payoffPath qui retourne la valeur de la méthode payoff avec le dernier élément du vecteur prices par défaut
double Option::payoffPath(const std::vector<double>& prices) const {
    // Appel de la méthode payoff(double) avec le dernier élément du vecteur
    return payoff(prices.back());
}

// Implémentation de la méthode isAsianOption qui retourne false par défaut
bool Option::isAsianOption() const {
    return false;
}
