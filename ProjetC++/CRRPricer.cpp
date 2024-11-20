#include "CRRPricer.h"
#include <stdexcept> // For invalid_argument exception handling

// Constructor to initialize the CRR model parameters and set up the price and value trees
CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate)
    : _option(option), _depth(depth), _asset_price(asset_price), _up(up), _down(down), _interest_rate(interest_rate), _computed(false) {
    check_arbitrage(); // Verify no arbitrage conditions
    _q = (1 + _interest_rate - _down) / (_up - _down); // Calculate risk-neutral probability
    _price_tree.setDepth(_depth); // Initialize price tree
    _value_tree.setDepth(_depth); // Initialize value tree
    _price_tree.setNode(0, 0, _asset_price); // Set initial asset price
}

// Calculate option price using either closed-form or tree-based method
double CRRPricer::operator()(bool closed_form) {
    if (closed_form) {
        return closed_form_formula(); // Use closed-form formula
    } else {
        if (!_computed) compute(); // Compute tree values if not already done
        return _value_tree.getNode(0, 0); // Return price at root of value tree
    }
}

// Check for arbitrage conditions in model parameters
void CRRPricer::check_arbitrage() {
    if (_down >= 1 + _interest_rate || _up <= 1 + _interest_rate) {
        throw std::invalid_argument("Arbitrage opportunity detected.");
    }
}

// Compute the price and value trees
void CRRPricer::compute() {
    if (_computed) return;

    // Build the price tree
    for (int n = 1; n <= _depth; ++n) {
        for (int i = 0; i <= n; ++i) {
            double price = _price_tree.getNode(n - 1, i) * _up;
            if (i > 0) price = _price_tree.getNode(n - 1, i - 1) * _down;
            _price_tree.setNode(n, i, price);
        }
    }

    // Populate the value tree at maturity
    for (int i = 0; i <= _depth; ++i) {
        _value_tree.setNode(_depth, i, _option->payoff(_price_tree.getNode(_depth, i)));
    }

    // Backpropagate values to earlier nodes
    for (int n = _depth - 1; n >= 0; --n) {
        for (int i = 0; i <= n; ++i) {
            double continuation_value = (_q * _value_tree.getNode(n + 1, i) +
                                         (1 - _q) * _value_tree.getNode(n + 1, i + 1)) / (1 + _interest_rate);
            _value_tree.setNode(n, i, continuation_value);
        }
    }

    _computed = true;
}

// Get the value of a specific node in the value tree
double CRRPricer::get(int n, int i) const {
    return _value_tree.getNode(n, i);
}

// Calculate option price using closed-form formula
double CRRPricer::closed_form_formula() const {
    double result = 0.0;
    for (int i = 0; i <= _depth; ++i) {
        double probability = std::pow(_q, i) * std::pow(1 - _q, _depth - i); // Probability of ending at node i
        result += probability * _option->payoff(_price_tree.getNode(_depth, i)); // Weighted payoff
    }
    return result / std::pow(1 + _interest_rate, _depth); // Discount to present value
}
