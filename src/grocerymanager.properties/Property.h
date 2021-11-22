//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#ifndef GROCERYMANAGEMENT_PROPERTIES_PROPERTY_H_
#define GROCERYMANAGEMENT_PROPERTIES_PROPERTY_H_
#include "Property.h"

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Property {
	string key;
	string value;
public:
	Property();
	Property(string);
	Property(string, string);
	virtual ~Property();
	string getProperty();
	void setProperty(string);
	const string& getKey() const {
		return key;
	}
	const string& getValue() const {
		return value;
	}
	void setValue(const string& value) {
		this->value = value;
	}
	friend std::ostream & operator <<(std::ostream &out, Property &property) {
		out << property.getProperty() << endl;
		return out;
	}
	friend std::istream & operator >>(std::istream &in, Property &property) {
		std::string content;
		in >> content;
		property.setProperty(content);
		return in;
	}
};
#endif /* GROCERYMANAGEMENT_PROPERTIES_PROPERTY_H_ */
