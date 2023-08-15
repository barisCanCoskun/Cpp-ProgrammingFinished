#ifndef _SAVINGS_ACCOUNT_H_
#define _Savings__SAVINGS_ACCOUNT_H_ccount_H_

#include"Account.h"

class Savings_Account: public Account
{
friend std::ostream &operator<<(std::ostream &os, const Savings_Account&sav_acc);   
protected:
	double interest_rate;
public:
    Savings_Account();
    Savings_Account(double amount, double int_rate);
	bool deposit(double amount);
	// Withdraw is inherited
};

#endif  // _SAVINGS_ACCOUNT_H_










 