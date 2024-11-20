#include "CallOption.h"

//Payoff implementation for a Call
double CallOption::payoff(double z) const
{
	return (z >= getStrike()) ? (z - getStrike()) : 0.0;   // ? is a ternary operator, which I use to write if-else conditions in a single line. Here (z >= getStrike()) ? (z - getStrike()) : 0.0 <=> if (z >= getStrike()) { return z - getStrike(); } else { return 0.0; }
}


// Implementation of GetOptionType for a Call
EuropeanVanillaOption::optionType CallOption::GetOptionType() const
{
	return optionType::call;
}