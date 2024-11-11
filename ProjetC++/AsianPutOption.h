#pragma once
#include "AsianOption.h"

#ifndef ASIANPUTOPTION_H
#define ASIANPUTOPTION_H

class AsianPutOption : public AsianOption {
public:
    // Constructeur qui initialise _timeSteps et _strikePrice
    AsianPutOption(const std::vector<double>& timeSteps, double strike);

    // Implémentation de la méthode payoff
    double payoff(double underlyingPrice) const override;

private:
    double _strike; // Membre privé pour le prix d'exercice
};

#endif // ASIANPUTOPTION_H
