#pragma once
#pragma once
#include <stdexcept>
#include "Option.h"
#include <iostream>

class BlackScholesPricer; //D�claration anticip�e de la classe BSP

class EuropeanDigitalOption : public Option {
public:
	// Enum pour le type d'option
    enum class optionType { call, put };
	
    //Constructeur qui initialise _expiry et _strike
    EuropeanDigitalOption(double expiry, double strike) ;

    //M�thode getter pour _strike  
    double getStrike() const;

    //M�thode virtuelle pure pour obtenir le type d'option 
    virtual optionType GetOptionType() const = 0;

    //On d�clare BSP comme classe amie de EVO pour pouvoir acc�der � _strike dans BSP
    friend class BlackScholesPricer;

private:
    double strike;
};