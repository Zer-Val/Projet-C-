#include "AsianCallOption.h"
#include <algorithm>

// Constructeur qui initialise _expiry, _timeSteps et _strike
AsianCallOption::AsianCallOption(double expiry, const std::vector<double>& timeSteps, double strike)
    : AsianOption(expiry, timeSteps), _strike(strike) {}

// Implémentation de la méthode payoff
double AsianCallOption::payoff(double underlyingPrice) const {
    return std::max(0.0, underlyingPrice - _strike);
}