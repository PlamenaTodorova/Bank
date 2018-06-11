#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
#include "String.h"

class Account
{
public:
	Account(const String& iban, int ownerId, double amount);
	virtual ~Account() {};

	double GetBalance() const { return amount; }
	bool IsAccountWith(int ownerId) const { return ownerId == this->ownerId; }
	bool IsAccountWith(const String& iban) const { return (iban == this->iban); }

	//Virtual functions
	virtual void Deposit(double amount) = 0;
	virtual bool Withdraw(double amount) = 0;
	virtual void Display() const = 0;

protected:
	bool Withdraw(double amount, double overdraft);

private:
	String iban;
	int ownerId;
	double amount;

	void Draw(double amount);
	void SetAmount(double amount);
};


#endif // !ACCOUNT_H

