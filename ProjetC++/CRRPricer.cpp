#include "CRRPricer.h"
#include <stdexcept> // For invalid_argument

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate)
    : _option(option), _depth(depth), _asset_price(asset_price), _up(up), _down(down), _interest_rate(interest_rate), _computed(false) {
    check_arbitrage();
    _q = (1 + _interest_rate - _down) / (_up - _down);
    _price_tree.setDepth(_depth);
    _value_tree.setDepth(_depth);
    _price_tree.setNode(0, 0, _asset_price);
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
        throw std::invalid_argument("Arbitrage opportunity detected: check up, down, and interest rate values.");
    }
}

void CRRPricer::compute() {
    if (_computed) return;

    for (int n = 1; n <= _depth; ++n) {
        for (int i = 0; i <= n; ++i) {
            double price = _price_tree.getNode(n - 1, i) * _up;
            if (i > 0) price = _price_tree.getNode(n - 1, i - 1) * _down;
            _price_tree.setNode(n, i, price);
        }
    }

    for (int i = 0; i <= _depth; ++i) {
        _value_tree.setNode(_depth, i, _option->payoff(_price_tree.getNode(_depth, i)));
    }

    for (int n = _depth - 1; n >= 0; --n) {
        for (int i = 0; i <= n; ++i) {
            double continuation_value = (_q * _value_tree.getNode(n + 1, i) + (1 - _q) * _value_tree.getNode(n + 1, i + 1)) / (1 + _interest_rate);
            _value_tree.setNode(n, i, continuation_value);
        }
    }

    _computed = true;
}

double CRRPricer::get(int n, int i) const {
    return _value_tree.getNode(n, i);
}

double CRRPricer::closed_form_formula() const {
    double result = 0.0;
    for (int i = 0; i <= _depth; ++i) {
        double probability = std::pow(_q, i) * std::pow(1 - _q, _depth - i);
        result += probability * _option->payoff(_price_tree.getNode(_depth, i));
    }
    return result / std::pow(1 + _interest_rate, _depth);
}
