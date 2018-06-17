#pragma once

#include "stdafx.h"
#include "Account.h"

class PrivilegeAccount : public Account
{
public:
	PrivilegeAccount(const char* _iban = "", int _ownerid = 0, double _amount = 0.0, double _overdraft = 0.0)
		: Account(_iban, _ownerid, _amount)
	{
		overdraft = _overdraft;
	}
	PrivilegeAccount(const PrivilegeAccount& other)
		: Account(other.iban, other.ownerid, other.amount)
	{
		overdraft = other.overdraft;
	}
	PrivilegeAccount& operator=(const PrivilegeAccount& other)
	{
		if (this != &other)
		{
			Account::operator=(other);
			overdraft = other.overdraft;
		}

		return *this;
	}

	double getoverdraft() const
	{
		return overdraft;
	}

	void deposit(double money)
	{
		amount += money;
	}

	bool withdraw(double money)
	{
		if (money > amount + overdraft)
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
		std::cout << "Type: Privilege Account, IBAN: "
			<< iban << ", Owner ID: "
			<< ownerid << ", Overdraft: "
			<< overdraft << " lv, Balance: " << amount << " lv\n";
	}

	int getOwnerId() const
	{
		return ownerid;
	}
private:
	double overdraft;
};