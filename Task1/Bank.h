#pragma once

#include "stdafx.h"
#include "iostream"
#include "vector"
#include "Customer.h"
#include "CurrentAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"

using namespace std;

class Bank
{
public:
	Bank(const char* _name = "", const char* _address = "");
	Bank(const char* _name, const char* _address, vector<Customer>& _customers, vector<Account*>& _accounts);
	Bank(const Bank& other);
	Bank& operator=(const Bank& other);
	~Bank();

	void addCustomer(int customerId, const char* name, const char* address);
	void listCustomers() const;
	void deleteCustomer(int custId);
	void addAccount(const char* type, const char* iban, int ownerId, double amount);
	void deleteAccount(const char* iban);
	void listAccounts() const;
	void listCustomerAccount(int custId) const;
	void withdraw(const char* iban, double amount);
	void deposit(const char* iban, double amount);
	void transfer(const char* fromIBAN, const char* toIBAN, double amount);
	void display() const;

private:
	char* name;
	char* address;

	vector<Customer> customers;
	vector<Account*> accounts;

	//връща индекса на определен клиент от customers или -1, ако не съществува
	int findIndex(int custId) const;
	//връща индекса на определен акаунт от accounts като започва търсенето от определен индекс или -1, ако не съществува
	int findAccount(int i, int custId) const;
	//връща индекса на определен акаунт от accounts по определен IBAN
	int findWithIBAN(const char* iban) const;
};
