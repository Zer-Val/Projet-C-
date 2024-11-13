#pragma once

#include "EuropeanDigitalOption.h"

class EuropeanDigitalPutOption : public EuropeanDigitalOption {
public:
	// Constructeur de la classe EuropeanDigitalPutOption
    EuropeanDigitalPutOption(double K, double expiry) : EuropeanDigitalOption(K, expiry) {} 
    
	// Impl�mentation de la m�thode payoff pour une option digitale put
    double payoff(double z) const override;

	//Impl�mentation de GetOptionType pour une Put
	optionType GetOptionType() const override;
};