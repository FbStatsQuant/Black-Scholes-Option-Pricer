#ifndef EUROPEAN_OPTION_H
#define EUROPEAN_OPTION_H

#include "Option.h"

class EuropeanOption : public Option {
public:
    EuropeanOption(double S, double K, double r, double T, double sigma);

    double priceCall() const override;
    double pricePut() const override;

    // === Greeks (make these public)
    double delta(bool isCall) const;
    double gamma() const;
    double vega() const;
    double theta(bool isCall) const;
    double rho(bool isCall) const;

private:
    double norm_cdf(double x) const;
};

#endif
