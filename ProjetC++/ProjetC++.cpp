// Projet C++.cpp : Ce fichier contient la fonction 'main'. 
// L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <vector>
#include "CallOption.h"
#include "PutOption.h"
#include "EuropeanDigitalCallOption.h"
#include "EuropeanDigitalPutOption.h"
#include "BlackScholesPricer.h"
#include "BlackScholesMCPricer.h"
#include "CRRPricer.h"
#include "BinaryTree.h"

#include "AsianCallOption.h"
#include "AsianPutOption.h"
#include "AmericanCallOption.h"
#include "AmericanPutOption.h"

void testPayoffEuropeanVanillaCallOption() 
{
    std::cout << " --------------------------------------------" << std::endl;
	std::cout << "| Payoff for an European Vanilla Call Option |" << std::endl;
	std::cout << " --------------------------------------------" << std::endl;
    CallOption callOption(1.0, 100.0);
    double assetPrices[] = { 90.0, 100.0, 110.0 };
    for (double price : assetPrices)
    {
        double payoff = callOption.payoff(price);
        std::cout << "Payoff for asset price " << price << " is: " << payoff << std::endl;
    }
	std::cout << std::endl;
}

void testPayoffEuropeanVanillaPutOption() 
{
    std::cout << " -------------------------------------------" << std::endl;
	std::cout << "| Payoff for an European Vanilla Put Option |" << std::endl;
    std::cout << " -------------------------------------------" << std::endl;
    PutOption putOption(1.0, 100.0);
    double assetPrices[] = { 90.0, 100.0, 110.0 };
    for (double price : assetPrices)
    {
        double payoff = putOption.payoff(price);
        std::cout << "Payoff for asset price " << price << " is: " << payoff << std::endl;
    }
    std::cout << std::endl;
}

void testBSPriceAndDeltaEuropeanVanillaCallOption() 
{
    std::cout << " ----------------------------------------------------" << std::endl;
	std::cout << "| Price and Delta of an European Vanilla Call option |" << std::endl;
    std::cout << " ----------------------------------------------------" << std::endl;
    // Paramètres de l'option
    double T = 5.0;    // Maturity : 1 year
    double K = 101.0;  // Strike price of 100 $
    double S0 = 100.0; // Spot price of 105 $ (Current price of the underlying asset)
    double r = 0.01;   // Risk-free interest rate of 5%
    double vol = 0.1;  // Volatility : 20% (volatility of the underlying asset)

    CallOption* callOption = new CallOption(T, K);
    BlackScholesPricer pricer(callOption, S0, r, vol);
    double optionPrice = pricer();
    std::cout << "Call Option Price: " << optionPrice << std::endl;
    double optionDelta = pricer.delta();
    std::cout << "Call Option Delta: " << optionDelta << std::endl;
    std::cout << std::endl;
    delete callOption;
}

void testBSPriceAndDeltaEuropeanVanillaPutOption() 
{
    std::cout << " ---------------------------------------------------" << std::endl;
	std::cout << "| Price and Delta of an European Vanilla Put option |" << std::endl;
    std::cout << " ---------------------------------------------------" << std::endl;
    // Paramètres de l'option
    double T = 5.0;    // Maturity : 1 year
    double K = 101.0;  // Strike price of 100 $
    double S0 = 100.0; // Spot price of 105 $ (Current price of the underlying asset)
    double r = 0.01;   // Risk-free interest rate of 5%
    double vol = 0.1;  // Volatility : 20% (volatility of the underlying asset)

    PutOption* putOption = new PutOption(T, K); // Create a Put option
    BlackScholesPricer pricer(putOption, S0, r, vol); // Create the Black-Scholes pricer
    double optionPrice = pricer(); // Calculate the price of the Put option
    std::cout << "Put Option Price: " << optionPrice << std::endl;
    double optionDelta = pricer.delta(); // Calculate the delta of the Put option 
    std::cout << "Put Option Delta: " << optionDelta << std::endl;
	std::cout << std::endl;
    delete putOption; //Clean up memory
}


void testBTDisplay()
{
    std::cout << " ----------------------------------" << std::endl;
	std::cout << "| Display of a planned Binary Tree |" << std::endl;
    std::cout << " ----------------------------------" << std::endl;
    
    BinaryTree<double> tree;
    tree.setDepth(10);

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
	std::cout << std::endl;
}


void testPayoffEuropeanDigitalCallOption()
{
    std::cout << " --------------------------------------------" << std::endl;
    std::cout << "| Payoff for an European Digital Call Option |" << std::endl;
    std::cout << " --------------------------------------------" << std::endl;
    
    EuropeanDigitalCallOption digitalCallOption(1.0, 100.0);
    double assetPrices[] = {90.0, 100.0, 110.0 };
    for (double price : assetPrices)
    {
        double payoff = digitalCallOption.payoff(price);
        std::cout << "Payoff for asset price " << price << " is: " << payoff << std::endl;
    }
    std::cout << std::endl;
}

void testPayoffEuropeanDigitalPutOption()
{
    std::cout << " -------------------------------------------" << std::endl;
    std::cout << "| Payoff for an European Digital Put Option |" << std::endl;
    std::cout << " -------------------------------------------" << std::endl;

    EuropeanDigitalPutOption digitalPutOption(1.0, 100.0);
    double assetPrices[] = { 90.0, 100.0, 110.0 };
    for (double price : assetPrices) 
    {
        double payoff = digitalPutOption.payoff(price);
        std::cout << "Payoff for asset price " << price << " is: " << payoff << std::endl;
    }
    std::cout << std::endl;
}

void testPriceAndDeltaEuropeanDigitalCallOption()
{
    std::cout << " ----------------------------------------------------" << std::endl;
    std::cout << "| Price and Delta of an European Digital Call option |" << std::endl;
	std::cout << " ----------------------------------------------------" << std::endl;

	// Paramètres de l'option
    double T = 5.0;    // Maturity : 5 year
    double K = 101.0;  // Strike price of 101 $
    double S0 = 100.0; // Spot price of 100 $ (Current price of the underlying asset)
    double r = 0.01;   // Risk-free interest rate of 1%
    double vol = 0.1;  // Volatility : 10% (volatility of the underlying asset)

	EuropeanDigitalOption* callOption = new EuropeanDigitalCallOption(T, K);
	BlackScholesPricer pricer(callOption, S0, r, vol);

	double optionPrice = pricer();

	std::cout << "Prix de l'option Call digitale: " << optionPrice << std::endl;
	double optionDelta = pricer.delta();
	std::cout << "Delta de l'option Call digitale: " << optionDelta << std::endl;
	std::cout << std::endl;
	delete callOption;
}

void testPriceAndDeltaEuropeanDigitalPutOption()
{
    std::cout << " ---------------------------------------------------" << std::endl;
    std::cout << "| Price and Delta of an European Digital Put option |" << std::endl;
    std::cout << " ---------------------------------------------------" << std::endl;

	// Paramètres de l'option
    double T = 5.0;    // Maturity : 5 year
    double K = 101.0;  // Strike price of 101 $
    double S0 = 100.0; // Spot price of 100 $ (Current price of the underlying asset)
    double r = 0.01;   // Risk-free interest rate of 1%
    double vol = 0.1;  // Volatility : 10% (volatility of the underlying asset)

	EuropeanDigitalOption* putOption = new EuropeanDigitalPutOption(T, K);
	BlackScholesPricer pricer(putOption, S0, r, vol);
	double optionPrice = pricer();
	std::cout << "Prix de l'option Put digitale: " << optionPrice << std::endl;
	double optionDelta = pricer.delta();
	std::cout << "Delta de l'option Put digitale: " << optionDelta << std::endl;
	std::cout << std::endl;
	delete putOption;
}


void testCRRPriceEuropeanVanillaCallOption() {
    
    std::cout << " --------------------------------------------------------------" << std::endl;
    std::cout << "| Price of an European Vanilla Call Option with the CRR Pricer |" << std::endl;
    std::cout << " --------------------------------------------------------------" << std::endl;
    
    double expiry = 5.0;
    double strike = 101.0;
    int depth = 5;
    double asset_price = 100.0;
    double up = 0.05;
    double down = -0.045;
    double interest_rate = 0.01;

    CallOption callOption(expiry, strike);
    CRRPricer pricer(&callOption, depth, asset_price, up, down, interest_rate);

    // Calculate price using the CRR method
    double price = pricer();
    std::cout << "Option Price (CRR method): " << price << std::endl;

    // Calculate price using closed-form formula
    double closed_form_price = pricer(true);
    std::cout << "Option Price (Closed-form method): " << closed_form_price << std::endl;
	std::cout << std::endl;
}

void testCRRPricerEuropeanVanillaPutOption()
{
	std::cout << " -----------------------------------------------------" << std::endl;
	std::cout << "| Price of an European Put Option with the CRR Pricer |" << std::endl;
	std::cout << " -----------------------------------------------------" << std::endl;

    double expiry = 5.0;
    double strike = 101.0;
    int depth = 5;
    double asset_price = 100.0;
    double up = 0.05;
    double down = -0.045;
    double interest_rate = 0.01;

	PutOption putOption(expiry, strike);
	CRRPricer pricer(&putOption, depth, asset_price, up, down, interest_rate);

	// Calculate price using the CRR method
	double price = pricer();
	std::cout << "Option Price (CRR method): " << price << std::endl;

	// Calculate price using closed-form formula
	double closed_form_price = pricer(true);
	std::cout << "Option Price (Closed-form method): " << closed_form_price << std::endl;
	std::cout << std::endl;
}

void testCRRPricerEuropeanDigitalCallOption()
{
    std::cout << " --------------------------------------------------------------" << std::endl;
    std::cout << "| Price of an European Digital Call Option with the CRR Pricer |" << std::endl;
    std::cout << " --------------------------------------------------------------" << std::endl;

    double expiry = 5.0;
    double strike = 101.0;
    int depth = 5;
    double asset_price = 100.0;
    double up = 0.05;
    double down = -0.045;
    double interest_rate = 0.01;

    EuropeanDigitalCallOption EuropeanDigitalCallOption(expiry, strike);
    CRRPricer pricer(&EuropeanDigitalCallOption, depth, asset_price, up, down, interest_rate);

    // Calculate price using the CRR method
    double price = pricer();
    std::cout << "Option Price (CRR method): " << price << std::endl;

    // Calculate price using closed-form formula
    double closed_form_price = pricer(true);
    std::cout << "Option Price (Closed-form method): " << closed_form_price << std::endl;
    std::cout << std::endl;

}

void testCRRPricerEuropeanDigitalPutOption()
{
    std::cout << " -------------------------------------------------------------" << std::endl;
    std::cout << "| Price of an European Digital Put Option with the CRR Pricer |" << std::endl;
    std::cout << " -------------------------------------------------------------" << std::endl;

    double expiry = 5.0;
    double strike = 101.0;
    int depth = 5;
    double asset_price = 100.0;
    double up = 0.05;
    double down = -0.045;
    double interest_rate = 0.01;

    EuropeanDigitalPutOption EuropeanDigitalPutOption(expiry, strike);
    CRRPricer pricer(&EuropeanDigitalPutOption, depth, asset_price, up, down, interest_rate);

    // Calculate price using the CRR method
    double price = pricer();
    std::cout << "Option Price (CRR method): " << price << std::endl;

    // Calculate price using closed-form formula
    double closed_form_price = pricer(true);
    std::cout << "Option Price (Closed-form method): " << closed_form_price << std::endl;
    std::cout << std::endl;
}

void testCRRPricerAmericanCallOption()
{
	std::cout << " ------------------------------------------------------" << std::endl;
	std::cout << "| Price of an American Call Option with the CRR Pricer |" << std::endl;
	std::cout << " ------------------------------------------------------" << std::endl;

    double expiry = 5.0;
    double strike = 101.0;
    int depth = 5;
    double asset_price = 100.0;
    double up = 0.05;
    double down = -0.045;
    double interest_rate = 0.01;

	AmericanCallOption americanCallOption(expiry, strike);
	CRRPricer pricer(&americanCallOption, depth, asset_price, up, down, interest_rate);

	// Calculate price using the CRR method
	double price = pricer();
	std::cout << "Option Price (CRR method): " << price << std::endl;

	// Calculate price using closed-form formula
	double closed_form_price = pricer(true);
	std::cout << "Option Price (Closed-form method): " << closed_form_price << std::endl;
	std::cout << std::endl;

}

void testCRRPricerAmericanPutOption()
{
    std::cout << " -----------------------------------------------------" << std::endl;
    std::cout << "| Price of an American Put Option with the CRR Pricer |" << std::endl;
    std::cout << " -----------------------------------------------------" << std::endl;

    double expiry = 5.0;
    double strike = 99;
    int depth = 5;
    double asset_price = 100.0;
    double up = 0.05;
    double down = -0.045;
    double interest_rate = 0.01;

    AmericanPutOption americanPutOption(expiry, strike);
    CRRPricer pricer(&americanPutOption, depth, asset_price, up, down, interest_rate);

    // Calculate price using the CRR method
    double price = pricer();
    std::cout << "Option Price (CRR method): " << price << std::endl;

    // Calculate price using closed-form formula
    double closed_form_price = pricer(true);
    std::cout << "Option Price (Closed-form method): " << closed_form_price << std::endl;
    std::cout << std::endl;
}




void testBSMCPricerEuropeanVanillaCallOption()
{
    std::cout << " ---------------------------------------------------------------------------------" << std::endl;
    std::cout << "| Price with Black-Scholes Monte-Carlo pricer for an European Vanilla Call Option |" << std::endl;
    std::cout << " ---------------------------------------------------------------------------------" << std::endl;

	double expiry = 5.0;
	double strike = 101.0;
	double asset_price = 100.0;
	double interest_rate = 0.01;
	double volatility = 0.1;
	int nb_paths = 1000000;

	CallOption callOption(expiry, strike);
	BlackScholesMCPricer pricer(&callOption, asset_price, interest_rate, volatility);

	pricer.generate(nb_paths);
	double price = pricer();
	std::cout << "Option Price (MC method): " << price << std::endl;

	std::vector<double> confidence_interval = pricer.confidenceInterval();
	std::cout << "Confidence interval: [" << confidence_interval[0] << ", " << confidence_interval[1] << "]" << std::endl;
	std::cout << std::endl;
}

void testBSMCPricerEuropeanVanillaPutOption()
{
    std::cout << " --------------------------------------------------------------------------------" << std::endl;
    std::cout << "| Price with Black-Scholes Monte-Carlo pricer for an European Vanilla Put Option |" << std::endl;
    std::cout << " --------------------------------------------------------------------------------" << std::endl;
    
    double expiry = 5.0;
	double strike = 101.0;
	double asset_price = 100.0;
	double interest_rate = 0.01;
	double volatility = 0.1;
	int nb_paths = 1000000;

	PutOption putOption(expiry, strike);
	BlackScholesMCPricer pricer(&putOption, asset_price, interest_rate, volatility);

	pricer.generate(nb_paths);
	double price = pricer();
	std::cout << "Option Price (MC method): " << price << std::endl;

	std::vector<double> confidence_interval = pricer.confidenceInterval();
	std::cout << "Confidence interval: [" << confidence_interval[0] << ", " << confidence_interval[1] << "]" << std::endl;
	std::cout << std::endl;
}

void testBSMCPricerEuropeanDigitalCallOption()
{
    std::cout << " ---------------------------------------------------------------------------------" << std::endl;
    std::cout << "| Price with Black-Scholes Monte-Carlo pricer for an European Vanilla Call Option |" << std::endl;
    std::cout << " ---------------------------------------------------------------------------------" << std::endl;

    double expiry = 5.0;
    double strike = 101.0;
    double asset_price = 100.0;
    double interest_rate = 0.01;
    double volatility = 0.1;
    int nb_paths = 1000000;

    EuropeanDigitalCallOption europeanDigitalCallOption(expiry, strike);
    BlackScholesMCPricer pricer(&europeanDigitalCallOption, asset_price, interest_rate, volatility);

    pricer.generate(nb_paths);
    double price = pricer();
    std::cout << "Option Price (MC method): " << price << std::endl;

    std::vector<double> confidence_interval = pricer.confidenceInterval();
    std::cout << "Confidence interval: [" << confidence_interval[0] << ", " << confidence_interval[1] << "]" << std::endl;
    std::cout << std::endl;
}

void testBSMCPricerEuropeanDigitalPutOption()
{
    std::cout << " --------------------------------------------------------------------------------" << std::endl;
    std::cout << "| Price with Black-Scholes Monte-Carlo pricer for an European Vanilla Put Option |" << std::endl;
    std::cout << " --------------------------------------------------------------------------------" << std::endl;

    double expiry = 5.0;
    double strike = 101.0;
    double asset_price = 100.0;
    double interest_rate = 0.01;
    double volatility = 0.1;
    int nb_paths = 1000000;

    EuropeanDigitalPutOption europeanDigitalPutOption(expiry, strike);
    BlackScholesMCPricer pricer(&europeanDigitalPutOption, asset_price, interest_rate, volatility);

    pricer.generate(nb_paths);
    double price = pricer();
    std::cout << "Option Price (MC method): " << price << std::endl;

    std::vector<double> confidence_interval = pricer.confidenceInterval();
    std::cout << "Confidence interval: [" << confidence_interval[0] << ", " << confidence_interval[1] << "]" << std::endl;
    std::cout << std::endl;
}

void testBSMCPricerAsianCallOption()
{
	std::cout << " ---------------------------------------------------------------------------------" << std::endl;
	std::cout << "| Price with Black-Scholes Monte-Carlo pricer for an Asian Call Option |" << std::endl;
	std::cout << " ---------------------------------------------------------------------------------" << std::endl;


	double T = 5.0;
	double strike = 101.0;
	double asset_price = 100.0;
	double interest_rate = 0.01;
	double volatility = 0.1;
	int nb_paths = 1000000;

    int m = 50;
    std::vector<double> time_steps;
    double deltaT = T / m;
    for (int i = 1; i <= m; ++i)
    {
        time_steps.push_back(i * deltaT);
    }


	AsianCallOption asianCallOption(time_steps, strike);
	BlackScholesMCPricer pricer(&asianCallOption, asset_price, interest_rate, volatility);

	pricer.generate(nb_paths);
	double price = pricer();
	std::cout << "Option Price (MC method): " << price << std::endl;

	std::vector<double> confidence_interval = pricer.confidenceInterval();
	std::cout << "Confidence interval: [" << confidence_interval[0] << ", " << confidence_interval[1] << "]" << std::endl;
	std::cout << std::endl;

}




void test_prof_1()
{
    {

        double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
        CallOption opt1(T, K);
        PutOption opt2(T, K);


        std::cout << "European options 1" << std::endl << std::endl;

        {
            BlackScholesPricer pricer1(&opt1, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer1() << ", delta=" << pricer1.delta() << std::endl;

            BlackScholesPricer pricer2(&opt2, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer2() << ", delta=" << pricer2.delta() << std::endl;
            std::cout << std::endl;

            int N(150);
            double U = exp(sigma * sqrt(T / N)) - 1.0;
            double D = exp(-sigma * sqrt(T / N)) - 1.0;
            double R = exp(r * T / N) - 1.0;

            CRRPricer crr_pricer1(&opt1, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer1() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer1(true) << std::endl;
            std::cout << std::endl;

            CRRPricer crr_pricer2(&opt2, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer2() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer2(true) << std::endl;
        }
        std::cout << std::endl << "*********************************************************" << std::endl;
    }

    {
        std::cout << "Binary Tree" << std::endl << std::endl;
        BinaryTree<bool> t1;
        t1.setDepth(3);
        t1.setNode(1, 1, true);
        t1.display();
        t1.setDepth(5);
        t1.display();
        t1.setDepth(3);
        t1.display();


        BinaryTree<double> t2;
        t2.setDepth(2);
        t2.setNode(2, 1, 3.14);
        t2.display();
        t2.setDepth(4);
        t2.display();
        t2.setDepth(3);
        t2.display();

        BinaryTree<int> t3;
        t3.setDepth(4);
        t3.setNode(3, 0, 8);
        t3.display();
        t3.setDepth(2);
        t3.display();
        t3.setDepth(4);
        t3.display();

        std::cout << std::endl << "*********************************************************" << std::endl;
    }

    {

        double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
        EuropeanDigitalCallOption opt1(T, K);
        EuropeanDigitalPutOption opt2(T, K);


        std::cout << "European options 2" << std::endl << std::endl;

        {
            BlackScholesPricer pricer1(&opt1, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer1() << ", delta=" << pricer1.delta() << std::endl;

            BlackScholesPricer pricer2(&opt2, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer2() << ", delta=" << pricer2.delta() << std::endl;
            std::cout << std::endl;

            int N(150);
            double U = exp(sigma * sqrt(T / N)) - 1.0;
            double D = exp(-sigma * sqrt(T / N)) - 1.0;
            double R = exp(r * T / N) - 1.0;

            CRRPricer crr_pricer1(&opt1, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << crr_pricer1.get(1, 1);
            std::cout << "CRR pricer computed price=" << crr_pricer1() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer1(true) << std::endl;
            std::cout << std::endl;

            CRRPricer crr_pricer2(&opt2, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer2() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer2(true) << std::endl;
        }
        std::cout << std::endl << "*********************************************************" << std::endl;
    }
}

void test_prof_2()
{
    double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
    std::vector<Option*> opt_ptrs;
    opt_ptrs.push_back(new CallOption(T, K));
    opt_ptrs.push_back(new PutOption(T, K));
    opt_ptrs.push_back(new EuropeanDigitalCallOption(T, K));
    opt_ptrs.push_back(new EuropeanDigitalPutOption(T, K));

    std::vector<double> fixing_dates;
    for (int i = 1; i <= 5; i++) {
        fixing_dates.push_back(0.1 * i);
    }
    opt_ptrs.push_back(new AsianCallOption(fixing_dates, K));
    opt_ptrs.push_back(new AsianPutOption(fixing_dates, K));

    std::vector<double> ci;
    BlackScholesMCPricer* pricer;

    for (auto& opt_ptr : opt_ptrs) {
        pricer = new BlackScholesMCPricer(opt_ptr, S0, r, sigma);
        do {
            pricer->generate(10);
            ci = pricer->confidenceInterval();
        } while (ci[1] - ci[0] > 1e-2);
        std::cout << "nb samples: " << pricer->getNbPaths() << std::endl;
        std::cout << "price: " << (*pricer)() << std::endl << std::endl;
        delete pricer;
        delete opt_ptr;
    }
}

void test_prof_3()
{
    double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
    std::vector<Option*> opt_ptrs;
    opt_ptrs.push_back(new CallOption(T, K));
    opt_ptrs.push_back(new PutOption(T, K));
    opt_ptrs.push_back(new EuropeanDigitalCallOption(T, K));
    opt_ptrs.push_back(new EuropeanDigitalPutOption(T, K));
    opt_ptrs.push_back(new AmericanCallOption(T, K));
    opt_ptrs.push_back(new AmericanPutOption(T, K));

    CRRPricer* pricer;

    for (auto& opt_ptr : opt_ptrs) {
        pricer = new CRRPricer(opt_ptr, 150, S0, r, sigma);

        pricer->compute();

        std::cout << "price: " << (*pricer)() << std::endl << std::endl;
        delete pricer;
        delete opt_ptr;

    }

}


int main() {

	//testPayoffEuropeanVanillaCallOption();
	//testPayoffEuropeanVanillaPutOption();
	//testBSPriceAndDeltaEuropeanVanillaCallOption();
    //testBSPriceAndDeltaEuropeanVanillaPutOption();

    //testBTDisplay();

    //testPayoffEuropeanDigitalCallOption();
    //testPayoffEuropeanDigitalPutOption();
	//testPriceAndDeltaEuropeanDigitalCallOption();
	//testPriceAndDeltaEuropeanDigitalPutOption();

    //testCRRPriceEuropeanVanillaCallOption();
	//testCRRPricerEuropeanVanillaPutOption();
	//testCRRPricerEuropeanDigitalCallOption();
	//testCRRPricerEuropeanDigitalPutOption();
    //testCRRPricerAmericanCallOption();
    testCRRPricerAmericanPutOption(); //A REPRENDRE

	//testBSMCPricerEuropeanVanillaCallOption();
	//testBSMCPricerEuropeanVanillaPutOption();
	//testBSMCPricerEuropeanDigitalCallOption();
    //testBSMCPricerEuropeanDigitalPutOption();
	//testBSMCPricerAsianCallOption();

	//test_prof_1();
	//test_prof_2();
	//test_prof_3();

    return 0;
}


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

