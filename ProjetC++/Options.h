#ifndef OPTION_H
#define OPTION_H

class Option {
public:
    Option(double expiry) : _expiry(expiry) {}
    double getExpiry() const { return _expiry; }
    virtual double payoff(double underlyingPrice) const = 0;

private:
    double _expiry;
};

#endif // OPTION_H
