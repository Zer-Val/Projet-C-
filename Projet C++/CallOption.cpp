#include "CallOption.h"

//Constructeur qui utilise le celui de EVO
CallOption::CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

//Impl�mentation de payoff pour une Call
double CallOption::payoff(double z) const {
	return (z >= getStrike()) ? (z - getStrike()) : 0.0;   // ? est un op�rateur ternaire, je m'en sers pour �crire des conditions if-else en une seule ligne. Ici (z >= getStrike()) ? (z - getStrike()) : 0.0 <=> if (z >= getStrike()) { return z - getStrike(); } else { return 0.0; }
}

//Impl�mentation de GetOptionType pour une Call
EuropeanVanillaOption::optionType CallOption::GetOptionType() const {
    return optionType::call;
}