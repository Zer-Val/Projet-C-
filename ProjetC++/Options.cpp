#include "Options.h"
#include <iostream>

// Constructor initializing _expiry
Option::Option(double expiry) : _expiry(expiry) {}

// Get method for _expiry
double Option::getExpiry() const {
    return _expiry;
}