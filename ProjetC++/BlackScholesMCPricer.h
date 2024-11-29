#pragma once

#include "Option.h"
#include "MT.h"
#include <vector>
#include <cmath>
#include <stdexcept>

class BlackScholesMCPricer 
{
    public:
		// Constructor of the BlackScholesMCPricer class
        BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility);

		// Method to generate paths
        void generate(int nb_paths);

		// Operator () to price the option
        double operator()() const;

		// Method to compute the 95% confidence interval of theprice
        std::vector<double> confidenceInterval() const;

		// Method to get the number of paths generated sicne the beginning of the program
        int getNbPaths() const;

    private:
        Option* option; 
		double S0; // Underlying asset price
		double r; // Risk-free interest rate
		double sigma; // Volatility
        int nb_paths_generated; //the number of paths already generated since the beginning of the program
        double current_estimate;
};
