#pragma once

class Customer
{
public:
	Customer(int _id = 0, const char* _name = "", const char* _address = "");
	Customer(const Customer&);
	Customer& operator=(const Customer&);
	~Customer();

	//getters
	int getId() const;
	char* getName() const;
	char* getAddress() const;

	void display() const;

private:
	int id;
	char* name;
	char* address;
};