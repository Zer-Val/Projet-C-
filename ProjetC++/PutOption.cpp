#include "PutOption.h"

//Implémentation de payoff pour une Put
double PutOption::payoff(double z) const
{
	return (getStrike() >= z) ? (getStrike() - z) : 0.0; // ? est un opérateur ternaire, je m'en sers pour écrire des conditions if-else en une seule ligne ici (getStrike() >= z) ? (getStrike() - z) : 0.0 <=> if (getStrike() >= z) { return getStrike() - z; } else { return 0.0; }
}

//Implémentation de GetOptionType pour une Put
EuropeanVanillaOption::optionType PutOption::GetOptionType() const
{
	return optionType::put;
}