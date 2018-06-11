#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount :
	public Account
{
public:
	SavingsAccount(const String& iban, int ownerId, double amount);
	SavingsAccount(const String& iban, int ownerId, double amount, double interestRate);

	double GetInterestRate() const { return interestRate; }

	//Overriding the inherited functions
	virtual void Deposit(double amount);
	virtual bool Withdraw(double amount);
	virtual void Display() const;
private:
	double interestRate;

	void SetInterestRate(double interestRate);
};

#endif // !SAVINGS_ACCOUNT_H
