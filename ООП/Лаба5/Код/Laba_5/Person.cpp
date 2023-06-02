#pragma once

#include "Person.h"

Person::Person()
{
	name = "null";
	age = 0;
}
Person::Person(string name, int age)
{
	this->name = name;
	this->age = age;
}
Person::Person(const Person& object)
{
	this->age = object.age;
	this->name = object.name;
}
Person::~Person()
{
}

void Person::showData()
{
	cout << "name: " << name << endl;
	cout << "age:  " << age << endl;
}
void Person::inputData()
{
	cout << "Input name: "; cin >> name;
	cout << "Input age: "; cin >> age;
}