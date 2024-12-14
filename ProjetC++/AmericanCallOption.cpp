#include "AmericanCallOption.h"

// Implementation of the constructor for AmericanCallOption, uses the one from AmericanOption
AmericanCallOption::AmericanCallOption(double expiry, double strike) : AmericanOption(expiry, strike) {}

//Payoff method for an Amerocan Call option
double AmericanCallOption::payoff(double z) const
{
	return (z >= getStrike()) ? (z - getStrike()) : 0.0;
}

//GetOptionType method for a(n) (American) Call option
AmericanCallOption::optionType AmericanCallOption::GetOptionType() const
{
	return optionType::call;
}
