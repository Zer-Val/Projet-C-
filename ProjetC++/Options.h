#pragma once

#ifndef OPTION_H
#define OPTION_H

class Option {
public:
    //Constructeur qui initialise _expiry
    Option(double expiry);

    //Méthode getter pour _expiry
    double getExpiry() const;

    //Méthode virtuelle pure pour le calcul du payoff
    virtual double payoff(double underlyingPrice) const = 0;

private:
    double _expiry; //Membre privé pour la date d'expiration
};

#endif //OPTION_H
