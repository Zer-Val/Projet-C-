#include "AmericanCallOption.h"

// Implementation of the constructor for AmericanCallOption, uses the one from AmericanOption
AmericanCallOption::AmericanCallOption(double expiry, double strike) : AmericanOption(expiry, strike) {}

//Implementation of the Payoff method for an European Vanilla Call option
double AmericanCallOption::payoff(double z) const
{

}

//Implementation of the GetOptionType method for a Call option
AmericanCallOption::optionType AmericanCallOption::GetOptionType() const
{
	return optionType::call;
}