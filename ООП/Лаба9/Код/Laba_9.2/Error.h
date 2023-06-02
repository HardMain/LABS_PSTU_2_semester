#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error
{
protected: 
	string msg;
public:
	virtual void what() {};
};

class IndexError : public Error
{
public:
	IndexError() { msg = "Out of range!\n"; };
	void what() override { cout << msg; }
};

class InputError : public Error
{
public:
	InputError() { msg = "Input Error!"; };
	void what() override { cout << msg; }
};

class EmptySizeError : public Error
{
public:
	EmptySizeError() { msg = "List is empty!\n"; };
	void what() override { cout << msg; }
};