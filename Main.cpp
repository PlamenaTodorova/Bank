#include<iostream>

#include "String.h"
#include "Bank.h"
#include "Menu.h"
#include "HelperFunctions.h"

using namespace std;

void StartProgram();
Bank SetBank();

int main()
{
	StartProgram();
	
	system("pause");

}

void StartProgram()
{
	Bank bank = SetBank();
	Menu menu(bank);

	bool active = true;
	int command;

	menu.PrintMenu();

	while (active)
	{
		command = ValidIntegerInput();

		try
		{
			menu.RecogniseCommand(command);
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}

		system("pause");

		menu.CleanMenu();
		menu.PrintMenu();
	}
}

Bank SetBank()
{
	String name, address;

	cout << "Enter bank's name: ";
	std::cin >> name;

	cout << "Enter bank's address: ";
	std::cin >> address;

	system("cls");

	return Bank(name, address);
}
