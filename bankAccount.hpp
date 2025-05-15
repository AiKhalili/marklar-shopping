#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include "currency.hpp"

enum class accountType
{
    PERSONAL,
    ORGANIZATIONAL
};

class BankAccount
{
private:
    std::string name;
    std::string accountNumber;
    accountType type;
    Currency* balance;
    double dailyTranferredUSD;

public:
    BankAccount(std::string, std::string, accountType, Currency *);
    double getDailyLimit() const;
    bool deposit(Currency *);
    bool withdraw(Currency *);
    double getBalance() const;
    std::string getCurrencyCode() const;
    void resetDailyTransfer();
};

#endif