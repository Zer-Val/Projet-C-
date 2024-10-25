#pragma once
#include <stdexcept>
#include "Options.h"
#include <iostream>

#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H

class BlackScholesPricer; // Déclaration anticipée

class EuropeanVanillaOption : public Option {
public:
    enum class optionType { call, put };

    EuropeanVanillaOption(double expiry, double strike) : _expiry(expiry), _strike(strike) {}

    virtual ~EuropeanVanillaOption() {}

    double getExpiry() const { return _expiry; }
    double getStrike() const { return _strike; }

    virtual double payoff(double z) const = 0;

    virtual optionType GetOptionType() const = 0;

    //On déclare BSP comme classe amie de EVO
    friend class BlackScholesPricer;

private:
    double _expiry;
    double _strike;
};

#endif //EUROPEANVANILLAOPTION_H
