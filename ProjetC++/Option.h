#pragma once
#include <vector>

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

    //Méthode virtuelle pure pour le calcul du payoff d'un chemin (pour les options asiatiques)
    virtual double payoffPath(const std::vector<double>& prices) const;

    // Méthode virtuelle pour vérifier si c'est une option asiatique
    virtual bool isAsianOption() const;

private:
    double _expiry; //Membre privé pour la date d'expiration
};

#endif //OPTION_H
