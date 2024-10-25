#pragma once
#include <cmath>
#include "EuropeanVanillaOption.h"

#ifndef BLACKSCHOLESPRICER_H
#define BLACKSCHOLESPRICER_H
class BlackScholesPricer {
public:
    //Constructeur de la classe BSP
    BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility);

    //On d�finit l'op�rateur () pour retourner le prix d'une option
    double operator()() const;

    //M�thode pour retourner le Delta d'une option
    double delta() const;

private:
    
    EuropeanVanillaOption* option_;
    double asset_price;
    double interest_rate;
    double volatility;

    //M�thode pour calculer la Frep cumulative de la loi normale
    double normal_cdf(double x) const;
};
#endif //BLACKSCHOLESPRICER_H