//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#ifndef GROCERYMANAGER_USERS_USER_H_
#define GROCERYMANAGER_USERS_USER_H_
#include "../grocerymanager.helpers/Object.h"
#include "../grocerymanager.helpers/FileHandler.h"
#include "../grocerymanager.properties/PropertiesManager.h"
#include "Address.h"
#include <iomanip>

class User: private FileHandler, private Object {
	char* userFileName = "user.txt";
	char* tempFileName = "userTemp.txt";
	string name;
	string userId;
	string password;
	string mobile;
	string type;
	Address address;
	void display();
	void readToUpdate();
	void createContent();
	void createObject();
	int getUserCount();
	int search(string);
	void updateUserCount(int);
	void addFirstUser();
public:
	User();
	virtual ~User();
	void read();
	int add();
	int update();
	int erase();
	void displayAll();
	int authenticateUser();
	friend std::ostream & operator <<(std::ostream &out, User &user) {
		user.clearContent();
		user.createContent();
		string content = user.getContent();
		out << content << endl;
		return out;
	}
	friend std::istream & operator >>(std::istream &in, User &user) {
		string content;
		in >> content;
		user.setContent(content);
		user.createObject();
		return in;
	}
	void setUserId(const string& userId) {
		this->userId = userId;
	}
	const string& getType() const {
		return type;
	}
};
#endif /* GROCERYMANAGER_USERS_USER_H_ */
