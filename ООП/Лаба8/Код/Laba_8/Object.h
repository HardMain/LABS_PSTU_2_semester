#pragma once
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Object
{
public:
	Object() {};
	virtual ~Object() {};

	virtual void show() = 0;
	virtual void input() = 0;
	virtual string getName() = 0;
};