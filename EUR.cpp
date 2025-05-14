#include <iostream>
#include "EUR.hpp"
#include "USD.hpp"
#include "IRR.hpp"

using namespace std;

EUR::EUR(double amount) : Currency(amount) {}

string EUR::getCode() const
{
    return "EUR";
}

double EUR::convertToUSD() const
{
    return amount * 1.1;
}

double EUR::revertFromUSD(double usd) const{
    return usd / 1.1;
}
