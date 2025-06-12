#include <iostream>
#include <iomanip>
#include "EuropeanOption.h"

int main() {
    EuropeanOption opt(100.0, 100.0, 0.05, 1.0, 0.2);  // ATM call/put

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "European Call Price: " << opt.priceCall() << std::endl;
    std::cout << "European Put Price:  " << opt.pricePut() << std::endl;

    std::cout << "\nGreeks (Call):" << std::endl;
    std::cout << "Delta: " << opt.delta(true) << std::endl;
    std::cout << "Gamma: " << opt.gamma() << std::endl;
    std::cout << "Vega : " << opt.vega() << std::endl;
    std::cout << "Theta: " << opt.theta(true) << std::endl;
    std::cout << "Rho  : " << opt.rho(true) << std::endl;

    std::cout << "\nGreeks (Put):" << std::endl;
    std::cout << "Delta: " << opt.delta(false) << std::endl;
    std::cout << "Gamma: " << opt.gamma() << std::endl;
    std::cout << "Vega : " << opt.vega() << std::endl;
    std::cout << "Theta: " << opt.theta(false) << std::endl;
    std::cout << "Rho  : " << opt.rho(false) << std::endl;

    return 0;
}


// g++ -std=c++20 -o bs_pricing main.cpp Option.cpp EuropeanOption.cpp
