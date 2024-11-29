#include "AsianCallOption.h"
#include <algorithm>

// Constructor that initializes _strike
AsianCallOption::AsianCallOption(const std::vector<double>& timeSteps, double strikePrice) : AsianOption(timeSteps), _strike(strikePrice) {}

// Implementation of the payoff method for the Call option
double AsianCallOption::payoff(double underlyingPrice) const 
{
    return std::max(underlyingPrice - _strike, 0.0);
}
