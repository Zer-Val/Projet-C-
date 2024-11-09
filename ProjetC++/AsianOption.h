#pragma once
#include "Option.h"
#include <vector>

#ifndef ASIANOPTION_H
#define ASIANOPTION_H

class AsianOption : public Option {
public:
    // Constructeur qui initialise _expiry et _timeSteps
    AsianOption(double expiry, const std::vector<double>& timeSteps);

    // Getter pour _timeSteps
    const std::vector<double>& getTimeSteps() const;

    // Override de la m�thode payoffPath
    double payoffPath(const std::vector<double>& prices) const override;

    // Override de la m�thode isAsianOption
    bool isAsianOption() const override;

private:
    std::vector<double> _timeSteps; // Membre priv� pour les �tapes de temps
};

#endif // ASIANOPTION_H