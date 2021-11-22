//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#ifndef GROCERYMANAGER_USERS_ADDRESS_H_
#define GROCERYMANAGER_USERS_ADDRESS_H_
#include "../grocerymanager.helpers/FileHandler.h"
#include <iomanip>

class Address: private FileHandler {
	string addressLine1;
	string addressLine2;
	string city;
	string state;
	string pinCode;
	void createContent();
	void createObject();
	void readToUpdate();
public:
	Address();
	virtual ~Address();
	void readAddress();
	void displayAddress();
	int update();
	void setAddress(string);
	string getAddress();
};

#endif /* GROCERYMANAGER_USERS_ADDRESS_H_ */
