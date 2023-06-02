#pragma once

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Object
{
public:
	Object() {};
	virtual void showData() = 0;
	virtual void inputData() = 0;
	virtual ~Object() = 0;
};

