#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const String& iban, int ownerId, double amount)
	:SavingsAccount(iban, ownerId, amount, 2.3)
{
}

SavingsAccount::SavingsAccount(const String& iban, int ownerId, double amount, double interestRate)
	:Account(iban, ownerId, amount), interestRate(interestRate)
{
}

void SavingsAccount::Deposit(double amount)
{
	Account::Deposit(amount);
}

bool SavingsAccount::Withdraw(double amount)
{
	return Withdraw(amount);
}

void SavingsAccount::Display() const
{
	std::cout << "Saving Account with an interest rate: " << interestRate << std::endl;

	Account::Display();
}

void SavingsAccount::SetInterestRate(double interestRate)
{
	if (interestRate < 0)
		throw std::exception("An account could not be created with negative interest rate.");

	this->interestRate = interestRate;
}
