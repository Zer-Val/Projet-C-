#include "EuropeanDigitalOption.h"

// Constructeur qui initialise _expiry et _strike
EuropeanDigitalOption::EuropeanDigitalOption(double K, double expiry) 
    : Option(expiry), strike(K) {
    if (expiry < 0 || strike < 0) {
        throw std::invalid_argument("Expiry and strike must be non-negative");
    }
}

// Méthode getter pour _strike
double EuropeanDigitalOption::getStrike() const {
    return strike;
}
