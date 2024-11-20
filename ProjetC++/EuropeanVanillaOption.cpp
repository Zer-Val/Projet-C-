// EuropeanVanillaOption.cpp
#include "EuropeanVanillaOption.h"

// Constructor initializing _expiry and _strike
EuropeanVanillaOption::EuropeanVanillaOption(double expiry, double strike)
    : Option(expiry), _strike(strike) {
    if (expiry < 0 || strike < 0) {
        throw std::invalid_argument("Expiry and strike must be non-negative");
    }
}

// Get method for _strike
double EuropeanVanillaOption::getStrike() const {
    return _strike;
}