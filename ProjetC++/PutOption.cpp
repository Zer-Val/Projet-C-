#include "PutOption.h"

//Impl�mentation de payoff pour une Put
double PutOption::payoff(double z) const
{
	return (getStrike() >= z) ? (getStrike() - z) : 0.0; // ? est un op�rateur ternaire, je m'en sers pour �crire des conditions if-else en une seule ligne ici (getStrike() >= z) ? (getStrike() - z) : 0.0 <=> if (getStrike() >= z) { return getStrike() - z; } else { return 0.0; }
}

//Impl�mentation de GetOptionType pour une Put
EuropeanVanillaOption::optionType PutOption::GetOptionType() const
{
	return optionType::put;
}