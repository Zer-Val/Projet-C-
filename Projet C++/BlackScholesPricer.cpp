#include "BlackScholesPricer.h"
#include <cmath>
#include <iostream>

#ifndef M_SQRT1_2 // check if M_SRQT1_2 is not defined
#define M_SQRT1_2 0.70710678118654752440 // define M_SQRT1_2 as square root of 1/2
#endif

//Constructeur de la classe BSP
BlackScholesPricer::BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility)
    : option_(option), asset_price(asset_price), interest_rate(interest_rate), volatility(volatility) {}

//Méthode pour calculer la Frep cumulative de la loi normale
double BlackScholesPricer::normal_cdf(double x) const {
    return 0.5 * std::erfc(-x * M_SQRT1_2);
}

//On définit l'opérateur () pour retourner le prix d'une option (Call ou Put)
double BlackScholesPricer::operator()() const {
    double K = option_->getStrike();
    double T = option_->getExpiry();
    double d1 = (std::log(asset_price / K) + (interest_rate + 0.5 * volatility * volatility) * T) / (volatility * std::sqrt(T));
    double d2 = d1 - volatility * std::sqrt(T);

    if (option_->GetOptionType() == EuropeanVanillaOption::optionType::call) {
        return asset_price * normal_cdf(d1) - K * std::exp(-interest_rate * T) * normal_cdf(d2);
    }
    else {
        return K * std::exp(-interest_rate * T) * normal_cdf(-d2) - asset_price * normal_cdf(-d1);
    }
}

//Méthode pour retourner le Delta d'une option (Call ou Put)
double BlackScholesPricer::delta() const {
    double T = option_->getExpiry();
    double d1 = (std::log(asset_price / option_->getStrike()) + (interest_rate + 0.5 * volatility * volatility) * T) / (volatility * std::sqrt(T));

    if (option_->GetOptionType() == EuropeanVanillaOption::optionType::call) {
        return normal_cdf(d1);
    }
    else {
        return normal_cdf(d1) - 1;
    }
}