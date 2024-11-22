#include <iostream>
#include "CRRPricer.h"

// Simple European call option as an example
class EuropeanCallOption : public Option {
public:
    EuropeanCallOption(double expiry, double strike) : Option(expiry), _strike(strike) {}

    double payoff(double underlyingPrice) const override {
        return std::max(0.0, underlyingPrice - _strike);
    }

private:
    double _strike;
};

int main() {
    double expiry = 1.0;
    double strike = 100.0;
    int depth = 3;
    double asset_price = 100.0;
    double up = 1.1;
    double down = 0.9;
    double interest_rate = 0.05;

    EuropeanCallOption callOption(expiry, strike);
    CRRPricer pricer(&callOption, depth, asset_price, up, down, interest_rate);

    // Calculate price using the CRR method
    double price = pricer();
    std::cout << "Option Price (CRR method): " << price << std::endl;

    // Calculate price using closed-form formula
    double closed_form_price = pricer(true);
    std::cout << "Option Price (Closed-form method): " << closed_form_price << std::endl;

    return 0;
}
