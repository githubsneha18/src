//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#include "PropertiesManager.h"

PropertiesManager::PropertiesManager() {
	userCountKey = "usercount";
	groceryCountKey = "grocerycount";
	itemCountKey = "itemcount";
	initProperties();
}
PropertiesManager::~PropertiesManager() {
}
int PropertiesManager::addProperty(string key, string value) {
	if (key == "" || value == "" || ifPropertyExists(key) == 0) {
		return -1;
	}
	Property property(key, value);
	std::ofstream out(propertyFileName, ios::app);
	out << property;
	out.close();
	return 0;
}
int PropertiesManager::updateProperty(string key, string value) {
	if (key == "" || value == "" || ifPropertyExists(key) == -1) {
		return -1;
	}
	string content = "";
	std::ifstream in(propertyFileName);
	std::ofstream out(tempFileName);
	for (int i = 0; i < PROPERTY_COUNT; i++) {
		in >> content;
		if (content == "") {
			break;
		}
		Property property(content);
		if (property.getKey() == key) {
			property.setValue(value);
			out << property;
		} else {
			out << property;
		}
	}
	in.close();
	out.close();
	remove(propertyFileName);
	rename(tempFileName, propertyFileName);
	return 0;
}
int PropertiesManager::deleteProperty(string key) {
	if (key == "" || ifPropertyExists(key) == -1) {
		return -1;
	}
	string content = "";
	std::ifstream in(propertyFileName);
	std::ofstream out(tempFileName);
	for (int i = 0; i < PROPERTY_COUNT; i++) {
		in >> content;
		if (content == "") {
			break;
		}
		Property property(content);
		if (!(property.getKey() == key)) {
			out << property;
		}
	}
	in.close();
	out.close();
	remove(propertyFileName);
	rename(tempFileName, propertyFileName);
	return 0;
}
Property PropertiesManager::readProperty(string key) {
	string content = "";
	Property property;
	ifstream in(propertyFileName);
	for (int i = 0; i < PROPERTY_COUNT; i++) {
		in >> content;
		if (content == "") {
			break;
		}
		property.setProperty(content);
		if (property.getKey() == key) {
			break;
		}
	}
	in.close();
	return property;
}
void PropertiesManager::initProperties() {
	addProperty(userCountKey, to_string(0));
	addProperty(groceryCountKey, to_string(0));
	addProperty(itemCountKey, to_string(0));
}
int PropertiesManager::ifPropertyExists(string key) {
	string content = "";
	Property property;
	ifstream in(propertyFileName);
	for (int i = 0; i < PROPERTY_COUNT; i++) {
		in >> content;
		if (content == "") {
			break;
		}
		property.setProperty(content);
		if (property.getKey() == key) {
			return 0;
		}
	}
	in.close();
	return -1;
}
int PropertiesManager::readPropertyAsInteger(string key) {
	Property property = readProperty(key);
	if (property.getKey() != "") {
		return stoi(property.getValue());
	}
	return -1;
}
void PropertiesManager::resetItemCount() {
	updateProperty(itemCountKey, to_string(0));
}
