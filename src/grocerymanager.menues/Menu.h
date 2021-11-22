//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#ifndef GROCERYMANAGER_MENUES_MENU_H_
#define GROCERYMANAGER_MENUES_MENU_H_
#include "../grocerymanager.groceries/Inventory.h"
#include "../grocerymanager.users/User.h"
#include "../grocerymanager.groceries/CartManager.h"
#include <string>
#include <iostream>
using namespace std;

class Menu {
	string menuType;
	int readChoice(int, int);
	int isAdmin();
	int displayAdminMenu();
	int displayUserMenu();
	int displayUserManagementMenu();
	int displayStockManagementMenu();
	int displayCartManagementMenu();
	string readString();
	int readInteger(string);
public:
	Menu(string);
	virtual ~Menu();
	void displayMenu();
};

#endif /* GROCERYMANAGER_MENUES_MENU_H_ */
