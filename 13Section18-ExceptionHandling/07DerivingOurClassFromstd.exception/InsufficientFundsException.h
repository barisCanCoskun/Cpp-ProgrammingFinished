#ifndef _INSUFFICIENTFUNDSEXCEPTION_H_
#define _INSUFFICIENTFUNDSEXCEPTION_H_

class InsufficientFundsException: public std::exception {
public:
    InsufficientFundsException() noexcept = default;	
	~InsufficientFundsException() = default;	
	virtual const char* what() const noexcept{
		return "Insufficient funds exception";
	}
};
#endif  // _INSUFFICIENTFUNDSEXCEPTION_H_










 