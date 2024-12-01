#include "EuropeanVanillaOption.h"

//Constructor that initialize _strike
EuropeanVanillaOption::EuropeanVanillaOption(double expiry, double strike)
    : Option(expiry), _strike(strike) {
    if (expiry < 0 || strike < 0) {
        throw std::invalid_argument("Expiry and strike must be non-negative");
    }
}

// Getter method for _strike
double EuropeanVanillaOption::getStrike() const 
{
    return _strike;
}

// Override of isAsianOption to return false for EVO - (Compilation issue if not)
bool EuropeanVanillaOption::isAsianOption() const 
{
    return false;
}
