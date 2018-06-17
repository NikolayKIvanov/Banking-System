#include "stdafx.h"
#include "Account.h"

Account::Account(const char * _iban, int _ownerid, double _amount)
{
	iban = new char[strlen(_iban) + 1];
	strcpy(iban, _iban);
	ownerid = _ownerid;
	amount = _amount;
}

Account::Account(const Account& other)
{
	iban = new char[strlen(other.iban) + 1];
	strcpy(iban, other.iban);
	ownerid = other.ownerid;
	amount = other.amount;
}

Account& Account::operator=(const Account& other)
{
	if (this != &other)
	{
		delete[] iban;
		iban = new char[strlen(other.iban) + 1];
		strcpy(iban, other.iban);
		ownerid = other.ownerid;
		amount = other.amount;
	}

	return *this;
}

Account::~Account()
{
	delete[] iban;
}

double Account::getBalance() const
{
	return amount;
}
