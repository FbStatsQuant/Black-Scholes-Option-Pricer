#include "EuropeanOption.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

EuropeanOption::EuropeanOption(double S, double K, double r, double T, double sigma)
    : Option(S, K, r, T, sigma) {}

double EuropeanOption::norm_cdf(double x) const {
    return 0.5 * std::erfc(-x / std::sqrt(2));
}

double EuropeanOption::priceCall() const {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    return S * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
}

double EuropeanOption::pricePut() const {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    return K * std::exp(-r * T) * norm_cdf(-d2) - S * norm_cdf(-d1);
}

double EuropeanOption::delta(bool isCall) const {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    return isCall ? norm_cdf(d1) : norm_cdf(d1) - 1;
}

double EuropeanOption::gamma() const {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double pdf = std::exp(-0.5 * d1 * d1) / std::sqrt(2 * M_PI);
    return pdf / (S * sigma * std::sqrt(T));
}

double EuropeanOption::vega() const {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double pdf = std::exp(-0.5 * d1 * d1) / std::sqrt(2 * M_PI);
    return S * pdf * std::sqrt(T);
}

double EuropeanOption::theta(bool isCall) const {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    double pdf = std::exp(-0.5 * d1 * d1) / std::sqrt(2 * M_PI);

    double firstTerm = - (S * pdf * sigma) / (2 * std::sqrt(T));
    double secondTerm = r * K * std::exp(-r * T) * (isCall ? norm_cdf(d2) : norm_cdf(-d2));
    return firstTerm - secondTerm;
}

double EuropeanOption::rho(bool isCall) const {
    double d2 = (std::log(S / K) + (r - 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double factor = K * T * std::exp(-r * T);
    return isCall ? factor * norm_cdf(d2) : -factor * norm_cdf(-d2);
}

