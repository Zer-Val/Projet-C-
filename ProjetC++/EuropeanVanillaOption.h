#pragma once
#include <stdexcept>
#include "Options.h"
#include <iostream>

class BlackScholesPricer; //Early declaration of the BSP class

#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H


class EuropeanVanillaOption : public Option {
public:
    //Enum for option type
    enum class optionType { call, put };

    //Constructor initializing _expiry and _strike
    EuropeanVanillaOption(double expiry, double strike);

    //Get method for _strike
    double getStrike() const;

    //Pure virtual method for obtaining the option type
    virtual optionType GetOptionType() const = 0;

    //We declare BSP as an EVO-friendly class
    friend class BlackScholesPricer;

private:
    double _strike; //Private member for the exercise price
};

#endif // EUROPEANVANILLAOPTION_H