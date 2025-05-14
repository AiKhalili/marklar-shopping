#include <iostream>
#include "EUR.hpp"
#include "USD.hpp"
#include "IRR.hpp"

using namespace std;

IRR::IRR(double amount) : Currency(amount) {}

string IRR::getCode() const
{
    return "IRR";
}

double IRR::convertToUSD() const
{
    return amount * 50000.0;
}

double IRR::revertFromUSD(double usd) const
{
    return usd / 50000.0;
}