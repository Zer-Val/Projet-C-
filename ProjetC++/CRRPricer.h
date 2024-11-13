#include "BinaryTree.h"
#include <stdexcept>

#ifndef CRRPRICER_H
#define CRRPRICER_H

class Option {
public:
    virtual double payoff(double asset_price) const = 0;
};

class CRRPricer {
public:
    CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
    void compute();
    double get(int n, int i) const;
    double operator()(bool closed_form = false);

private:
    Option* option;
    int N;
    double S0, U, D, R;
    double q;
    BinaryTree<double> tree;

    double closedForm() const;
    static double binomialCoefficient(int n, int k);
};

#endif // CRRPRICER_H