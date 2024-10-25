#pragma once

#ifndef OPTION_H
#define OPTION_H

class Option 
{
    private:
        double _expiry;

    public:
        //Constructeur qui initialise _expiry
        Option(double expiry);

        //Getter pour _expiry
        double getExpiry() const;

		//Méthode virtuelle pour le calcul du payoff de l'option
        virtual double payoff(double) const = 0;

};

#endif //OPTION_H