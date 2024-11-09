#include "AsianPutOption.h"
#include <algorithm> 

// Constructeur qui initialise _expiry, _timeSteps et _strike
AsianPutOption::AsianPutOption(double expiry, const std::vector<double>& timeSteps, double strike)
    : AsianOption(expiry, timeSteps), _strike(strike) {}

// Implémentation de la méthode payoff
double AsianPutOption::payoff(double underlyingPrice) const {
    return std::max(0.0, _strike - underlyingPrice);
}