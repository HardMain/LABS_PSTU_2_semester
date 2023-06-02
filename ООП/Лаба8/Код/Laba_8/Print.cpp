#include "Print.h"

Print::Print()
{
	name = "NULL";
	author = "NULL";
}
Print::Print(const Print& object)
{
	this->name = object.name;
	this->author = object.author;
}
Print::~Print()
{
}

Print& Print::operator=(const Print& object)
{
	if (this == &object)
		return *this;
	this->name = object.name;
	this->author = object.author;
	return *this;
}

void Print::show()
{
	cout << "Name: " << name;
	cout << "\nAuthor: " << author;
	cout << endl;
}
void Print::input()
{
	cout << "Name(str): "; cin >> name;
	cout << "Author(str): "; cin >> author;
}