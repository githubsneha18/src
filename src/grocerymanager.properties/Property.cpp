//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#include "Property.h"

Property::Property() {
	this->key = "";
	this->value = "";
}
Property::Property(string content) {
	key = content.substr(0, content.find('='));
	value = content.substr(content.find('=') + 1, (content.length() - 1));
}
Property::Property(string key, string value) {
	this->key = key;
	this->value = value;
}
Property::~Property() {
}
string Property::getProperty() {
	string content = key;
	content.append("=");
	content.append(value);
	return content;
}
void Property::setProperty(string content) {
	key = content.substr(0, content.find('='));
	value = content.substr(content.find('=') + 1, (content.length() - 1));
}
