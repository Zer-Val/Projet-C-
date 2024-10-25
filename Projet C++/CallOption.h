#pragma once
#include "EuropeanVanillaOption.h"
#ifndef CALLOPTION_H
#define CALLOPTION_H
class CallOption : public EuropeanVanillaOption 
{
    public:
        //Constructeur, qui utilise le celui de EVO
        CallOption(double expiry, double strike);

        //Impl�mentation de payoff pour une Call
        double payoff(double z) const override;

		//Impl�mentation de GetOptionType pour une Call
        optionType GetOptionType() const override;
};

#endif //CALLOPTION_H
