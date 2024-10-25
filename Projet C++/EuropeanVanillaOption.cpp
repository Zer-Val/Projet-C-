#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H

#include "Options.h" // Assurez-vous que le chemin est correct
#include <stdexcept> // Pour std::invalid_argument

class EuropeanVanillaOption : public Option {
public:
    enum class OptionType { Call, Put };

    EuropeanVanillaOption(double expiry, double strike);
    virtual ~EuropeanVanillaOption() {}

    virtual OptionType GetOptionType() const = 0; // Méthode virtuelle pure

    double getStrike() const;
    double getExpiry() const;

private:
    double _strike;
};

#endif // EUROPEANVANILLAOPTION_H