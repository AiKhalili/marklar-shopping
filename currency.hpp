#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>

class Currency
{
protected:
    double amount;

public:
    Currency(double amount = 0.0);
    virtual ~Currency() = default;
    double getAmount() const;
    virtual std::string getCode() const = 0;
    virtual double revertFromUSD(double) const = 0;
    virtual double convertToUSD() const = 0;
    Currency &operator+(const Currency &);
    Currency &operator-(const Currency &);
    Currency &operator*(double);
    Currency &operator/(double);
    bool operator==(const Currency &) const;
    bool operator!=(const Currency &) const;
    bool operator>(const Currency &) const;
    bool operator<(const Currency &) const;
};

#endif