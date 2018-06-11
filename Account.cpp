#include "Account.h"
#include<iostream>

Account::Account(const String& iban, int ownerId, double amount) :
	iban(iban) ,
	ownerId(ownerId)
{
	SetAmount(amount);
}

void Account::Deposit(double amount)
{
	this->amount += amount;
}

bool Account::Withdraw(double amount)
{
	if (this->amount >= amount)
	{
		Draw(amount);
		return true;
	}
	
	return false;
}

void Account::Display() const
{
	std::cout << "	IBAN: " << iban << std::endl;
	std::cout << "	Owner's Id: " << ownerId << std::endl;
	std::cout << "	Balance: " << amount << std::endl;
}

bool Account::Withdraw(double amount, double overdraft)
{
	if (amount <= this->amount + overdraft)
	{
		Draw(amount);
		return true;
	}

	return false;
}

void Account::Draw(double amount)
{ 
	this->amount -= amount;
}

void Account::SetAmount(double amount)
{
	if (amount < 0)
		throw std::exception("An account could not be created with negative amount of money.");

	this->amount = amount;
}
