#include "EuropeanDigitalPutOption.h"

// Implémentation de la méthode payoff pour une option digitale put
double EuropeanDigitalPutOption::payoff(double z) const {
    return z <= getStrike() ? 1.0 : 0.0;
}

//Implémentation de GetOptionType pour une Put
EuropeanDigitalOption::optionType EuropeanDigitalPutOption::GetOptionType() const {
	return optionType::put;
}