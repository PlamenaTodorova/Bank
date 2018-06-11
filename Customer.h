#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "String.h"

class Customer
{
public:
	Customer();
	Customer(int id, const String& name, const String& address);

	int GetId() const { return id; }
	const String& GetName() const { return name; }
	const String& GetAddress() const { return address; }

	void Display() const;
private:
	int id;
	String name;
	String address;

	void SetId(int id);
};

#endif // !CUSTOMER_H