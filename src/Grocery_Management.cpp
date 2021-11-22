//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#include <iostream>
#include "grocerymanager.groceries/Inventory.h"
#include "grocerymanager.users/User.h"
#include "grocerymanager.groceries/CartManager.h"
#include "grocerymanager.menues/Menu.h"
#include <time.h>

using namespace std;
int main() {
	User user;
	while(true){
		int authenticated = -1;
		do{
			authenticated = user.authenticateUser();
		}while(authenticated != 0);
		if(user.getType() == "ADMIN"){
			Menu menu("Admin");
			menu.displayMenu();
		} else {
			Menu menu("User");
			menu.displayMenu();
		}
		cout << endl << "Logged you out..." << endl;
	}
	return 0;
}
