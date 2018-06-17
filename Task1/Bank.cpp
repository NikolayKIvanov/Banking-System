#include "stdafx.h"
#include "Bank.h"

Bank::Bank(const char* _name, const char* _address) : accounts(), customers()
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	address = new char[strlen(_address) + 1];
	strcpy(address, _address);
}

Bank::Bank(const char* _name, const char* _address, vector<Customer>& _customers, vector<Account*>& _accounts)
	: customers(_customers), accounts(_accounts)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	address = new char[strlen(_address) + 1];
	strcpy(address, _address);
}

Bank::Bank(const Bank& other) 
	: customers(other.customers), accounts(other.accounts)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	address = new char[strlen(other.address) + 1];
	strcpy(address, other.address);
}

Bank& Bank::operator=(const Bank& other)
{
	if (this != &other)
	{
		delete[] name;
		delete[] address;

		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		address = new char[strlen(other.address) + 1];
		strcpy(address, other.address);
		customers = other.customers;
		accounts = other.accounts;
	}

	return *this;
}

Bank::~Bank()
{
	delete[] name;
	delete[] address;
}

void Bank::addCustomer(int customerId, const char* name, const char* address)
{

	if (findIndex(customerId) == -1)
	{
		Customer* curr = new Customer(customerId, name, address);
		customers.push_back(*curr);
		delete curr;
	}

}

void Bank::listCustomers() const
{
	for (int i = 0; i < static_cast<int>(customers.size()); i++)
	{
		customers[i].display();
	}
}

void Bank::deleteCustomer(int custId)
{
	int index = findIndex(custId);
	customers.erase(customers.begin() + index);

	index = 0;
	while (!accounts.empty())
	{
		index = findAccount(index, custId);
		if (index == -1)
		{
			break;
		}
		accounts.erase(accounts.begin() + index);
	}

}

void Bank::addAccount(const char* type, const char* iban, int ownerId, double amount)
{
	if (findIndex(ownerId) == -1)
	{
		cout << "No such customer exists!\n";
		return;
	}

	for (int i = 0; i < static_cast<int>(accounts.size()); i++)
	{
		if (strcmp((*accounts[i]).getIBAN(), iban) == 0)
		{
			cout << "Such IBAN already exists!\n";
			return;
		}
	}

	if (strcmp(type, "CurrentAccount") == 0)
	{
		CurrentAccount* curr = new CurrentAccount(iban, ownerId, amount);
		accounts.push_back(curr);
	}
	else if (strcmp(type, "SavingsAccount") == 0)
	{
		cout << "Enter interest rate: ";
		double interest;
		cin >> interest;
		SavingsAccount* curr = new SavingsAccount(iban, ownerId, amount, interest);
		accounts.push_back(curr);
	}
	else if (strcmp(type, "PrivilegeAccount") == 0)
	{
		cout << "Enter overdraft amount: ";
		double overdraft;
		cin >> overdraft;
		PrivilegeAccount* curr = new PrivilegeAccount(iban, ownerId, amount, overdraft);
		accounts.push_back(curr);
	}
	else
	{
		cout << "No such account type exists!\n";
	}
}

void Bank::deleteAccount(const char* iban)
{
	for (int i = 0; i < static_cast<int>(accounts.size()); i++)
	{
		if (strcmp(accounts[i]->getIBAN(), iban) == 0)
		{
			accounts.erase(accounts.begin() + i);
			return;
		}
	}
	cout << "No such account exists!\n";
}

void Bank::listAccounts() const
{
	for (int i = 0; i < static_cast<int>(accounts.size()); i++)
	{
		accounts[i]->display();
	}
}

void Bank::listCustomerAccount(int custId) const
{
	int index = -1;
	while (true)
	{
		index = findAccount(index + 1, custId);
		if (index == -1)
		{
			break;
		}
		accounts[index]->display();
	}
}

void Bank::withdraw(const char* iban, double amount)
{
	int index = findWithIBAN(iban);
	if (index == -1)
	{
		cout << "No such account " << iban << " exists!\n";
		return;
	}
	if (!accounts[index]->withdraw(amount))
	{
		cout << "Not enough money in account!\n";
	}
}

void Bank::deposit(const char* iban, double amount)
{
	int index = findWithIBAN(iban);
	if (index == -1)
	{
		cout << "No such account " << iban << " exists!\n";
	}
	accounts[index]->deposit(amount);
}

void Bank::transfer(const char* fromIBAN, const char* toIBAN, double amount)
{
	int index = findWithIBAN(fromIBAN);
	if (index == -1)
	{
		cout << "No such account " << fromIBAN << " exists!\n";
	}
	if (accounts[index]->withdraw(amount))
	{
		int newIndex = findWithIBAN(toIBAN);
		if (newIndex == -1)
		{
			accounts[index]->deposit(amount);
			cout << "No such account " << toIBAN << " exists!\n";
		}
		accounts[newIndex]->deposit(amount);
	}
}

void Bank::display() const
{
	cout << "Name: " << name 
		<< "\nAddress: " << address
		<< "\nCustomers: " << static_cast<int>(customers.size())
		<< "\nAccounts: " << static_cast<int>(accounts.size());
}

int Bank::findIndex(int custId) const
{
	for (int i = 0; i < static_cast<int>(customers.size()); i++)
	{
		if (custId == customers[i].getId())
		{
			return i;
		}
	}

	return -1;
}
int Bank::findAccount(int i, int custId) const
{
	for (i; i < static_cast<int>(accounts.size()); i++)
	{
		if (custId == accounts[i]->getOwnerId())
		{
			return i;
		}
	}

	return -1;
}

int Bank::findWithIBAN(const char* iban) const
{
	for (int i = 0; i < static_cast<int>(accounts.size()); i++)
	{
		if (strcmp(accounts[i]->getIBAN(), iban) == 0)
		{
			return i;
		}
	}

	return -1;
}