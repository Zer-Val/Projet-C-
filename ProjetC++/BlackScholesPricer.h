#pragma once
#include <cmath>
#include "EuropeanVanillaOption.h"

#ifndef BLACKSCHOLESPRICER_H
#define BLACKSCHOLESPRICER_H

class BlackScholesPricer {
public:

    BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility); //Constructeur de la classe BSP
    double operator()() const; //Opérateur () pour calculer le prix de l'option
    double delta() const; //Méthode pour calculer le delta de l'option

private:
    EuropeanVanillaOption* option_; //Pointeur vers l'option qu'on veut pricer
    double asset_price_; //Prix de l'actif sous-jacent (S)
    double interest_rate_; //Taux d'intérêt (r)
    double volatility_;  //Volatilité (vol)
};

#endif //BLACKSCHOLESPRICER_H
