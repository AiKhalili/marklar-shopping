#include <iostream>
#include <stdexcept>
#include "currency.hpp"

using namespace std;

Currency::Currency(double amount)
{
    if (amount < 0.0)
    {
        throw invalid_argument("Currency amount cannot be negative!");
    }
    this->amount = amount;
}

double Currency::getAmount() const
{
    return this->amount;
}

Currency &Currency::operator+(const Currency &other)
{ // sum two numbers with currency conversion applied to the first number.
    double result = this->convertToUSD() + other.convertToUSD();
    this->amount = this->revertFromUSD(result);

    return (*this);
}

Currency &Currency::operator-(const Currency &other)
{ // convert both number to USD then substract(operation in first one).
    if (other.amount < 0)
    {
        throw std::invalid_argument("Negative result in currency subtraction!");
    }
    double result = this->convertToUSD() - other.convertToUSD();
    this->amount = this->revertFromUSD(result);
    return (*this);
}

Currency &Currency::operator*(double other)
{ // currency multiplied by a number.
    amount *= other;
    return (*this);
}

Currency &Currency::operator/(double other)
{ // currency divided by a number.
    if (other == 0)
    {
        throw std::invalid_argument("Division by zero in currency!");
    }
    amount /= other;
    return (*this);
}

bool Currency::operator==(const Currency &other) const
{
    return amount == other.convertToUSD();
}

bool Currency::operator!=(const Currency &other) const
{
    return !(*this == other);
}

bool Currency::operator<(const Currency &other) const
{
    return amount < other.convertToUSD();
}

bool Currency::operator>(const Currency &other) const
{
    return (other < *this);
}