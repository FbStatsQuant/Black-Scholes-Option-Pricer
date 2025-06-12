#ifndef OPTION_H
#define OPTION_H

class Option {
protected:
    double S;      // Underlying price
    double K;      // Strike price
    double r;      // Risk-free rate
    double T;      // Time to maturity
    double sigma;  // Volatility

public:
    Option(double S, double K, double r, double T, double sigma);
    virtual ~Option() {}

    virtual double priceCall() const = 0;
    virtual double pricePut() const = 0;
};

#endif
