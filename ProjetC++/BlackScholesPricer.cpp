#include "BlackScholesPricer.h"
#include <iostream>

#ifndef M_SQRT1_2 // check if M_SRQT1_2 is not defined
#define M_SQRT1_2 0.70710678118654752440 // define M_SQRT1_2 as square root of 1/2
#endif


BlackScholesPricer::BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility)
    : option_(option), asset_price_(asset_price), interest_rate_(interest_rate), volatility_(volatility) {} // BSP class constructor

double BlackScholesPricer::normal_cdf(double x) const // Method for calculating the cumulative distribution function of the normal distribution
{
    return 0.5 * std::erfc(-x * M_SQRT1_2);
}

double BlackScholesPricer::operator()() const // Operator () to return the option price 
{
    double T = option_->getExpiry(); // Option maturity
    double K = option_->getStrike(); // Option exercise price
    double S = asset_price_; // Underlying asset price
    double r = interest_rate_; // Interest rates
    double sigma = volatility_; // Volatility

    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    if (option_->GetOptionType() == EuropeanVanillaOption::optionType::call)
    {
        return S * normal_cdf(d1) - K * std::exp(-r * T) * normal_cdf(d2);
    }
    else
    {
        return K * std::exp(-r * T) * normal_cdf(-d2) - S * normal_cdf(-d1);
    }
}

// Method for returning option delta
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
