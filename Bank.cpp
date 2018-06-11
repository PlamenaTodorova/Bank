#include "Bank.h"

#include<exception>

#include "HelperFunctions.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"

Bank::Bank(const String& name, const String& address) :
	name(name),
	address(address)
{
}

Bank::~Bank()
{
	for (int i = 0; i < accounts.Size(); i++)
	{
		delete accounts[i];
	}
}

void Bank::AddCustomer(int customerId, const String& name, const String& address)
{
	if (!CustomerExist(customerId))
	{
		customers.PushBack(Customer(customerId, name, address));
	}
	else
		throw std::exception("This id is already taken.");
}

void Bank::ListCustomers() const
{
	for (int i = 0; i < customers.Size(); i++)
	{
		customers[i].Display();
	}
}

void Bank::DeleteCustomer(int customerId)
{
	int index = -1;

	for (int i = 0; i < customers.Size(); i++)
	{
		if (customers[i].GetId() == customerId)
		{
			index = i;
			break;
		}
	}

	if (index >= 0)
	{
		customers.Erase(index);

		for (int i = 0; i < accounts.Size(); i++)
		{
			if (accounts[i]->IsAccountWith(customerId))
			{
				accounts.Erase(i);
			}
		}
	}
	else
		throw std::exception("There is no customer with this id.");
}

void Bank::AddAccount(AccountType type, const String& iban, int ownerId, double amount)
{
	double interestRate, overdraft;
	if (CustomerExist(ownerId) && FindAccount(iban) == NO_MATCH_FOUND)
	{
		switch (type)
		{
		case CURRENT_ACCOUNT:
			accounts.PushBack(new CurrentAccount(iban, ownerId, amount));
			break;
		case SAVINGS_ACCOUNTS:

			std::cout << "Enter interest rate: ";
			interestRate = ValidDoubleInput();

			accounts.PushBack(new SavingsAccount(iban, ownerId, amount, interestRate));
			break;
		case PRIVILEGE_ACCOUNT:

			std::cout << "Enter overdraft: ";
			overdraft = ValidDoubleInput();

			accounts.PushBack(new PrivilegeAccount(iban, ownerId, amount, overdraft));
			break;
		default:
			throw std::exception("The type doesn't match the available ones.");
			break;
		}
	}
	else
	{
		throw std::exception("Account could not be added becouse there is no owner with this id or the IBAN is already taken.");
	}
}

void Bank::DeleteAccount(const String& iban)
{
	int index = FindAccount(iban);

	if (index != NO_MATCH_FOUND)
	{
		accounts.Erase(index);
	}
	else
		throw std::exception("There is no account with this IBAN.");

}

void Bank::ListAccounts() const
{
	for (int i = 0; i < accounts.Size(); i++)
	{
		accounts[i]->Display();
	}
}

void Bank::ListCustomerAccount(int ownerId) const
{
	if (!CustomerExist(ownerId))
	{
		throw std::exception("No customer with this id.");
	}

	Vector<Account*> result = AccountsOwnedByCustomer(ownerId);

	for (int i = 0; i < result.Size(); i++)
	{
		result[i]->Display();
	}
}

void Bank::Transfer(const String& sender, const String& receiver, double amount)
{
	int senderIndex = FindAccount(sender);
	int receiverIndex = FindAccount(receiver);

	if (senderIndex == NO_MATCH_FOUND || receiverIndex == NO_MATCH_FOUND)
	{
		throw std::exception("One or both of the accounts could not be found.");
	}

	if (accounts[senderIndex]->Withdraw(amount))
	{
		accounts[receiverIndex]->Deposit(amount);
	}
	else
		throw std::exception("There was not enough money in the account to be transfered.");
}

void Bank::Withdraw(const String& iban, double amount)
{
	int index = FindAccount(iban);

	if (index != NO_MATCH_FOUND)
	{
		if (!accounts[index]->Withdraw(amount))
			throw std::exception("Not enough money in the account.");
	}
	else
		throw std::exception("Account not found.");
}

void Bank::Deposit(const String& iban, double amount)
{
	int index = FindAccount(iban);

	if (index != NO_MATCH_FOUND)
	{
		accounts[index]->Deposit(amount);
	}
	else
		throw std::exception("Account not found.");
}

void Bank::Display() const
{
	std::cout << "Bank: " << name << std::endl;
	std::cout << "Address: " << address << std::endl;

	for (int i = 0; i < customers.Size(); i++)
	{
		customers[i].Display();
		ListCustomerAccount(customers[i].GetId());
		std::cout << std::endl;
	}
}

Vector<Account*> Bank::AccountsOwnedByCustomer(int customerId) const
{
	Vector<Account*> result;

	for (int i = 0; i < accounts.Size(); i++)
	{
		if (accounts[i]->IsAccountWith(customerId))
			result.PushBack(accounts[i]);
	}

	return result;
}

int Bank::FindAccount(const String& iban) const
{
	for (int i = 0; i < accounts.Size(); i++)
	{
		if (accounts[i]->IsAccountWith(iban))
			return i;
	}

	return NO_MATCH_FOUND;
}

bool Bank::CustomerExist(int id) const
{
	for (int i = 0; i < customers.Size(); i++)
	{
		if (customers[i].GetId() == id)
			return true;
	}

	return false;
}