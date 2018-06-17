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

	//����� ������� �� ��������� ������ �� customers ��� -1, ��� �� ����������
	int findIndex(int custId) const;
	//����� ������� �� ��������� ������ �� accounts ���� ������� ��������� �� ��������� ������ ��� -1, ��� �� ����������
	int findAccount(int i, int custId) const;
	//����� ������� �� ��������� ������ �� accounts �� ��������� IBAN
	int findWithIBAN(const char* iban) const;
};
