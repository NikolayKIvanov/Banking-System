#include "stdafx.h"
#include "Customer.h"
#include "iostream"
#include "stdlib.h"

Customer::Customer(int _id, const char * _name, const char * _address)
{
	id = _id;
	name = new char[strlen(_name) + 1];
	if (name == NULL)
	{
		exit(1);
	}
	strcpy(name, _name);
	address = new char[strlen(_address) + 1];
	strcpy(address, _address);
}

Customer::Customer(const Customer& other)
{
	id = other.id;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	address = new char[strlen(other.address) + 1];
	strcpy(address, other.address);
}

Customer & Customer::operator=(const Customer& other)
{
	if (this != &other)
	{
		delete[] name;
		delete[] address;
		id = other.id;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		address = new char[strlen(other.address) + 1];
		strcpy(address, other.address);
	}

	return *this;
}

Customer::~Customer()
{
	delete[] name;
	delete[] address;
}

int Customer::getId() const
{
	return id;
}

char* Customer::getName() const
{
	return name;
}

char* Customer::getAddress() const
{
	return address;
}

void Customer::display() const
{
	std::cout << "Id: " << id << ", Name: " << name << ", Address: " << address << '\n';
}
