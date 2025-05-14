#ifndef EUR_H
#define EUR_H

#include <iostream>
#include "currency.hpp"

class EUR : public Currency
{
public:
    EUR(double amount = 0.0);
    std::string getCode() const override;
    double convertToUSD() const override;
    double revertFromUSD(double) const;
};

#endif