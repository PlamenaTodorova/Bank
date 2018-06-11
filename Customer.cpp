#include "Customer.h"
#include<iostream>
#include<exception>

/*Customer::Customer() : Customer(0, "No_name", "No_address")
{
}*/

Customer::Customer() :
	name(""),
	address("")
{
	id = -1;
}

Customer::Customer(int id, const String& name, const String& address) :
	name(name),
	address(address)
{
	SetId(id);
}

void Customer::Display() const
{
	std::cout << "Custtomer: #" << GetId() << "; Name: " << GetName() << "; Address: " << GetAddress() << std::endl;
}

void Customer::SetId(int id)
{
	if (id >= 0)
	{
		this->id = id;
	}
	else
		throw std::exception("Id can not be negative number.");
}
