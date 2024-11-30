#pragma once
#include "EuropeanVanillaOption.h"

class CallOption : public EuropeanVanillaOption
{
    public:
		//Constructor for CallOption, uses the one from EuropeanVanillaOption
        CallOption(double expiry, double strike);

        //Payoff method for an European Vanilla Call option
        double payoff(double z) const override;

        //GetOptionType method for an European Vanilla Call option
        optionType GetOptionType() const override;
};
