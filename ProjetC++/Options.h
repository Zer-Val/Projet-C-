#pragma once

#ifndef OPTION_H
#define OPTION_H

class Option {
public:
    //Constructeur qui initialise _expiry
    Option(double expiry);

    //M�thode getter pour _expiry
    double getExpiry() const;

    //M�thode virtuelle pure pour le calcul du payoff
    virtual double payoff(double underlyingPrice) const = 0;

private:
    double _expiry; //Membre priv� pour la date d'expiration
};

#endif //OPTION_H
