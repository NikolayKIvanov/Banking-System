// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "Bank.h"

using namespace std;

void showMenu()
{
	cout << "\n********* MENU *********";
	cout << "\n---1. List customers";
	cout << "\n---2. Add new customer";
	cout << "\n---3. Delete customer";
	cout << "\n---4. List all accounts";
	cout << "\n---5. List customer accounts";
	cout << "\n---6. Add new account";
	cout << "\n---7. Delete account";
	cout << "\n---8. Withdraw from account";
	cout << "\n---9. Deposit to account";
	cout << "\n--10. Transfer";
	cout << "\n--11. Display info for the bank";
	cout << "\n--12. Quit";
}

bool legal(int i)
{
	return i >= 1 && i <= 12;
}

int getCommand()
{
	int cmd;
	cout << "\nEnter command: ";
	cin >> cmd;
	while (!legal(cmd))
	{
		cout << "\nIllegal command, please try again . . .";
		showMenu();
		cout << "\nEnter command: ";
		cin >> cmd;
	}

	return cmd;
}

void execution(Bank& b)
{
	showMenu();

	int command;
	int custId;
	char name[20];
	char address[20];
	char accType[20];
	char fromIBAN[20];
	char toIBAN[20];
	double amount;

	do
	{
		command = getCommand();		// извличаме команда
		switch (command)
		{
		case 1:
			b.listCustomers();
			break;
		case 2:
			cout << "Enter customer ID: ";
			cin >> custId;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter address: ";
			cin >> address;
			b.addCustomer(custId, name, address);
			break;
		case 3:
			cout << "Enter customer ID: ";
			cin >> custId;
			b.deleteCustomer(custId);
			break;
		case 4:
			b.listAccounts();
			break;
		case 5:
			cout << "Enter customer ID: ";
			cin >> custId;
			b.listCustomerAccount(custId);
			break;
		case 6:
			cout << "Enter account type: ";
			cin >> accType;
			cout << "Enter IBAN: ";
			cin >> toIBAN;
			cout << "Enter customer ID: ";
			cin >> custId;
			cout << "Enter amount: ";
			cin >> amount;
			b.addAccount(accType, toIBAN, custId, amount);
			break;
		case 7:
			cout << "Enter IBAN: ";
			cin >> fromIBAN;
			b.deleteAccount(fromIBAN);
			break;
		case 8:
			cout << "Enter IBAN: ";
			cin >> fromIBAN;
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			b.withdraw(fromIBAN, amount);
			break;
		case 9:
			cout << "Enter IBAN: ";
			cin >> toIBAN;
			cout << "Enter amount to deposit: ";
			cin >> amount;
			b.deposit(toIBAN, amount);
			break;
		case 10:
			cout << "Enter fromIBAN: ";
			cin >> fromIBAN;
			cout << "Enter toIBAN: ";
			cin >> toIBAN;
			cout << "Enter amount to transfer: ";
			cin >> amount;
			b.transfer(fromIBAN, toIBAN, amount);
			break;
		case 11:
			b.display();
			break;
		case 12:
			break;
		}
	} while (command != 12);
}

int main()
{
	Bank b("fibank", "sofia, bulgaria");

	execution(b);
	
	return 0;
}

