#pragma once

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{
	friend class Student;
private:
	string name;
	int age;
public:
	Person();
	Person(string name, int age);
	Person(const Person& object);
	~Person();

	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; }

	string getName() { return name; }
	int getAge() { return age; }

	virtual void showData();
	virtual void inputData();
};

