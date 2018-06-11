#include "HelperFunctions.h"

#include<iostream>

int ValidIntegerInput()
{
	int number;
	bool valid = false;

	do
	{
		std::cin >> number;

		if (std::cin.good())
		{
			valid = true;
		}
		else
		{
			std::cout << "Not a number. Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid);

	std::cin.ignore();

	return number;
}

double ValidDoubleInput()
{
	double number;
	bool valid = false;

	do
	{
		std::cin >> number;

		if (std::cin.good())
		{
			valid = true;
		}
		else
		{
			std::cout << "Not a number. Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid);

	std::cin.ignore();

	return number;
}
