#include "AsianCallOption.h"
#include <algorithm>

// Constructeur qui initialise _expiry, _timeSteps et _strike
AsianCallOption::AsianCallOption(const std::vector<double>& timeSteps, double strikePrice)
    : AsianOption(timeSteps), _strike(strikePrice) {}

// Implémentation de la méthode payoff pour l'option Call
double AsianCallOption::payoff(double underlyingPrice) const {
    return std::max(underlyingPrice - _strike, 0.0);
}
