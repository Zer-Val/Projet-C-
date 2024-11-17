#pragma once

#include <random>

class MT {
public:
    // Méthode pour obtenir une instance unique de MT
    static MT& getInstance();

    // Méthode pour générer un nombre aléatoire uniforme entre 0 et 1
    static double rand_unif();

    // Méthode pour générer un nombre aléatoire normal avec une moyenne de 0 et un écart-type de 1
    static double rand_norm();

private:
    // Constructeur privé pour empêcher la création d'instances en dehors de la classe
    MT();

    // Suppression des constructeurs de copie et d'affectation
    MT(const MT&) = delete;
    MT& operator=(const MT&) = delete;

    std::mt19937 mt; // Générateur de nombres aléatoires
};