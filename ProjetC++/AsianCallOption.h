#pragma once
#include "AsianOption.h"

#ifndef ASIANCALLOPTION_H
#define ASIANCALLOPTION_H

class AsianCallOption : public AsianOption {
public:
    // Constructeur qui initialise _expiry, _timeSteps et _strike
    AsianCallOption(const std::vector<double>& timeSteps, double strike);

    // Implémentation de la méthode payoff
    double payoff(double underlyingPrice) const override;

private:
    double _strike; // Membre privé pour le prix d'exercice
};

#endif // ASIANCALLOPTION_H
