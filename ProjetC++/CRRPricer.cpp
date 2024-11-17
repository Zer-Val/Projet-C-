#include "CRRPricer.h"
#include <cmath>

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate)
    : option(option), N(depth), S0(asset_price), U(up), D(down), R(interest_rate), q((1 + R - D) / (U - D)) {
    if (U <= D || R <= -1) {
        throw std::invalid_argument("Arbitrage condition violated.");
    }
    if (option->isAsianOption()) {
        throw std::invalid_argument("Asian options are not supported by this CRRPricer.");
    }
    tree.setDepth(N + 1); // Initialiser la profondeur de l'arbre
}

void CRRPricer::compute() {
    for (int i = 0; i <= N; ++i) {
        tree.setNode(N, i, option->payoff(S0 * std::pow(U, i) * std::pow(D, N - i)));
    }
    for (int n = N - 1; n >= 0; --n) {
        for (int i = 0; i <= n; ++i) {
            double value = (q * tree.getNode(n + 1, i + 1) + (1 - q) * tree.getNode(n + 1, i)) / (1 + R);
            tree.setNode(n, i, value);
        }
    }
}

double CRRPricer::get(int n, int i) const {
    if (n < 0 || n > N || i < 0 || i > n) {
        throw std::out_of_range("Invalid indices.");
    }
    return tree.getNode(n, i);
}

double CRRPricer::operator()(bool closed_form) {
    if (closed_form) {
        return closedForm();
    }
    else {
        compute();
        return tree.getNode(0, 0);
    }
}

double CRRPricer::closedForm() const {
    double result = 0.0;
    for (int i = 0; i <= N; ++i) {
        result += binomialCoefficient(N, i) * std::pow(q, i) * std::pow(1 - q, N - i) * option->payoff(S0 * std::pow(U, i) * std::pow(D, N - i));
    }
    return result / std::pow(1 + R, N);
}

double CRRPricer::binomialCoefficient(int n, int k) {
    double result = 1.0;
    for (int i = 1; i <= k; ++i) {
        result *= (n - i + 1) / static_cast<double>(i);
    }
    return result;
}
