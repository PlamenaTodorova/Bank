#ifndef PRIVILEGE_ACCOUNT_H
#define PRIVILEGE_ACCOUNT_H

#include "Account.h"

class PrivilegeAccount :
	public Account
{
public:
	PrivilegeAccount(const String& iban, int ownerId, double amount);
	PrivilegeAccount(const String& iban, int ownerId, double amount, double overdrafr);

	double GetOverdraft() const { return overdraft; }

	//Overriding the inherited functions
	virtual void Deposit(double amount);
	virtual bool Withdraw(double amount);
	virtual void Display() const;

private:
	double overdraft;

	void SetOverdragt(double overdraft);
};

#endif // !PRIVILEGE_ACCOUNT_H

