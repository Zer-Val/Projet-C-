#pragma once
#include "EuropeanVanillaOption.h"
#ifndef CALLOPTION_H
#define CALLOPTION_H
class CallOption : public EuropeanVanillaOption 
{
    public:
        //Constructeur, qui utilise le celui de EVO
        CallOption(double expiry, double strike);

        //Implémentation de payoff pour une Call
        double payoff(double z) const override;

		//Implémentation de GetOptionType pour une Call
        optionType GetOptionType() const override;
};

#endif //CALLOPTION_H
