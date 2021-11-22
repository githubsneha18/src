//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#include "CartManager.h"

CartManager::CartManager() {
	groceryId = to_string(0);
	name = "";
	price = 0.0F;
	quantity = 0.0F;
	unit = "";
}
CartManager::~CartManager() {
}
void CartManager::readToUpdate() {
	float requiredQuantity = 0;
	int stock = getQuantityFromInventory();
	do {
		cout << "Quantity ( " << stock << " " << unit << " ) : ";
		requiredQuantity = readFloat(readString());
	} while (requiredQuantity >= stock || requiredQuantity <= 0);
	this->quantity = requiredQuantity;
	calculatePrice();
}
void CartManager::display() {
	cout << setw(10) << groceryId << setw(15) << name << setw(15) << price
			<< setw(15) << quantity << setw(10) << unit << endl;
}
int CartManager::add() {
	CartManager grocery;
	Inventory inventory;
	cout << "Enter item details :" << endl;
	do {
		grocery.read();
		if (search(this->groceryId) == 0) {
			cout << "Item already available in cart, Enter new item id : ";
		} else {
			if (inventory.search(grocery.getGroceryId()) == 0) {
				grocery.readFromInventory();
				grocery.readToUpdate();
			}
			break;
		}
	} while (1);
	ofstream out(CartManager::cartFileName, ios::app);
	out << grocery;
	out.close();
	updateItemCount(1);
	return 0;
}
int CartManager::getItemCount() {
	PropertiesManager propertyManager;
	string key = propertyManager.getItemCountKey();
	string value = propertyManager.readProperty(key).getValue();
	return readInteger(value);
}
int CartManager::getGroceryCount() {
	PropertiesManager propertyManager;
	string key = propertyManager.getGroceryCountKey();
	string value = propertyManager.readProperty(key).getValue();
	return readInteger(value);
}
int CartManager::update() {
	cout << "Enter item details (existing) :" << endl;
	cout << "Item id : ";
	string id = readString();
	if (search(id) != 0) {
		return -1;
	}
	ifstream in(CartManager::cartFileName);
	ofstream out(CartManager::tempFileName, ios::app);
	CartManager grocery;
	for (int counter = 0, groceryCount = getItemCount(); counter < groceryCount;
			counter++) {
		in >> grocery;
		if (grocery.groceryId == id) {
			cout
					<< "Type in details for relevant field(s) or press return key to skip : "
					<< endl;
			grocery.readToUpdate();
			out << grocery;
		} else {
			out << grocery;
		}
	}
	in.close();
	out.close();
	remove(CartManager::cartFileName);
	rename(CartManager::tempFileName, CartManager::cartFileName);
	return 0;
}
int CartManager::erase() {
	cout << "Enter item details :" << endl;
	cout << "Item id : ";
	string id;
	cin >> id;
	if (search(id) != 0) {
		return -1;
	}
	ifstream in(CartManager::cartFileName);
	ofstream out(CartManager::tempFileName, ios::app);
	CartManager grocery;
	for (int counter = 0, groceryCount = getItemCount(); counter < groceryCount;
			counter++) {
		in >> grocery;
		if (grocery.groceryId != id) {
			out << grocery;
		}
	}
	in.close();
	out.close();
	updateItemCount(-1);
	remove(CartManager::cartFileName);
	rename(CartManager::tempFileName, CartManager::cartFileName);
	return 0;
}
void CartManager::read() {
	cout << "Grocery Id : ";
	this->groceryId = readString();
}
int CartManager::search(string id) {
	CartManager grocery;
	ifstream in(cartFileName);
	for (int counter = 0, itemCount = getItemCount(); counter < itemCount;
			counter++) {
		in >> grocery;
		if (grocery.groceryId == id) {
			return 0;
		}
	}
	in.close();
	return -1;
}
void CartManager::createContent() {
	appendToContent(groceryId);
	appendToContent(name);
	appendToContent(price);
	appendToContent(quantity);
	appendToContent(unit);
}
void CartManager::createObject() {
	this->groceryId = getToken();
	replaceUnderscoresWithSpaces(groceryId);
	this->name = getToken();
	replaceUnderscoresWithSpaces(name);
	this->price = readFloat(getToken());
	this->quantity = readFloat(getToken());
	this->unit = getToken();
	replaceUnderscoresWithSpaces(unit);
}
void CartManager::updateItemCount(int off) {
	PropertiesManager propertyManager;
	string key = propertyManager.getItemCountKey();
	string value = propertyManager.readProperty(key).getValue();
	int itemCount = readInteger(value);
	propertyManager.updateProperty(key, to_string(itemCount + 1));
	if (off == -1) {
		propertyManager.updateProperty(key, to_string(itemCount - 1));
	} else if (off == 1) {
		propertyManager.updateProperty(key, to_string(itemCount + 1));
	}
}
void CartManager::displayAll() {
	CartManager grocery;
	ifstream in(cartFileName);
	cout << setw(10) << "Item ID" << setw(15) << "Name" << setw(15) << "Price"
			<< setw(15) << "Quantity" << setw(10) << "Unit" << endl;
	for (int counter = 0, groceryCount = getItemCount(); counter < groceryCount;
			counter++) {
		in >> grocery;
		grocery.display();
	}
	in.close();
}
void CartManager::readFromInventory() {
	ifstream in(groceryFileName);
	CartManager cartManager;
	cout << setw(10) << "Grocery ID" << setw(15) << "Name" << setw(15)
			<< "Price" << setw(15) << "Quantity" << setw(10) << "Unit" << endl;
	for (int counter = 0, groceryCount = getGroceryCount();
			counter < groceryCount; counter++) {
		in >> cartManager;
		if (cartManager.getGroceryId() == this->getGroceryId()) {
			this->name = cartManager.name;
			this->unit = cartManager.unit;
		}
	}
}
int CartManager::getQuantityFromInventory() {
	ifstream in(groceryFileName);
	CartManager cartManager;
	for (int counter = 0, groceryCount = getGroceryCount();
			counter < groceryCount; counter++) {
		in >> cartManager;
		if (cartManager.getGroceryId() == this->getGroceryId()) {
			return cartManager.getQuantity();
		}
	}
	return -1;
}
float CartManager::getPriceFromInventory() {
	ifstream in(groceryFileName);
	CartManager cartManager;
	for (int counter = 0, groceryCount = getGroceryCount();
			counter < groceryCount; counter++) {
		in >> cartManager;
		if (cartManager.getGroceryId() == this->getGroceryId()) {
			return cartManager.getPrice();
		}
	}
	return -1;
}
void CartManager::calculatePrice() {
	float price = getPriceFromInventory();
	this->price = price * quantity;
}
void CartManager::displayInventory() {
	CartManager grocery;
	ifstream in(groceryFileName);
	cout << setw(10) << "Item ID" << setw(15) << "Name" << setw(15) << "Price"
			<< setw(15) << "Quantity" << setw(10) << "Unit" << endl;
	for (int counter = 0, groceryCount = getGroceryCount();
			counter < groceryCount; counter++) {
		in >> grocery;
		grocery.display();
	}
	in.close();
}
void CartManager::generateBill() {
	CartManager grocery;
	float total = 0;
	ifstream in(cartFileName);
	cout << "***************************************************************"
			<< endl;
	cout << "                          RECEIPT                              "
			<< endl;
	cout << "***************************************************************"
			<< endl;
	cout << setw(15) << "Item" << setw(15) << "Quantity" << setw(15) << "Price"
			<< endl;
	for (int counter = 0, groceryCount = getItemCount(); counter < groceryCount;
			counter++) {
		in >> grocery;
		cout << setw(15) << grocery.getName() << setw(10)
				<< grocery.getQuantity() << setw(5) << grocery.unit << setw(8)
				<< "Rs" << setw(7) << grocery.getPrice() << endl;
		total = total + grocery.getPrice();
		updateInventory(grocery);
	}
	cout << "***************************************************************"
			<< endl;
	cout << "Total Amount in rupees :" << setw(21) << total << endl;
	cout << "***************************************************************"
			<< endl;
	remove(cartFileName);
	PropertiesManager propertyManager;
	propertyManager.resetItemCount();
	in.close();
}
void CartManager::updateInventory(CartManager item) {
	ifstream in(groceryFileName);
	ofstream out(tempFileName, ios::app);
	CartManager cartManager;
	for (int counter = 0, groceryCount = getGroceryCount();
			counter < groceryCount; counter++) {
		in >> cartManager;
		if (cartManager.getGroceryId() == item.getGroceryId()) {
			float quntity = cartManager.getQuantity();
			quantity = quntity - item.getQuantity();
			cartManager.setQuantity(quantity);
			out << cartManager;
		} else {
			out << cartManager;
		}
	}
	remove(groceryFileName);
	rename(tempFileName, groceryFileName);
}
