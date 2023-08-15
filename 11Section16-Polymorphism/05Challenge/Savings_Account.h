#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include<iostream>
#include"Account.h"

class Savings_Account: public Account
{ 
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance  = 0.0;
    static constexpr double def_int_rate  = 0.0;
protected:
	double interest_rate;
public:
	virtual void print(std::ostream &os) const override;
    Savings_Account(std::string n = def_name, double bal = def_balance, double int_rate = def_int_rate);
	virtual bool deposit(double amount) override;
	virtual bool withdraw(double amount) override;
    virtual ~Savings_Account() = default;
};

#endif  // _SAVINGS_ACCOUNT_H_










 