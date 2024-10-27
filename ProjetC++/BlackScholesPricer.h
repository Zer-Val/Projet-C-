#pragma once
#include <cmath>
#include "EuropeanVanillaOption.h"

#ifndef BLACKSCHOLESPRICER_H
#define BLACKSCHOLESPRICER_H

class BlackScholesPricer {
public:

    BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility); //Constructeur de la classe BSP
    double operator()() const; //Op�rateur () pour calculer le prix de l'option
    double delta() const; //M�thode pour calculer le delta de l'option

private:
    EuropeanVanillaOption* option_; //Pointeur vers l'option qu'on veut pricer
    double asset_price_; //Prix de l'actif sous-jacent (S)
    double interest_rate_; //Taux d'int�r�t (r)
    double volatility_;  //Volatilit� (vol)

    double normal_cdf(double x) const; //M�thode pour calculer la fonction de r�partition cumulative de la loi normale
};

#endif //BLACKSCHOLESPRICER_H