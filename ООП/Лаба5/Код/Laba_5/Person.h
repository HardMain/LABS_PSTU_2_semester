#pragma once

#include "Objects.h"

class Person : public Object
{
	friend ostream& operator<<(ostream& out, const Person& object);
	friend class Student;
private:
	string name;
	int age;
public:
	Person();
	Person(string name, int age);
	Person(const Person& object);
	~Person() override;

	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; }

	string getName() { return name; }
	int getAge() { return age; }

	void showData() override;
	void inputData() override;
};

