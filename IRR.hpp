#ifndef IRR_H
#define IRR_H

#include <iostream>
#include <memory>
#include "currency.hpp"

class IRR : public Currency
{
public:
    IRR(double amount = 0.0);
    std::string getCode() const override;
    double convertToUSD() const override;
    double revertFromUSD(double) const;
};

#endif