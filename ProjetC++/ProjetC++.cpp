// Projet C++.cpp : Ce fichier contient la fonction 'main'. 
// L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include "Option.h"
#include "EuropeanVanillaOption.h"
#include "CallOption.h"
#include "PutOption.h"
#include "BlackScholesPricer.h"
#include "BinaryTree.h"
#include "EuropeanDigitalOption.h"
#include "EuropeanDigitalCallOption.h"
#include "EuropeanDigitalPutOption.h"


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


void testAffichagePyramide()
{
    BinaryTree<double> tree;

    tree.setDepth(11);

    tree.setNode(0, 0, 0);

    tree.setNode(1, 0, 20);
    tree.setNode(1, 1, 0);

    tree.setNode(2, 0, 40);
    tree.setNode(2, 1, 0);
    tree.setNode(2, 2, 80);

    tree.setNode(3, 0, 60);
    tree.setNode(3, 1, 0);
    tree.setNode(3, 2, 100);
    tree.setNode(3, 3, 0);

    tree.setNode(4, 0, 80);
    tree.setNode(4, 1, 0);
    tree.setNode(4, 2, 120);
    tree.setNode(4, 3, 0);
    tree.setNode(4, 4, 160);

    tree.setNode(5, 0, 100);
    tree.setNode(5, 1, 0);
    tree.setNode(5, 2, 140);
    tree.setNode(5, 3, 0);
    tree.setNode(5, 4, 180);
    tree.setNode(5, 5, 0);

    tree.setNode(6, 0, 120);
    tree.setNode(6, 1, 0);
    tree.setNode(6, 2, 160);
    tree.setNode(6, 3, 0);
    tree.setNode(6, 4, 200);
    tree.setNode(6, 5, 0);
    tree.setNode(6, 6, 240);

    tree.setNode(7, 0, 140);
    tree.setNode(7, 1, 0);
    tree.setNode(7, 2, 180);
    tree.setNode(7, 3, 0);
    tree.setNode(7, 4, 220);
    tree.setNode(7, 5, 0);
    tree.setNode(7, 6, 260);
    tree.setNode(7, 7, 0);

    tree.setNode(8, 0, 160);
    tree.setNode(8, 1, 0);
    tree.setNode(8, 2, 200);
    tree.setNode(8, 3, 0);
    tree.setNode(8, 4, 240);
    tree.setNode(8, 5, 0);
    tree.setNode(8, 6, 280);
    tree.setNode(8, 7, 0);
    tree.setNode(8, 8, 320);

    tree.setNode(9, 0, 180);
    tree.setNode(9, 1, 0);
    tree.setNode(9, 2, 220);
    tree.setNode(9, 3, 0);
    tree.setNode(9, 4, 260);
    tree.setNode(9, 5, 0);
    tree.setNode(9, 6, 300);
    tree.setNode(9, 7, 0);
    tree.setNode(9, 8, 340);
    tree.setNode(9, 9, 0);

    tree.setNode(10, 0, 200);
    tree.setNode(10, 1, 0);
    tree.setNode(10, 2, 240);
    tree.setNode(10, 3, 0);
    tree.setNode(10, 4, 280);
    tree.setNode(10, 5, 0);
    tree.setNode(10, 6, 320);
    tree.setNode(10, 7, 0);
    tree.setNode(10, 8, 360);
    tree.setNode(10, 9, 0);
    tree.setNode(10, 10, 400);

    tree.display();
}


void testPayoffDigitalCallOption()
{
    double strike = 100.0;
    double expiry = 1.0; // 1 an

    EuropeanDigitalCallOption callOption(strike, expiry);

    double assetPrice = 105.0; // Prix actuel de l'actif sous-jacent

    std::cout << "Prix de l'actif sous-jacent: " << assetPrice << std::endl;
    std::cout << "Prix d'exercice: " << strike << std::endl;
    std::cout << "Echéance: " << expiry << " an(s)" << std::endl;

    std::cout << "Payoff de l'option call digitale: " << callOption.payoff(assetPrice) << std::endl;

}

void testPayoffDigitalPutOption()
{
	double strike = 100.0;
	double expiry = 1.0; // 1 an

	EuropeanDigitalPutOption putOption(strike, expiry);

	double assetPrice = 95.0; // Prix actuel de l'actif sous-jacent

	std::cout << "Prix de l'actif sous-jacent: " << assetPrice << std::endl;
	std::cout << "Prix d'exercice: " << strike << std::endl;
	std::cout << "Echéance: " << expiry << " an(s)" << std::endl;

	std::cout << "Payoff de l'option put digitale: " << putOption.payoff(assetPrice) << std::endl;

}

void testPrixAndDeltaDigitalCallOption()
{
	// Paramètres de l'option
	double T = 1.0;    // Maturity : 1 year
	double K = 100.0;  // Strike price of 100 $
	double S0 = 105.0; // Spot price of 105 $ (Current price of the underlying asset)
	double r = 0.05;   // Risk-free interest rate of 5%
	double vol = 0.2;  // Volatility : 20% (volatility of the underlying asset)

	EuropeanDigitalOption* callOption = new EuropeanDigitalCallOption(K, T);
	BlackScholesPricer pricer(callOption, S0, r, vol);
	double optionPrice = pricer();
	std::cout << "Prix de l'option Call digitale: " << optionPrice << std::endl;
	double optionDelta = pricer.delta();
	std::cout << "Delta de l'option Call digitale: " << optionDelta << std::endl;
	delete callOption;
}

void testPrixAndDeltaDigitalPutOption()
{
	// Paramètres de l'option
	double T = 1.0;    // Maturity : 1 year
	double K = 100.0;  // Strike price of 100 $
	double S0 = 95.0; // Spot price of 95 $ (Current price of the underlying asset)
	double r = 0.05;   // Risk-free interest rate of 5%
	double vol = 0.2;  // Volatility : 20% (volatility of the underlying asset)

	EuropeanDigitalOption* putOption = new EuropeanDigitalPutOption(K, T);
	BlackScholesPricer pricer(putOption, S0, r, vol);
	double optionPrice = pricer();
	std::cout << "Prix de l'option Put digitale: " << optionPrice << std::endl;
	double optionDelta = pricer.delta();
	std::cout << "Delta de l'option Put digitale: " << optionDelta << std::endl;
	delete putOption;
}

int main() {
	
	//testPayoffDigitalCallOption();

	//testPayoffDigitalPutOption();

	//testPrixAndDeltaCallOption();
	
    //testPrixAndDeltaPutOption();

	testPrixAndDeltaDigitalCallOption();

	testPrixAndDeltaDigitalPutOption();

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
