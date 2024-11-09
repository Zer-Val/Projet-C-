#include "BlackScholesPricer.h"
#include <iostream>

#ifndef M_SQRT1_2 // check if M_SRQT1_2 is not defined
#define M_SQRT1_2 0.70710678118654752440 // define M_SQRT1_2 as square root of 1/2
#endif


BlackScholesPricer::BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility)
    : option_(option), asset_price_(asset_price), interest_rate_(interest_rate), volatility_(volatility) {} // Constructeur de la classe BSP


double BlackScholesPricer::operator()() const // Opérateur () pour retourner le prix de l'option 
{
    double T = option_->getExpiry(); // Maturité de l'option
    double K = option_->getStrike(); // Prix d'exercice de l'option
    double S = asset_price_; // Prix de l'actif sous-jacent
    double r = interest_rate_; // Taux d'intérêt
    double sigma = volatility_; // Volatilité

    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    if (option_->GetOptionType() == EuropeanVanillaOption::optionType::call)
    {
        return S * normal_cdf(d1) - K * std::exp(-r * T) * (0.5 * std::erfc(-d2 * M_SQRT1_2));
    }
    else
    {
        return K * std::exp(-r * T) * normal_cdf(-d2) - S * (0.5 * std::erfc(-d1 * M_SQRT1_2));
    }
}

// Méthode pour retourner le Delta de l'option
double BlackScholesPricer::delta() const {
    double T = option_->getExpiry();
    double K = option_->getStrike();
    double S = asset_price_;
    double sigma = volatility_;

    double d1 = (std::log(S / K) + (interest_rate_ + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));

    if (option_->GetOptionType() == EuropeanVanillaOption::optionType::call)
    {
        return normal_cdf(d1);
    }
    else
    {
        return normal_cdf(d1) - 1;
    }
}
