#pragma once
#include "EuropeanVanillaOption.h"

#ifndef PUTOPTION_H
#define PUTOPTION_H

class PutOption : public EuropeanVanillaOption
{
public:
    //Constructor using EVO's
    PutOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

    //Payoff implementation for a Put
    double payoff(double z) const override;

    //Implementation of GetOptionType for a Put
    optionType GetOptionType() const override;
};

#endif //PUTOPTION_H
