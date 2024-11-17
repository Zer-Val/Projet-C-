#pragma once

#include "Option.h"
#include "MT.h"
#include <vector>
#include <cmath>
#include <stdexcept>

class BlackScholesMCPricer {
public:
    BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility);

    void generate(int nb_paths);
    double operator()() const;
    std::vector<double> confidenceInterval() const;
    int getNbPaths() const;

private:
    Option* option;
    double S0;
    double r;
    double sigma;
    int nb_paths_generated; //the number of paths already generated since the beginning of the program
    double current_estimate;
};