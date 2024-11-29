#pragma once

#include "EuropeanDigitalOption.h"

class EuropeanDigitalCallOption : public EuropeanDigitalOption 
{
	public:
		// Constructor for the EuropeanDigitalCallOption class
		EuropeanDigitalCallOption(double expiry, double strike);

		// Payoff method for a digital Call option
		double payoff(double z) const override;

		// GetOptionType method for a Call option
		optionType GetOptionType() const override;
};
