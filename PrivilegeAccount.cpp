#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount(const String& iban, int ownerId, double amount) :
	PrivilegeAccount(iban, ownerId, amount, 2000)
{
}

PrivilegeAccount::PrivilegeAccount(const String& iban, int ownerId, double amount, double overdraft) :
	Account(iban, ownerId, amount),
	overdraft(overdraft)
{
}

void PrivilegeAccount::Deposit(double amount)
{
	Account::Deposit(amount);
}

bool PrivilegeAccount::Withdraw(double amount)
{
	return Account::Withdraw(amount, overdraft);
}

void PrivilegeAccount::Display() const
{
	std::cout << "Privilege Account with an overdraft: " << overdraft << std::endl;

	Account::Display();
}

void PrivilegeAccount::SetOverdragt(double overdraft)
{
	if (overdraft < 0)
		throw std::exception("An account could not be created with negative overdraft.");

	this->overdraft = overdraft;
}
