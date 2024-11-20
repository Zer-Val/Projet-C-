#pragma once
#include "EuropeanVanillaOption.h"

#ifndef CALLOPTION_H
#define CALLOPTION_H

class CallOption : public EuropeanVanillaOption
{
public:
    //Cosntructor using EVO's
    CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

    //Payoff implementation for a Call
    double payoff(double z) const override;

    //Implementation of GetOptionType for a Call
    optionType GetOptionType() const override;
};

#endif //CALLOPTION_H