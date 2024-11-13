#pragma once

#include "EuropeanDigitalOption.h"

class EuropeanDigitalCallOption : public EuropeanDigitalOption {
public:
	// Constructeur de la classe EuropeanDigitalCallOption
	EuropeanDigitalCallOption(double K, double expiry) : EuropeanDigitalOption(K, expiry) {}

	// Impl�mentation de la m�thode payoff pour une option digitale call
    double payoff(double z) const override;

	//Impl�mentation de GetOptionType pour une Call
	optionType GetOptionType() const override;
};