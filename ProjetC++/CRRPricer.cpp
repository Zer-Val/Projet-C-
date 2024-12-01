#include "CRRPricer.h"

// Constructor to initialize the CRR model
CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate)
    : _option(option), _depth(depth), _asset_price(asset_price), _up(up), _down(down), _interest_rate(interest_rate), _computed(false) {
    check_arbitrage();
    _q = (1 + _interest_rate - _down) / (_up - _down);
    _price_tree.setDepth(_depth);
    _value_tree.setDepth(_depth);
    _exercise_tree.setDepth(_depth);
    _price_tree.setNode(0, 0, _asset_price);
}

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
        double intrinsic_value = _option->payoff(_price_tree.getNode(_depth, i));
        _value_tree.setNode(_depth, i, intrinsic_value);
        _exercise_tree.setNode(_depth, i, true); // Exercise at maturity
    }

    // Backpropagate values and calculate exercise conditions
    for (int n = _depth - 1; n >= 0; --n) {
        for (int i = 0; i <= n; ++i) {
            double continuation_value = (_q * _value_tree.getNode(n + 1, i) +
                                         (1 - _q) * _value_tree.getNode(n + 1, i + 1)) / (1 + _interest_rate);

            double intrinsic_value = _option->payoff(_price_tree.getNode(n, i));
            if (intrinsic_value >= continuation_value) {
                _value_tree.setNode(n, i, intrinsic_value);
                _exercise_tree.setNode(n, i, true); // Exercise if intrinsic value is greater
            } else {
                _value_tree.setNode(n, i, continuation_value);
                _exercise_tree.setNode(n, i, false); // Do not exercise otherwise
            }
        }
    }

    _computed = true;
}

double CRRPricer::get(int n, int i) const {
    return _value_tree.getNode(n, i);
}

bool CRRPricer::getExercise(int n, int i) const {
    return _exercise_tree.getNode(n, i);
}

double CRRPricer::operator()(bool closed_form) {
    if (closed_form) {
        return closed_form_formula();
    } else {
        if (!_computed) compute();
        return _value_tree.getNode(0, 0);
    }
}

void CRRPricer::check_arbitrage() {
    if (_down >= 1 + _interest_rate || _up <= 1 + _interest_rate) {
        throw std::invalid_argument("Arbitrage opportunity detected.");
    }
}

double CRRPricer::closed_form_formula() const {
    // Closed-form implementation (not applicable to American options)
    throw std::runtime_error("Closed-form formula is not available for American options.");
}
