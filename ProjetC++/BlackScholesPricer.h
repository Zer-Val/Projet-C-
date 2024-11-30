#pragma once
#include <cmath>
#include "EuropeanVanillaOption.h"
#include "EuropeanDigitalOption.h"

class BlackScholesPricer 
{
	public:

		BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility); //Constructor of the BSP class for a European Vanilla Option
		BlackScholesPricer(EuropeanDigitalOption* option, double asset_price, double interest_rate, double volatility); //Constructor of the BSP class for a European Digital Option
		double operator()() const; //Operator () to price the option
		double delta() const; //Method to compute the delta of the option

	private:
		EuropeanVanillaOption* vanilla_option_; // Pointer to the vanilla option we want to price
		EuropeanDigitalOption* digital_option_; // Pointer to the digital option we want to price
		double _asset_price; // Underlying asset price (S)
		double _interest_rate; // Risk-free interest rate (r)
		double _volatility; // Volatility (vol)
};
