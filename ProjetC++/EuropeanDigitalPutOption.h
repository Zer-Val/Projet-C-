#pragma once

#include "EuropeanDigitalOption.h"

class EuropeanDigitalPutOption : public EuropeanDigitalOption {
public:
	// Constructeur de la classe EuropeanDigitalPutOption
    EuropeanDigitalPutOption(double K, double expiry) : EuropeanDigitalOption(K, expiry) {} 
    
	// Implémentation de la méthode payoff pour une option digitale put
    double payoff(double z) const override;

	//Implémentation de GetOptionType pour une Put
	optionType GetOptionType() const override;
};