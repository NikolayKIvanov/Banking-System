#pragma once

#include "iostream"

class Account
{
public:
	Account(const char* _iban = "", int _ownerid = 0, double _amount = 0.0);
	Account(const Account&);
	Account& operator=(const Account&);
	~Account();

	virtual void deposit(double) = 0;
	virtual bool withdraw(double) = 0;
	virtual void display() const = 0;

	double getBalance() const;
	int getOwnerId() const
	{
		return ownerid;
	}

	const char* getIBAN() const
	{
		return iban;
	}
protected:
	char* iban;
	int ownerid;
	double amount;
};
