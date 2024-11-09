#include "AsianOption.h"

// Constructeur qui initialise _expiry et _timeSteps
AsianOption::AsianOption(double expiry, const std::vector<double>& timeSteps)
    : Option(expiry), _timeSteps(timeSteps) {}

// Getter pour _timeSteps
const std::vector<double>& AsianOption::getTimeSteps() const {
    return _timeSteps;
}

// Override de la méthode payoffPath
double AsianOption::payoffPath(const std::vector<double>& prices) const {
    double sum = 0.0;
    for (double price : prices) {
        sum += price;
    }
    double averagePrice = sum / prices.size();
    return payoff(averagePrice);
}

// Override de la méthode isAsianOption
bool AsianOption::isAsianOption() const {
    return true;
}