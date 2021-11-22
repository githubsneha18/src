//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#ifndef GROCERYMANAGEMENT_HELPERS_FILEHANDLER_H_
#define GROCERYMANAGEMENT_HELPERS_FILEHANDLER_H_
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class FileHandler {
	string content;
protected:
	void appendToContent(string);
	void replaceSpacesWithUnderscores(string&);
	void replaceUnderscoresWithSpaces(string&);
	void appendToContent(int);
	void appendToContent(float);
	void appendToContent(double);
	void clearContent();
	int readInteger(string);
	float readFloat(string);
	double readDouble(string);
	string getToken();
	virtual void createContent() = 0;
	virtual void createObject() = 0;
	int checkReturn(string);
	string readString();
	string readStringWithoutSpace();
public:
	FileHandler();
	virtual ~FileHandler();
	const string& getContent() const {
		return content;
	}
	void setContent(const string& content) {
		this->content = content;
	}
};
#endif /* GROCERYMANAGEMENT_HELPERS_FILEHANDLER_H_ */
