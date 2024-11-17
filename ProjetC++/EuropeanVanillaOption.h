#pragma once
#include <stdexcept>
#include "Option.h"
#include <iostream>

class BlackScholesPricer; //Déclaration anticipée de la classe BSP

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

	//On déclare BSP comme classe amie de EVO pour pouvoir accéder à _strike dans BSP
    friend class BlackScholesPricer;

	//Override de isAsianOption pour retourner false pour EVO - (Probleme de compilation si on ne le fait pas)
    bool isAsianOption() const override;

private:
    double _strike; //Membre privé pour le prix d'exercice
};

