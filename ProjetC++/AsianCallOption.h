#pragma once
#include "AsianOption.h"

class AsianCallOption : public AsianOption 
{
	public:
		// Constructor that initializes _strike
		AsianCallOption(const std::vector<double>& timeSteps, double strike);

		// Implementation of the payoff method for the Call option
		double payoff(double underlyingPrice) const override;

	private:
		double _strike; //Private member to store the strike price of the option
};
