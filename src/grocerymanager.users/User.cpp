//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#include "User.h"

User::User() {
	name = "";
	userId = "";
	password = "";
	type = "user";
	mobile = "";
}
User::~User() {
}
void User::readToUpdate() {
	string val = "";
	cout << "Name ( " << name << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->name = val;
	}
	cout << "User id ( " << userId << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->userId = readFloat(val);
	}
	cout << "Password ( " << password << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->password = val;
	}
	cout << "Mobile ( " << mobile << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->mobile = val;
	}
	cout << "User type ( " << type << " ) : ";
	val = readString();
	if (checkReturn(val) != 0) {
		this->type = val;
	}
	cout << "Address ( " << endl;
	address.displayAddress();
	cout << " ) : ";
	this->address.update();
}
void User::display() {
	cout << setw(7) << userId << setw(15) << name << setw(15) << mobile << setw(10) << type;
	address.displayAddress();
}
int User::add() {
	User user;
	cout << "Enter User details :" << endl;
	user.read();
	while (search(this->userId) == 0) {
		cout << "User id unavailable, Enter new User id : ";
		string id = readString();
		user.setUserId(id);
	}
	ofstream out(User::userFileName, ios::app);
	out << user;
	out.close();
	updateUserCount(1);
	return 0;
}
int User::getUserCount() {
	PropertiesManager propertyManager;
	string key = propertyManager.getUserCountKey();
	string value = propertyManager.readProperty(key).getValue();
	return readInteger(value);
}
int User::update() {
	cout << "Enter User details (existing) :" << endl;
	cout << "User id : ";
	string id;
	id = readString();
	if (search(id) != 0) {
		return -1;
	}
	ifstream in(User::userFileName);
	ofstream out(User::tempFileName, ios::app);
	User user;
	for (int counter = 0, UserCount = getUserCount(); counter < UserCount;
			counter++) {
		in >> user;
		if (user.userId == id) {
			cout
					<< "Type in details for relevant field(s) or press return key to skip : "
					<< endl;
			user.readToUpdate();
			out << user;
		} else {
			out << user;
		}
	}
	in.close();
	out.close();
	remove(User::userFileName);
	rename(User::tempFileName, User::userFileName);
	return 0;
}
int User::erase() {
	cout << "Enter User details :" << endl;
	cout << "User id : ";
	string id = readString();
	if (search(id) != 0) {
		return -1;
	}
	ifstream in(User::userFileName);
	ofstream out(User::tempFileName, ios::app);
	User User;
	for (int counter = 0, UserCount = getUserCount(); counter < UserCount;
			counter++) {
		in >> User;
		if (User.userId != id) {
			out << User;
		}
	}
	in.close();
	out.close();
	updateUserCount(-1);
	remove(User::userFileName);
	rename(User::tempFileName, User::userFileName);
	return 0;
}
void User::read() {
	cout << "User Id : ";
	this->userId = readString();
	cout << "User name : ";
	this->name = readString();
	cout << "Mobile :";
	this->mobile = readString();
	cout << "Address :" << endl;
	address.readAddress();
	cout << "Type : ";
	this->type = readString();
	cout << "Password :";
	this->password = readString();
}
int User::search(string id) {
	User user;
	ifstream in(userFileName);
	for (int counter = 0, UserCount = getUserCount(); counter < UserCount;
			counter++) {
		in >> user;
		if (user.userId == id) {
			return 0;
		}
	}
	in.close();
	return -1;
}
void User::createContent() {
	appendToContent(userId);
	appendToContent(name);
	appendToContent(mobile);
	appendToContent(type);
	appendToContent(password);
	appendToContent(address.getAddress());
}
void User::createObject() {
	userId = getToken();
	replaceUnderscoresWithSpaces(userId);
	name = getToken();
	replaceUnderscoresWithSpaces(name);
	mobile = getToken();
	type = getToken();
	password = getToken();
	address.setAddress(this->getContent());
}
void User::updateUserCount(int off) {
	PropertiesManager propertyManager;
	string key = propertyManager.getUserCountKey();
	string value = propertyManager.readProperty(key).getValue();
	int UserCount = readInteger(value);
	propertyManager.updateProperty(propertyManager.getUserCountKey(),
			to_string(UserCount + 1));
	if (off == -1) {
		propertyManager.updateProperty(propertyManager.getUserCountKey(),
				to_string(UserCount - 1));
	} else if (off == 1) {
		propertyManager.updateProperty(propertyManager.getUserCountKey(),
				to_string(UserCount + 1));
	}
}
void User::displayAll() {
	User user;
	ifstream in(userFileName);
	cout << setw(7) << "User ID";
	cout << setw(15) << "Name";
	cout << setw(15) << "Mobile";
	cout << setw(10) << "Type";
	cout << setw(20) << "Add_Line1";
	cout << setw(20) << "Add_Line2";
	cout << setw(20) << "City";
	cout << setw(20) << "State";
	cout << setw(10) << "Pincode" << endl;
	for (int counter = 0, userCount = getUserCount(); counter < userCount;
			counter++) {
		in >> user;
		user.display();
	}
	in.close();
}
int User::authenticateUser() {
	if (getUserCount() == 0) {
		cout << "System currently has no user..." << endl;
		cout << "Adding system's first Administrator..." << endl;
		addFirstUser();
	}
	cout << "Logging you in..." << endl;
	cout << "User id : ";
	string id = readString();
	if (search(id) != 0) {
		return -1;
	}
	cout << "Password : ";
	string password = readString();
	ifstream in(User::userFileName);
	User user;
	for (int counter = 0, UserCount = getUserCount(); counter < UserCount;
			counter++) {
		in >> user;
		if (user.userId == id && user.password == password) {
			this->type = user.type;
			this->name = user.name;
			this->userId = user.userId;
			this->mobile = user.mobile;
			this->address = user.address;
			return 0;
		}
	}
	in.close();
	return -1;
}
void User::addFirstUser() {
	User user;
	cout << "Enter User details :" << endl;
	user.read();
	user.type = "ADMIN";
	ofstream out(User::userFileName, ios::app);
	out << user;
	out.close();
	updateUserCount(1);
}

