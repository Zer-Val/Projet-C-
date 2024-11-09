#pragma once
#include "AsianOption.h"

#ifndef ASIANCALLOPTION_H
#define ASIANCALLOPTION_H

class AsianCallOption : public AsianOption {
public:
    // Constructeur qui initialise _expiry, _timeSteps et _strike
    AsianCallOption(double expiry, const std::vector<double>& timeSteps, double strike);

    // Impl�mentation de la m�thode payoff
    double payoff(double underlyingPrice) const override;

private:
    double _strike; // Membre priv� pour le prix d'exercice
};

#endif // ASIANCALLOPTION_H