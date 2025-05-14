#include <iostream>
#include "USD.hpp"
#include "IRR.hpp"
#include "EUR.hpp"

using namespace std;

USD::USD(double amount = 0.0) : Currency(amount) {}

string USD::getCode() const
{
    return "USD";
}

double USD::convertToUSD() const{
    return amount;
}

double USD::revertFromUSD(double usd) const{
    return usd;
}