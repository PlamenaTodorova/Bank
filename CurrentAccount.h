#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H

#include "Account.h"

class CurrentAccount :
	public Account
{
public:
	CurrentAccount(const String& iban, int ownerId, double amount);

	//Overriding the inherited functions
	virtual void Deposit(double amount);
	virtual bool Withdraw(double amount);
	virtual void Display() const;
};


#endif // !CURRENT_ACCOUNT_H

