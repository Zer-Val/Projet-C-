#include "Options.h"
#include <iostream>

// Constructeur qui initialise _expiry
Option::Option(double expiry) : _expiry(expiry) {}

// Méthode getter pour _expiry
double Option::getExpiry() const {
    return _expiry;
}