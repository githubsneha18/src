//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#ifndef GROCERYMANAGEMENT_PROPERTIES_PROPERTIESMANAGER_H_
#define GROCERYMANAGEMENT_PROPERTIES_PROPERTIESMANAGER_H_
#define PROPERTY_COUNT 3
#include <string>
#include <fstream>

#include "Property.h"
using namespace std;

class PropertiesManager {
	char* propertyFileName = "property.txt";
	char* tempFileName = "propertytemp.txt";
	string userCountKey;
	string groceryCountKey;
	string itemCountKey;
	void initProperties();
public:
	PropertiesManager();
	virtual ~PropertiesManager();
	int ifPropertyExists(string);
	int addProperty(string, string);
	int updateProperty(string, string);
	int deleteProperty(string);
	Property readProperty(string);
	int readPropertyAsInteger(string);
	void resetItemCount();
	const string& getGroceryCountKey() const {
		return groceryCountKey;
	}
	const string& getUserCountKey() const {
		return userCountKey;
	}
	const string& getItemCountKey() const {
		return itemCountKey;
	}
};

#endif /* GROCERYMANAGEMENT_PROPERTIES_PROPERTIESMANAGER_H_ */
