#pragma once
#include "EuropeanDigitalOption.h"

class EuropeanDigitalPutOption : public EuropeanDigitalOption 
{
	public:
		// Constructor for the EuropeanDigitalPutOption class
		EuropeanDigitalPutOption(double expiry, double strike);
    
		// Payoff method for a digital Put option
		double payoff(double z) const override;

		// GetOptionType method for a Put option
		optionType GetOptionType() const override;
};
