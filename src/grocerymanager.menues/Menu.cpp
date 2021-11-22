//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#include "Menu.h"

Menu::Menu(string type) {
	if (type == "Admin") {
		this->menuType = "ADMIN";
	} else {
		this->menuType = "USER";
	}
}
Menu::~Menu() {
}
int Menu::readChoice(int llimit, int ulimit) {
	cout << "# ";
	int choice = 1;
	while (llimit <= choice && choice <= ulimit) {
		choice = readInteger(readString());
		if (llimit <= choice && choice <= ulimit) {
			break;
		}
	}
	return choice;
}
int Menu::isAdmin() {
	if (menuType == "ADMIN") {
		return 0;
	}
	return -1;
}
void Menu::displayMenu() {
	int choice;
	do {
		cout << endl;
		if (isAdmin() == 0) {
			choice = displayAdminMenu();
		} else {
			choice = displayUserMenu();
		}
	} while (choice != -1);
}
int Menu::displayAdminMenu() {
	while (true) {
		cout << "[Admin Menu]" << endl;
		cout << "1. Manage users" << endl;
		cout << "2. Manage stock" << endl;
		cout << "3. Exit" << endl;
		int choice = readChoice(1, 3);
		if (choice == 1) {
			cout << endl << "[Manage users]" << endl;
			displayUserManagementMenu();
		} else if (choice == 2) {
			cout << endl << "[Manage stock]" << endl;
			displayStockManagementMenu();
		} else {
			break;
		}
		cout << endl;
	}
	return -1;
}
int Menu::displayUserMenu() {
	while (true) {
		cout << "[User Menu]" << endl;
		cout << "1. Manage cart" << endl;
		cout << "2. Exit" << endl;
		int choice = readChoice(1, 2);
		if (choice == 1) {
			cout << "[Manage cart items]" << endl;
			displayCartManagementMenu();
		} else {
			break;
		}
		cout << endl;
	}
	return -1;
}
int Menu::displayUserManagementMenu() {
	User user;
	while (true) {
		cout << "[User Management Menu]" << endl;
		cout << "1. Add user" << endl;
		cout << "2. Modify user" << endl;
		cout << "3. Delete user" << endl;
		cout << "4. Display all users" << endl;
		cout << "5. Exit" << endl;
		int choice = readChoice(1, 5);
		if (choice == 1) {
			cout << "[Add user]" << endl;
			user.add();
		} else if (choice == 2) {
			cout << "[Modify user]" << endl;
			user.update();
		} else if (choice == 3) {
			cout << "[Delete user]" << endl;
			user.erase();
		} else if (choice == 4) {
			cout << "[Display all users]" << endl;
			user.displayAll();
		} else {
			break;
		}
		cout << endl;
	}
	return -1;
}
int Menu::displayStockManagementMenu() {
	Inventory inventory;
	while (true) {
		cout << "[Stock Management Menu]" << endl;
		cout << "1. Add grocery to Inventory" << endl;
		cout << "2. Modify grocery in Inventory" << endl;
		cout << "3. Delete grocery from Inventory" << endl;
		cout << "4. Display all groceries from Inventory" << endl;
		cout << "5. Exit" << endl;
		int choice = readChoice(1, 5);
		if (choice == 1) {
			cout << "[Add grocery to Inventory]" << endl;
			inventory.add();
		} else if (choice == 2) {
			cout << "[Modify grocery in Inventory]" << endl;
			inventory.update();
		} else if (choice == 3) {
			cout << "[Delete grocery from Inventory]" << endl;
			inventory.erase();
		} else if (choice == 4) {
			cout << "[Display all groceries from Inventory]" << endl;
			inventory.displayAll();
		} else {
			break;
		}
		cout << endl;
	}
	return -1;
}
int Menu::displayCartManagementMenu() {
	CartManager cartManager;
	while (true) {
		cout << "[Cart Management  Menu]" << endl;
		cout << "1. Add item to cart" << endl;
		cout << "2. Modify item in cart" << endl;
		cout << "3. Delete item from cart" << endl;
		cout << "4. Display all items from cart" << endl;
		cout << "5. Display all groceries from Inventory" << endl;
		cout << "6. Generate bill" << endl;
		cout << "7. Exit" << endl;
		int choice = readChoice(1, 6);
		if (choice == 1) {
			cout << "[Add item to cart]" << endl;
			cartManager.add();
		} else if (choice == 2) {
			cout << "[Modify item in cart]" << endl;
			cartManager.update();
		} else if (choice == 3) {
			cout << "[Delete item from cart]" << endl;
			cartManager.erase();
		} else if (choice == 4) {
			cout << "[Display all items from cart]" << endl;
			cartManager.displayAll();
		} else if (choice == 5) {
			cout << "[Display all groceries from Inventory]" << endl;
			cartManager.displayInventory();
		} else if (choice == 6) {
			cout << "[Generate bill]" << endl;
			cartManager.generateBill();
		}else {
			break;
		}
		cout << endl;
	}
	return -1;
}
string Menu::readString(){
	string value;
	cin.clear();
	getline(cin, value);
	return value;
}
int Menu::readInteger(string value) {
	return stoi(value);
}
