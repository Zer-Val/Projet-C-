#include "EuropeanDigitalCallOption.h"

// Impl�mentation de la m�thode payoff pour une option digitale call
double EuropeanDigitalCallOption::payoff(double z) const {
    return z >= getStrike() ? 1.0 : 0.0;
}

//Impl�mentation de GetOptionType pour une Call
EuropeanDigitalOption::optionType EuropeanDigitalCallOption::GetOptionType() const {
	return optionType::call;
}

