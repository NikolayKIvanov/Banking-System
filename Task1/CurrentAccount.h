#pragma once

#include "stdafx.h"
#include "Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount(const char* _iban = "", int _ownerid = 0, double _amount = 0.0)
		: Account(_iban, _ownerid, _amount) {}
	CurrentAccount(const CurrentAccount& other)
		: Account(other.iban, other.ownerid, other.amount) {}
	CurrentAccount& operator=(const CurrentAccount& other)
	{
		if (this != &other)
		{
			Account::operator=(other);
		}

		return *this;
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
		std::cout << "Type: Current Account, IBAN: "
			<< iban << ", Owner ID: "
			<< ownerid << ", Balance: " << amount << " lv\n";
	}

	int getOwnerId() const
	{
		return ownerid;
	}
};
