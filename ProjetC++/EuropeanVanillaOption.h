#pragma once
#include <stdexcept>
#include "Options.h"
#include <iostream>

class BlackScholesPricer; //D�claration anticip�e de la classe BSP

#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H


class EuropeanVanillaOption : public Option {
public:
    //Enum pour le type d'option
    enum class optionType { call, put };

    //Constructeur qui initialise _expiry et _strike
    EuropeanVanillaOption(double expiry, double strike);

    //M�thode getter pour _strike
    double getStrike() const;

    //M�thode virtuelle pure pour obtenir le type d'option
    virtual optionType GetOptionType() const = 0;

    //On d�clare BSP comme classe amie de EVO
    friend class BlackScholesPricer;

private:
    double _strike; //Membre priv� pour le prix d'exercice
};

#endif // EUROPEANVANILLAOPTION_H