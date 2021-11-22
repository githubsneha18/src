//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#ifndef GROCERYMANAGER_GROCERIES_INVENTORY_H_
#define GROCERYMANAGER_GROCERIES_INVENTORY_H_
#include "../grocerymanager.helpers/Object.h"
#include "../grocerymanager.helpers/FileHandler.h"
#include "../grocerymanager.properties/PropertiesManager.h"
#include <iomanip>

class Inventory: public Object, private FileHandler {
	char* groceryFileName = "grocery.txt";
	char* tempFileName = "groceryTemp.txt";
	string groceryId;
	string name;
	string unit;
	float quantity;
	float price;
	void display();
	void readToUpdate();
	void createContent();
	void createObject();
	int getGroceryCount();
	void updateGroceryCount(int);
public:
	Inventory();
	virtual ~Inventory();
	void read();
	int add();
	int update();
	int erase();
	void displayAll();
	int search(string);
	friend std::ostream & operator <<(std::ostream &out, Inventory &grocery) {
		grocery.createContent();
		string content = grocery.getContent();
		out << content << endl;
		return out;
	}
	friend std::istream & operator >>(std::istream &in, Inventory &grocery) {
		string content;
		in >> content;
		grocery.setContent(content);
		grocery.createObject();
		return in;
	}
	void setGroceryId(const string& groceryId) {
		this->groceryId = groceryId;
	}
	const string& getGroceryId() const {
		return groceryId;
	}
};

#endif /* GROCERYMANAGER_GROCERIES_INVENTORY_H_ */
