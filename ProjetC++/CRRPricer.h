#pragma once
#include "Option.h"
#include "BinaryTree.h"
#include <stdexcept>
#include <cmath>

// CRRPricer: Implements the Cox-Ross-Rubinstein pricing model for options
class CRRPricer 
{
    public:
        // Constructor to initialize the CRR model
        CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
	    // Constructor that initializes U, D et R
        CRRPricer(Option* option, int depth, double asset_price, double r, double volatility);


        void compute(); // Compute the price and value trees
        double get(int n, int i) const; // Retrieve the value at a specific tree node
        double operator()(bool closed_form = false); // Calculate option price using either closed-form or tree-based method
	    bool getExercice(int n, int i) const; // Retriev e the exercise decision at a specific tree node


    private:
        int _depth; // Depth of the binomial tree (N)
        double _asset_price; // Initial asset price (S0)
        double _up; // Up factor (U)
        double _down; // Down factor (D) 
        double _interest_rate; // Risk-free interest rate (R)
        double _q; // Risk-neutral probability
        Option* _option; // Pointer to the option being priced
        BinaryTree<double> _price_tree; // Tree structure for asset prices
        BinaryTree<double> _value_tree; // Tree structure for option values
        BinaryTree<bool> _exercise_tree; // Tree structure for exercise conditions, for the american options


        bool _computed; // Flag to indicate if the tree computation is complete

        void check_arbitrage(); // Check for arbitrage conditions
        double closed_form_formula() const; // Compute option price using closed-form formula
	    double binomialCoefficient(int n, int i) const; // Compute binomial coefficient (n choose i)
};
