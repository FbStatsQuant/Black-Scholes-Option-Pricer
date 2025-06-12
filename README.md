# Black-Scholes Option Pricer in C++

This project implements the **Black-Scholes model** for pricing **European call and put options** in C++, with full support for computing option **Greeks** (Delta, Gamma, Vega, Theta, Rho). The code is modular, object-oriented, and optimized for educational or interview use.

---

## 📌 Features

- European Call and Put Pricing
- Greeks: Delta, Gamma, Vega, Theta, Rho (both Call and Put)
- Inheritance-based design (`Option`, `EuropeanOption`)
- Command-line executable via `main.cpp`
- Clean mathematical implementation of the Black-Scholes formulas

---

## 📁 Files

| File              | Description                                |
|-------------------|--------------------------------------------|
| `main.cpp`        | Entry point – computes prices and Greeks   |
| `Option.h/.cpp`   | Abstract base class for options            |
| `EuropeanOption.h/.cpp` | Implements Black-Scholes for European options |
| `bs_pricing.exe`  | Precompiled executable (optional)          |

---

## 🧠 Model Formulas

The pricing formulas use the closed-form Black-Scholes expressions:

\[
\text{Call} = S \Phi(d_1) - K e^{-rT} \Phi(d_2)
\]
\[
\text{Put}  = K e^{-rT} \Phi(-d_2) - S \Phi(-d_1)
\]
With \( d_1, d_2 \) defined in standard form and \( \Phi \) as the standard normal CDF.

Greeks are derived analytically.

---

## ⚙️ How to Compile

Requires a C++20-compatible compiler (e.g., g++ ≥ 10.0)

```bash
g++ -std=c++20 -o bs_pricing main.cpp Option.cpp EuropeanOption.cpp
./bs_pricing
