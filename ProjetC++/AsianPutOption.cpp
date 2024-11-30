#include "AsianPutOption.h"
#include <algorithm> 

// Constructeur qui initialise _timeSteps et _strikePrice
AsianPutOption::AsianPutOption(const std::vector<double>& timeSteps, double strike) : AsianOption(timeSteps), _strike(strike) {}

// Implémentation de la méthode payoff pour l'option Put
double AsianPutOption::payoff(double underlyingPrice) const 
{
    return std::max(_strike - underlyingPrice, 0.0);
}
