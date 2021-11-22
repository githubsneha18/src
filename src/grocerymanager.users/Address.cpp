//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#include "Address.h"

Address::Address() {
	addressLine1 = "";
	addressLine2 = "";
	city = "";
	state = "";
	pinCode = "";
}
Address::~Address() {
}
void Address::createContent() {
	appendToContent(addressLine1);
	appendToContent(addressLine2);
	appendToContent(city);
	appendToContent(state);
	appendToContent(pinCode);
}
void Address::createObject() {
	addressLine1 = getToken();
	replaceUnderscoresWithSpaces(addressLine1);
	addressLine2 = getToken();
	replaceUnderscoresWithSpaces(addressLine2);
	city = getToken();
	replaceUnderscoresWithSpaces(city);
	state = getToken();
	replaceUnderscoresWithSpaces(state);
	pinCode = getToken();
}
void Address::readToUpdate() {
	string val = "";
	cout << "Address line 1 ( " << addressLine1 << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->addressLine1 = val;
	}
	cout << "Address line 2 ( " << addressLine2 << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->addressLine2 = val;
	}
	cout << "City ( " << city << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->city = val;
	}
	cout << "State ( " << state << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->state = val;
	}
}
void Address::readAddress() {
	cout << "Address line 1 : ";
	addressLine1 = readString();
	cout << "Address line 2 : ";
	addressLine2 = readString();
	cout << "City : ";
	city = readString();
	cout << "State : ";
	state = readString();
	cout << "Pin Code : ";
	pinCode = readString();
}
void Address::displayAddress() {
	cout << setw(20) << addressLine1 << setw(20) << addressLine2;
	cout << setw(20) << city << setw(20) << state << setw(10) << pinCode << endl;
}
int Address::update() {
	cout
			<< "Type in details for relevant field(s) or press return key to skip : "
			<< endl;
	readToUpdate();
	return 0;
}
void Address::setAddress(string content){
	setContent(content);
	createObject();
}
string Address::getAddress(){
	createContent();
	string addressString = getContent();
	return addressString.substr(0, addressString.length() - 1);
}

