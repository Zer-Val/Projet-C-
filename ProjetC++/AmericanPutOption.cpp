#include "AmericanPutOption.h"

//Implementation of the constructor for AmericanCallOption, uses the one from AmericanOption
AmericanPutOption::AmericanPutOption(double expiry, double strike) : AmericanOption(expiry, strike) {}

//Implementation of the Payoff method for an European Vanilla Call option


//Implementation of the GetOptionType method for a Call option
AmericanPutOption::optionType AmericanPutOption::GetOptionType() const
{
	return optionType::put;
}