#ifndef USD_H
#define USD_H

#include <iostream>
#include "currency.hpp"

class USD : public Currency
{
public:
    USD(double amount);
    std::string getCode() const override;
    double convertToUSD() const override;
    double revertFromUSD(double) const;
};

#endif