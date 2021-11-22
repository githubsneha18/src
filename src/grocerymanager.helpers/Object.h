//============================================================================
// Name        : Grocery_Management.cpp
// Author      : Sneha Priyanshu
// Version     :
// Copyright   : Your copyright notice
// Description : Grocery_Management in C++
//============================================================================

#ifndef GROCERYMANAGEMENT_HELPERS_OBJECT_H_
#define GROCERYMANAGEMENT_HELPERS_OBJECT_H_
#include <string>
using namespace std;

class Object {
protected:
	virtual void read() = 0;
	virtual void readToUpdate() = 0;
	virtual void display() = 0;
	virtual void displayAll() = 0;
	virtual int add() = 0;
	virtual int update() = 0;
	virtual int erase() = 0;
	virtual int search(string) = 0;
public:
	Object();
	virtual ~Object();
};
#endif /* GROCERYMANAGEMENT_HELPERS_OBJECT_H_ */
