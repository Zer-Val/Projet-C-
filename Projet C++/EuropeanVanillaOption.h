#pragma once
#include <stdexcept>
#include "Options.h"
#include <iostream>

class BlackScholesPricer; //Déclaration anticipée de la classe BSP

#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H


class EuropeanVanillaOption : public Option {
public:
    //Enum pour le type d'option
    enum class optionType { call, put };

    //Constructeur qui initialise _expiry et _strike
    EuropeanVanillaOption(double expiry, double strike);

    //Méthode getter pour _strike
    double getStrike() const;

    //Méthode virtuelle pure pour obtenir le type d'option
    virtual optionType GetOptionType() const = 0;

    //On déclare BSP comme classe amie de EVO
    friend class BlackScholesPricer;

private:
    double _strike; //Membre privé pour le prix d'exercice
};

#endif // EUROPEANVANILLAOPTION_H
