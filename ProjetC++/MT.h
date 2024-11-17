#pragma once

#include <random>

class MT {
public:
    // M�thode pour obtenir une instance unique de MT
    static MT& getInstance();

    // M�thode pour g�n�rer un nombre al�atoire uniforme entre 0 et 1
    static double rand_unif();

    // M�thode pour g�n�rer un nombre al�atoire normal avec une moyenne de 0 et un �cart-type de 1
    static double rand_norm();

private:
    // Constructeur priv� pour emp�cher la cr�ation d'instances en dehors de la classe
    MT();

    // Suppression des constructeurs de copie et d'affectation
    MT(const MT&) = delete;
    MT& operator=(const MT&) = delete;

    std::mt19937 mt; // G�n�rateur de nombres al�atoires
};