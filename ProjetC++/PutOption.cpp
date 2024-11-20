#include "PutOption.h"

//Payoff implementation for a put
double PutOption::payoff(double z) const
{
	return (getStrike() >= z) ? (getStrike() - z) : 0.0; // ? is a ternary operator, I use it to write if-else conditions in a single line here (getStrike() >= z) ? (getStrike() - z) : 0.0 <=> if (getStrike() >= z) { return getStrike() - z; } else { return 0.0; }
}

//Implementation of GetOptionType for a Put
EuropeanVanillaOption::optionType PutOption::GetOptionType() const
{
	return optionType::put;
}