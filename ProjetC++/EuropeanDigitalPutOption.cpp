#include "EuropeanDigitalPutOption.h"

// Impl�mentation de la m�thode payoff pour une option digitale put
double EuropeanDigitalPutOption::payoff(double z) const {
    return z <= getStrike() ? 1.0 : 0.0;
}

//Impl�mentation de GetOptionType pour une Put
EuropeanDigitalOption::optionType EuropeanDigitalPutOption::GetOptionType() const {
	return optionType::put;
}