#include "CallOption.h"

// Implementation of the constructor for CallOption, uses the one from EuropeanVanillaOption
CallOption::CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

//Implementation of the Payoff method for an European Vanilla Call option
double CallOption::payoff(double z) const
{
	return (z >= getStrike()) ? (z - getStrike()) : 0.0;   // ? est un opérateur ternaire, je m'en sers pour écrire des conditions if-else en une seule ligne. Ici (z >= getStrike()) ? (z - getStrike()) : 0.0 <=> if (z >= getStrike()) { return z - getStrike(); } else { return 0.0; }
}

//Implementation of the GetOptionType method for an European Vanilla Call option
EuropeanVanillaOption::optionType CallOption::GetOptionType() const
{
	return optionType::call;
}
