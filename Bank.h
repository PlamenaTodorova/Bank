#ifndef BANK_H
#define BANK_H

#include "Vector.h"
#include "String.h"
#include "Customer.h"
#include "Account.h"

enum AccountType{CURRENT_ACCOUNT = 1, SAVINGS_ACCOUNTS = 2, PRIVILEGE_ACCOUNT = 3};

class Bank
{
public:
	Bank(const String& name, const String& address);
	~Bank();

	const String& GetName() const { return name; }
	const String& GetAddres() const { return address; }

	void AddCustomer(int customerId, const String& name, const String& address);
	void ListCustomers() const;
	void DeleteCustomer(int customerId);
	
	void AddAccount(AccountType type, const String& iban, int ownerId, double amount);
	void DeleteAccount(const String& iban);
	void ListAccounts() const;

	void ListCustomerAccount(int ownerId) const;
	void Transfer(const String& sender, const String& receiver, double amount);
	void Withdraw(const String& iban, double amount);
	void Deposit(const String& iban, double amount);
	void Display() const;

private:
	enum { NO_MATCH_FOUND = -1 };
	String name;
	String address;
	Vector<Customer> customers;
	Vector<Account*> accounts;

	//Helper functios
	Vector<Account*> AccountsOwnedByCustomer(int customerId) const;
	int FindAccount(const String& iban) const;
	bool CustomerExist(int id) const;
};

#endif // !BANK_H
