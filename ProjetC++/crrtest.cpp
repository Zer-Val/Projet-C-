#include <iostream>
#include "CRRPricer.h"
#include "AmericanOption.h"

// Define a simple American Call option
class AmericanCallOption : public AmericanOption {
public:
    AmericanCallOption(double expiry, double strike)
        : AmericanOption(expiry, strike) {}

    // Return the intrinsic value payoff for a call option
    double payoff(double underlyingPrice) const override {
        return std::max(0.0, underlyingPrice - getStrike());
    }

    // Specify the type of option
    optionType GetOptionType() const override {
        return optionType::call;
    }
};

// Define a simple American Put option
class AmericanPutOption : public AmericanOption {
public:
    AmericanPutOption(double expiry, double strike)
        : AmericanOption(expiry, strike) {}

    // Return the intrinsic value payoff for a put option
    double payoff(double underlyingPrice) const override {
        return std::max(0.0, getStrike() - underlyingPrice);
    }

    // Specify the type of option
    optionType GetOptionType() const override {
        return optionType::put;
    }
};

// Test function
int main() {
    try {
        // Define parameters for the CRR model
        int depth = 3;                   // Depth of the binomial tree
        double asset_price = 100.0;      // Initial asset price
        double up = 1.2;                 // Up factor
        double down = 0.8;               // Down factor
        double interest_rate = 0.05;     // Risk-free interest rate
        double strike_price = 105.0;     // Strike price of the option

        // Create an American Call Option
        AmericanCallOption callOption(1.0, strike_price);

        // Create the CRRPricer instance for the call option
        CRRPricer pricer(&callOption, depth, asset_price, up, down, interest_rate);

        // Compute the option price using the tree method
        pricer.compute();
        double option_price = pricer();

        // Display the option price
        std::cout << "American Call Option Price: " << option_price << std::endl;

        // Display the exercise conditions
        std::cout << "Exercise Conditions (1: Exercise, 0: Hold):" << std::endl;
        for (int n = 0; n <= depth; ++n) {
            for (int i = 0; i <= n; ++i) {
                std::cout << pricer.getExercise(n, i) << " ";
            }
            std::cout << std::endl;
        }

        // Create an American Put Option
        AmericanPutOption putOption(1.0, strike_price);

        // Create the CRRPricer instance for the put option
        CRRPricer putPricer(&putOption, depth, asset_price, up, down, interest_rate);

        // Compute the option price using the tree method
        putPricer.compute();
        double put_option_price = putPricer();

        // Display the option price
        std::cout << "\nAmerican Put Option Price: " << put_option_price << std::endl;

        // Display the exercise conditions
        std::cout << "Exercise Conditions for Put (1: Exercise, 0: Hold):" << std::endl;
        for (int n = 0; n <= depth; ++n) {
            for (int i = 0; i <= n; ++i) {
                std::cout << putPricer.getExercise(n, i) << " ";
            }
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
