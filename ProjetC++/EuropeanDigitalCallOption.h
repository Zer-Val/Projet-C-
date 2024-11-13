#pragma once

#include "EuropeanDigitalOption.h"

class EuropeanDigitalCallOption : public EuropeanDigitalOption {
public:
	// Constructeur de la classe EuropeanDigitalCallOption
	EuropeanDigitalCallOption(double K, double expiry) : EuropeanDigitalOption(K, expiry) {}

	// Implémentation de la méthode payoff pour une option digitale call
    double payoff(double z) const override;

	//Implémentation de GetOptionType pour une Call
	optionType GetOptionType() const override;
};