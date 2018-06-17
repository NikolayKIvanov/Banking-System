#pragma once

#include "stdafx.h"
#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount(const char* _iban = "", int _ownerid = 0, double _amount = 0.0, double _interestRate = 0.0)
		: Account(_iban, _ownerid, _amount)
	{
		interestRate = _interestRate;
	}
	SavingsAccount(const SavingsAccount& other)
		: Account(other.iban, other.ownerid, other.amount)
	{
		interestRate = other.interestRate;
	}
	SavingsAccount& operator=(const SavingsAccount& other)
	{
		if (this != &other)
		{
			Account::operator=(other);
			interestRate = other.interestRate;
		}

		return *this;
	}

	double getInterestRate() const
	{
		return interestRate;
	}

	void deposit(double money)
	{
		amount += money;
	}
	bool withdraw(double money)
	{
		if (money > amount)
		{
			return false;
		}
		else
		{
			amount -= money;
			return true;
		}
	}
	void display() const
	{
		std::cout << "Type: Savings Account, IBAN: "
			<< iban << ", Owner ID: "
			<< ownerid << ", Interest Rate: "
			<< interestRate << "%, Balance: " << amount << " lv\n";
	}

	int getOwnerId() const
	{
		return ownerid;
	}
private:
	double interestRate;
};