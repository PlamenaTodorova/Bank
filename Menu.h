#ifndef MENU_H
#define MENU_H

#include "Bank.h"

class Menu
{
public:
	Menu(const Bank& bank);

	void PrintMenu() const;
	void CleanMenu() const;
	void RecogniseCommand(int command);

private:
	Bank bank;

	void AddCustomer();
	void DeleteCustomer();
	void DisplayCutomers() const;

	void AddAccount();
	void DeleteAccount();
	void DisplayAccounts() const;

	void DisplayAccountOfACustomer() const;

	void Transfer();
	void WithdrawFromAccount();
	void DepositToAccount();

	void DisplayBankInformation() const;

	void Quit();

	AccountType ReturnType(int num) const;
};

#endif // !MENU_H
