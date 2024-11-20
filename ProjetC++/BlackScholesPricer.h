#pragma once
#include <cmath>
#include "EuropeanVanillaOption.h"

#ifndef BLACKSCHOLESPRICER_H
#define BLACKSCHOLESPRICER_H

class BlackScholesPricer {
public:

    BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility); //BSP class Cosntructor
    double operator()() const; //Operator () to return the option price 
    double delta() const; //Method for returning option delta

private:
    EuropeanVanillaOption* option_; //Pointer to the option to be priced
    double asset_price_; //Price of underlying asset (S)
    double interest_rate_; //Interest rate (r)
    double volatility_;  //Volatility (vol)

    double normal_cdf(double x) const; //Method for calculating the cumulative distribution function of the normal distribution
};

#endif //BLACKSCHOLESPRICER_H