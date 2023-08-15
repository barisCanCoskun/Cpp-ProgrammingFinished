#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include<string>

class Account
{
friend std::ostream &operator<<(std::ostream &os, const Account&acc);   
protected:
	double balance;
public:
    Account();
    Account(double amount);
	bool deposit(double amount);
	bool withdraw(double amount);
};

#endif  // _ACCOUNT_H_










 