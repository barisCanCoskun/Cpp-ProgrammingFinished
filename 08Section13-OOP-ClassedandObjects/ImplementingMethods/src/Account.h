#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include<string>

class Account
{
private:
    //attributes
	std::string name{"Account"};
	double balance{0.0};

public:
	//methods
    void set_balance(double );
    double get_balance();

    void set_name(std::string );
    std::string get_name();

	bool withdraw(double );
	bool deposit(double );
};

#endif  // _ACCOUNT_H_










 