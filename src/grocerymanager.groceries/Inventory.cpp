//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#include "Inventory.h"

Inventory::Inventory() {
	groceryId = to_string(0);
	name = "";
	price = 0.0F;
	quantity = 0.0F;
	unit = "";
}
Inventory::~Inventory() {
}
void Inventory::readToUpdate() {
	string val = "";
	cout << "Grocery name ( " << name << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->name = val;
	}
	cout << "Price ( " << price << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->price = readFloat(val);
	}
	cout << "Quantity ( " << quantity << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->quantity = readFloat(val);
	}
	cout << "Unit : ( " << unit << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->unit = val;
	}
}
void Inventory::display() {
	cout << setw(10) << groceryId << setw(15) << name << setw(15) << price
			<< setw(15) << quantity << setw(10) << unit << endl;
}
int Inventory::add() {
	Inventory grocery;
	cout << "Enter grocery details :" << endl;
	grocery.read();
	while (search(this->groceryId) == 0) {
		cout << "Grocery id unavailable, Enter new grocery id : ";
		string id = readString();
		grocery.setGroceryId(id);
	}
	ofstream out(Inventory::groceryFileName, ios::app);
	out << grocery;
	out.close();
	updateGroceryCount(1);
	return 0;
}
int Inventory::getGroceryCount() {
	PropertiesManager propertyManager;
	string key = propertyManager.getGroceryCountKey();
	string value = propertyManager.readProperty(key).getValue();
	return readInteger(value);
}
int Inventory::update() {
	cout << "Enter grocery details (existing) :" << endl;
	cout << "Grocery id : ";
	string id = readString();
	if (search(id) != 0) {
		return -1;
	}
	ifstream in(Inventory::groceryFileName);
	ofstream out(Inventory::tempFileName, ios::app);
	Inventory grocery;
	for (int counter = 0, groceryCount = getGroceryCount();
			counter < groceryCount; counter++) {
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
	remove(Inventory::groceryFileName);
	rename(Inventory::tempFileName, Inventory::groceryFileName);
	return 0;
}
int Inventory::erase() {
	cout << "Enter grocery details :" << endl;
	cout << "Grocery id : ";
	string id = readString();
	if (search(id) != 0) {
		return -1;
	}
	ifstream in(Inventory::groceryFileName);
	ofstream out(Inventory::tempFileName, ios::app);
	Inventory grocery;
	for (int counter = 0, groceryCount = getGroceryCount();
			counter < groceryCount; counter++) {
		in >> grocery;
		if (grocery.groceryId != id) {
			out << grocery;
		}
	}
	in.close();
	out.close();
	updateGroceryCount(-1);
	remove(Inventory::groceryFileName);
	rename(Inventory::tempFileName, Inventory::groceryFileName);
	return 0;
}
void Inventory::read() {
	cout << "Grocery name : ";
	this->name = readString();
	cout << "Grocery Id : ";
	this->groceryId = readString();
	cout << "Price :";
	this->price = readFloat(readString());
	cout << "Quantity :";
	this->quantity = readFloat(readString());
	cout << "Unit : ";
	this->unit = readString();
}
int Inventory::search(string id) {
	Inventory grocery;
	ifstream in(groceryFileName);
	for (int counter = 0, groceryCount = getGroceryCount();
			counter < groceryCount; counter++) {
		in >> grocery;
		if (grocery.groceryId == id) {
			return 0;
		}
	}
	in.close();
	return -1;
}
void Inventory::createContent() {
	appendToContent(groceryId);
	appendToContent(name);
	appendToContent(price);
	appendToContent(quantity);
	appendToContent(unit);
}
void Inventory::createObject() {
	this->groceryId = getToken();
	replaceUnderscoresWithSpaces(this->groceryId);
	this->name = getToken();
	replaceUnderscoresWithSpaces(this->name);
	this->price = readFloat(getToken());
	this->quantity = readFloat(getToken());
	this->unit = getToken();
	replaceUnderscoresWithSpaces(this->unit);
}
void Inventory::updateGroceryCount(int off) {
	PropertiesManager propertyManager;
	string key = propertyManager.getGroceryCountKey();
	string value = propertyManager.readProperty(key).getValue();
	int groceryCount = readInteger(value);
	propertyManager.updateProperty(propertyManager.getGroceryCountKey(),
			to_string(groceryCount + 1));
	if (off == -1) {
		propertyManager.updateProperty(propertyManager.getGroceryCountKey(),
				to_string(groceryCount - 1));
	} else if (off == 1) {
		propertyManager.updateProperty(propertyManager.getGroceryCountKey(),
				to_string(groceryCount + 1));
	}
}
void Inventory::displayAll() {
	Inventory grocery;
	ifstream in(groceryFileName);
	cout << setw(10) << "Grocery ID" << setw(15) << "Name" << setw(15)
			<< "Price" << setw(15) << "Quantity" << setw(10) << "Unit" << endl;
	for (int counter = 0, groceryCount = getGroceryCount();
			counter < groceryCount; counter++) {
		in >> grocery;
		grocery.display();
	}
	in.close();
}
