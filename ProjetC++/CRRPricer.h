#include "BinaryTree.h"
#include "Option.h"
#include <stdexcept>

class CRRPricer {
public:
    CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
    void compute();
    double get(int n, int i) const;
    double operator()(bool closed_form = false);

private:
    Option* option;
    int N;
    double S0, U, D, R;
    double q;
    BinaryTree<double> tree;

    double closedForm() const;
    static double binomialCoefficient(int n, int k);
};
