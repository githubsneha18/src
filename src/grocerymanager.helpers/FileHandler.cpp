//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#include "FileHandler.h"

FileHandler::FileHandler() {
	content = "";
}
FileHandler::~FileHandler() {
}
void FileHandler::appendToContent(string value) {
	int pos = value.find(' ');
	if (pos >= 0) {
		replaceSpacesWithUnderscores(value);
	}
	content.append(value);
	content.append("@");
}
void FileHandler::replaceSpacesWithUnderscores(string& content) {
	replace(content.begin(), content.end(), ' ', '_');
}
void FileHandler::replaceUnderscoresWithSpaces(string& content) {
	replace(content.begin(), content.end(), '_', ' ');
}
void FileHandler::appendToContent(int value) {
	content.append(to_string(value));
	content.append("@");
}
void FileHandler::appendToContent(float value) {
	content.append(to_string(value));
	content.append("@");
}
void FileHandler::appendToContent(double value) {
	content.append(to_string(value));
	content.append("@");
}
void FileHandler::clearContent() {
	content = "";
}
int FileHandler::readInteger(string value) {
	int val = 0;
	try {
		val = stoi(value);
	} catch (int x) {
		cout << "Number-format-exception" << endl;
	}
	return val;
}
float FileHandler::readFloat(string value) {
	float val = 0.0F;
	try {
		val = stof(value);
	} catch (int x) {
		cout << "Number-format-exception" << endl;
	}
	return val;
}
double FileHandler::readDouble(string value) {
	double val = 0.0F;
	try {
		val = stod(value);
	} catch (int x) {
		cout << "Number-format-exception" << endl;
	}
	return val;
}
string FileHandler::getToken() {
	int pos = content.find('@');
	string token = content.substr(0, pos);
	content = content.substr(pos + 1, content.length() - 1);
	return token;
}
int FileHandler::checkReturn(string value) {
	if (value == "") {
		return 0;
	}
	return -1;
}
string FileHandler::readString() {
	string value;
	cin.clear();
	getline(cin, value);
	return value;
}
string FileHandler::readStringWithoutSpace() {
	string value;
	int pos = -1;
	do {
		value = readString();
		pos = value.find(' ');
		if(0 <= pos && pos <= value.length()){
			cout << "Spaces not allowed !" << endl << "# ";
		}
	} while (0 <= pos && pos <= value.length());
	return value;
}

