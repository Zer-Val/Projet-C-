#include "EuropeanDigitalCallOption.h"

// Implémentation de la méthode payoff pour une option digitale call
double EuropeanDigitalCallOption::payoff(double z) const {
    return z >= getStrike() ? 1.0 : 0.0;
}

//Implémentation de GetOptionType pour une Call
EuropeanDigitalOption::optionType EuropeanDigitalCallOption::GetOptionType() const {
	return optionType::call;
}

