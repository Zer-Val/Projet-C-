#pragma once
#include "EuropeanVanillaOption.h"

#ifndef PUTOPTION_H
#define PUTOPTION_H

class PutOption : public EuropeanVanillaOption 
{
    public:
        //Constructeur qui utilise celui d'EVO
        PutOption(double expiry, double strike): EuropeanVanillaOption(expiry, strike) {}

        //Implémentation de payoff pour une Put
        double payoff(double z) const override;

		//Implémentation de GetOptionType pour une Put
        optionType GetOptionType() const override;
};

#endif //PUTOPTION_H

