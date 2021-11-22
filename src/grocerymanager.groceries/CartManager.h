//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#ifndef GROCERYMANAGER_GROCERIES_CARTMANAGER_H_
#define GROCERYMANAGER_GROCERIES_CARTMANAGER_H_
#include "../grocerymanager.helpers/Object.h"
#include "../grocerymanager.helpers/FileHandler.h"
#include "../grocerymanager.properties/PropertiesManager.h"
#include "Inventory.h"
#include <iomanip>

class CartManager: private FileHandler, private Object {
	char* groceryFileName = "grocery.txt";
	char* cartFileName = "cart.txt";
	char* tempFileName = "cartTemp.txt";
	string groceryId;
	string name;
	string unit;
	float quantity;
	float price;
	void display();
	void readToUpdate();
	void createContent();
	void createObject();
	int getItemCount();
	int search(string);
	void updateItemCount(int);
	void readFromInventory();
	int getGroceryCount();
	int getQuantityFromInventory();
	void calculatePrice();
	float getPriceFromInventory();
	void updateInventory(CartManager);
public:
	CartManager();
	virtual ~CartManager();
	void read();
	int add();
	int update();
	int erase();
	void displayAll();
	void displayInventory();
	void generateBill();
	friend std::ostream & operator <<(std::ostream &out, CartManager &grocery) {
		grocery.createContent();
		string content = grocery.getContent();
		out << content << endl;
		return out;
	}
	friend std::istream & operator >>(std::istream &in, CartManager &grocery) {
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
	float getQuantity() const {
		return quantity;
	}
	float getPrice() const {
		return price;
	}
	const string& getName() const {
		return name;
	}
	const string& getUnit() const {
		return unit;
	}
	void setQuantity(float quantity) {
		this->quantity = quantity;
	}
};
#endif /* GROCERYMANAGER_GROCERIES_CARTMANAGER_H_ */
