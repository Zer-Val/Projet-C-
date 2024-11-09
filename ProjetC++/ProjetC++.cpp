// Projet C++.cpp : Ce fichier contient la fonction 'main'. 
// L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include "Option.h"
#include "EuropeanVanillaOption.h"
#include "CallOption.h"
#include "PutOption.h"
#include "BlackScholesPricer.h"

void testPayoffCallOption() {
    CallOption callOption(1.0, 100.0);
    double assetPrices[] = { 90.0, 100.0, 110.0 };
    for (double price : assetPrices)
    {
        double payoff = callOption.payoff(price);
        std::cout << "Payoff for asset price " << price << " is: " << payoff << std::endl;
    }
}

void testPayoffPutOption() {
    PutOption putOption(1.0, 100.0);
    double assetPrices[] = { 90.0, 100.0, 110.0 };
    for (double price : assetPrices)
    {
        double payoff = putOption.payoff(price);
        std::cout << "Payoff for asset price " << price << " is: " << payoff << std::endl;
    }
}

void testPrixAndDeltaCallOption() {
    // Paramètres de l'option
    double T = 1.0;    // Maturity : 1 year
    double K = 100.0;  // Strike price of 100 $
    double S0 = 105.0; // Spot price of 105 $ (Current price of the underlying asset)
    double r = 0.05;   // Risk-free interest rate of 5%
    double vol = 0.2;  // Volatility : 20% (volatility of the underlying asset)

    EuropeanVanillaOption* callOption = new CallOption(T, K);
    BlackScholesPricer pricer(callOption, S0, r, vol);
    double optionPrice = pricer();
    std::cout << "Prix de l'option Call: " << optionPrice << std::endl;
    double optionDelta = pricer.delta();
    std::cout << "Delta de l'option Call: " << optionDelta << std::endl;
    delete callOption;
}

void testPrixAndDeltaPutOption() {
    // Paramètres de l'option
    double T = 1.0;    // Maturity : 1 year
    double K = 100.0;  // Strike price of 100 $
    double S0 = 105.0; // Spot price of 105 $ (Current price of the underlying asset)
    double r = 0.05;   // Risk-free interest rate of 5%
    double vol = 0.2;  // Volatility : 20% (volatility of the underlying asset)

    EuropeanVanillaOption* putOption = new PutOption(T, K); // Create a Put option
    BlackScholesPricer pricer(putOption, S0, r, vol); // Create the Black-Scholes pricer
    double optionPrice = pricer(); // Calculate the price of the Put option
    std::cout << "Put Option Price: " << optionPrice << std::endl;
    double optionDelta = pricer.delta(); // Calculate the delta of the Put option 
    std::cout << "Put Option Delta: " << optionDelta << std::endl;
    delete putOption; //Clean up memory
}


int main() {

    testPrixAndDeltaCallOption();


    return 0;
}




// Paramètres de l'option
//double T = 5.0;    // Maturity : 5 year (time to expiration)
//double K = 101.0;  // Strike price of 101 $ (price at which the option holder can buy or sell the underlying asset)
//double S0 = 100.0; // Spot price of 100 $ (Current price of the underlying asset)
//double r = 0.01;   // Risk-free interest rate of 1% (annual)
//double vol = 0.1;  // Volatility : 10% (volatility of the underlying asset)
//EuropeanVanillaOption* putOption = new PutOption(T, K); // Create a Put option
//BlackScholesPricer pricer(putOption, S0, r, vol); // Create the Black-Scholes pricer
//double optionPrice = pricer(); // Calculate the price of the Put option
//std::cout << "Put Option Price: " << optionPrice << std::endl;
//double optionDelta = pricer.delta(); // Calculate the delta of the Put option 
//std::cout << "Put Option Delta: " << optionDelta << std::endl;
//delete putOption; //Clean up memory






// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
