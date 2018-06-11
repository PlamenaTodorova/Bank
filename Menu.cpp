#include "Menu.h"

#include<iostream>
#include<exception>

#include "HelperFunctions.h"
#include "String.h"

Menu::Menu(const Bank & bank) : 
	bank(bank)
{
}

void Menu::PrintMenu() const
{
	std::cout << bank.GetName() << " list of available options: " << std::endl;
	std::cout << "1. List customers" << std::endl;
	std::cout << "2. Add new customer" << std::endl;
	std::cout << "3. Delete customer" << std::endl;
	std::cout << "4. List all accounts" << std::endl;
	std::cout << "5. List customer account" << std::endl;
	std::cout << "6. Add new account" << std::endl;
	std::cout << "7. Delete account" << std::endl;
	std::cout << "8. Withdraw from account" << std::endl;
	std::cout << "9. Deposit to account" << std::endl;
	std::cout << "10. Transfer" << std::endl;
	std::cout << "11. Display info for the bank" << std::endl;
	std::cout << "12. Quit" << std::endl;
	std::cout << "Enter a number (from 1 to 12): ";
}

void Menu::CleanMenu() const
{
	system("cls");
}

void Menu::RecogniseCommand(int command)
{
	switch (command)
	{
	case 1:
		DisplayCutomers();
		break;
	case 2:
		AddCustomer();
		break;
	case 3:
		DeleteCustomer();
		break;
	case 4:
		DisplayAccounts();
		break;
	case 5:
		DisplayAccountOfACustomer();
		break;
	case 6:
		AddAccount();
		break;
	case 7:
		DeleteAccount();
		break;
	case 8:
		WithdrawFromAccount();
		break;
	case 9:
		DepositToAccount();
		break;
	case 10:
		Transfer();
		break;
	case 11:
		DisplayBankInformation();
		break;
	case 12:
		Quit();
		break;
	default:
		throw std::exception("Command not recongnised.");
		break;
	}
}

void Menu::DisplayBankInformation() const
{
	bank.Display();
}

void Menu::Quit()
{
	std::exit(EXIT_SUCCESS);
}

AccountType Menu::ReturnType(int num) const
{
	switch (num)
	{
	case 1:
		return CURRENT_ACCOUNT;
		break;
	case 2:
		return SAVINGS_ACCOUNTS;
		break;
	case 3:
		return PRIVILEGE_ACCOUNT;
		break;
	default:
		throw std::exception("No such account type");
	}
}

void Menu::AddCustomer()
{
	std::cout << "Enter customer information:" << std::endl;
	std::cout << "Enter customer id or -1 to exit: ";

	//Inputing the data
	int id = ValidIntegerInput();

	//Check if it is a return command
	if (id == -1)
		return;

	String name, address;

	std::cout << "Enter customer's name: ";
	std::cin >> name;
	std::cout << "Enter customer's address: ";
	std::cin >> address;

	//Calling the method
	bank.AddCustomer(id, name, address);
}

void Menu::DeleteCustomer()
{
	std::cout << "Enter customer id ot -1 to return to menu: ";

	int input = ValidIntegerInput();

	if (input == -1)
	{
		return;
	}
	
	bank.DeleteCustomer(input);
}

void Menu::DisplayCutomers() const
{
	bank.ListCustomers();
}

void Menu::AddAccount()
{
	std::cout << "Enter Account information:" << std::endl;
	
	int typeNum;
	
	std::cout << "Enter type(1 - Current account, 2 - Savings Account, 3 - Privilege Account, 0 to go back): ";
	typeNum = ValidIntegerInput();
	

	if (typeNum == 0)
		return;

	AccountType type = ReturnType(typeNum);

	std::cout << "Enter IBAN: ";
	String iban;
	std::cin >> iban;

	std::cout << "Enter owner's id: ";

	int id = ValidIntegerInput();

	std::cout << "Enter amount: ";
	double amount = ValidDoubleInput();

	bank.AddAccount(type, iban, id, amount);
}

void Menu::DeleteAccount()
{
	std::cout << "Enter IBAN:";
	String iban;
	std::cin >> iban;

	bank.DeleteAccount(iban);
}

void Menu::DisplayAccounts() const
{
	bank.ListAccounts();
}

void Menu::DisplayAccountOfACustomer() const
{
	std::cout << "Enter customer id ot -1 to return to menu: ";

	int input = ValidIntegerInput();

	if (input == -1)
	{
		return;
	}

	bank.ListCustomerAccount(input);
}

void Menu::Transfer()
{
	String first, second;

	std::cout << "Enter first accoutn IBAN:";

	std::cin >> first;

	std::cout << "Enter second accoutn IBAN:";

	std::cin >> second;

	std::cout << "Enter amount to be transfared: ";

	double amount = ValidDoubleInput();

	bank.Transfer(first, second, amount);
}

void Menu::WithdrawFromAccount()
{
	String iban;
	std::cout << "Enter IBAN:";

	std::cin >> iban;

	std::cout << "Enter amount to be withdrown: ";

	double amount = ValidDoubleInput();

	bank.Withdraw(iban, amount);
}

void Menu::DepositToAccount()
{
	String iban;
	std::cout << "Enter IBAN:";

	std::cin >> iban;

	std::cout << "Enter amount to be withdrown: ";

	double amount = ValidDoubleInput();

	bank.Deposit(iban, amount);
}