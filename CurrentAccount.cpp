#include "CurrentAccount.h"
#include<iostream>


CurrentAccount::CurrentAccount(const String& iban, int ownerId, double amount)
	:Account(iban, ownerId, amount)
{
}

void CurrentAccount::Deposit(double amount)
{
	Account::Deposit(amount);
}

bool CurrentAccount::Withdraw(double amount)
{
	return Account::Withdraw(amount);
}

void CurrentAccount::Display() const
{
	std::cout << "Current Account:" << std::endl;

	Account::Display();
}
