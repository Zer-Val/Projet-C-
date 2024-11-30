#include "Option.h"
#include <iostream>

// Implementation of the constructor that initialize _expiry
Option::Option(double expiry) : _expiry(expiry) {}

// Implementation of the getter method for _expiry
double Option::getExpiry() const 
{
    return _expiry;
}

// Implementation of the method payoffPath that calls the method payoff(double) with the last element of the vector
double Option::payoffPath(const std::vector<double>& prices) const 
{
	return payoff(prices.back()); // Call the payoff method with the last element of the vector
}

// Implementation of the virtual method to check if the option is an Asian Option
bool Option::isAsianOption() const 
{
    return false;
}

// Implementation of the virtual method to check if the option is an American Option
bool Option::isAmericanOption() const 
{
	return false;
}
