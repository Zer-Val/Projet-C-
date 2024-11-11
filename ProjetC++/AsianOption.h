#pragma once
#include "Option.h"
#include <vector>

#ifndef ASIANOPTION_H
#define ASIANOPTION_H

class AsianOption : public Option {
public:
    // Constructeur qui initialise _expiry et _timeSteps
    AsianOption(const std::vector<double>& timeSteps);

    // Getter pour _timeSteps
    const std::vector<double>& getTimeSteps() const;

    // Override de la méthode payoffPath
    double payoffPath(const std::vector<double>& prices) const override;

    // Override de la méthode isAsianOption
    bool isAsianOption() const override;

private:
    std::vector<double> _timeSteps; // Membre privé pour les étapes de temps
};

#endif // ASIANOPTION_H
