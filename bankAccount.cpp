#include <iostream>
#include "bankAccount.hpp"

using namespace std;

BankAccount::BankAccount(string Name, string Number, accountType Type, Currency *Balance)
    : name(Name), accountNumber(Number), type(Type),
      balance(Balance), dailyTranferredUSD(0) {}

double BankAccount::getDailyLimit() const
{
    if (type == accountType::PERSONAL)
    {
        return 1000.0;
    }
    return 10000.0;
}

bool BankAccount::deposit(Currency *amount)
{
    double usd = amount->convertToUSD();
    if (dailyTranferredUSD + usd > getDailyLimit())
    {
        return false;
    }
    *balance = *balance + *amount;
    dailyTranferredUSD += usd;
    return true;
}

bool BankAccount::withdraw(Currency *amount)
{
    double usd = amount->convertToUSD();
    if (dailyTranferredUSD + usd > getDailyLimit())
    {
        return false;
    }
    if (*balance < *amount)
    {
        return false;
    }
    *balance = *balance - *amount;
    dailyTranferredUSD += usd;
    return true;
}

double BankAccount::getBalance() const
{
    return balance->getAmount();
}

string BankAccount::getCurrencyCode() const
{
    return balance->getCode();
}

string BankAccount::getName() const{
    return name;
}