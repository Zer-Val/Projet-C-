#pragma once
#include "Options.h"
#include "BinaryTree.h"
#include <stdexcept>
#include <cmath>

class CRRPricer {
public:
    CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
    
    void compute();
    double get(int n, int i) const;
    double operator()(bool closed_form = false);

private:
    int _depth;
    double _asset_price;
    double _up;
    double _down;
    double _interest_rate;
    double _q;
    Option* _option;
    BinaryTree<double> _price_tree;
    BinaryTree<double> _value_tree;
    bool _computed;

    void check_arbitrage();
    double closed_form_formula() const;
};
