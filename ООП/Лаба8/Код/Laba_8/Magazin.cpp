#include "Magazin.h"

Magazine::Magazine() : Print()
{
	pages = 0;
}
Magazine::Magazine(const Magazine& object) : Print(object)
{
	this->pages = object.pages;
}
Magazine::~Magazine()
{
}

Magazine& Magazine::operator=(const Magazine& object)
{
	if (this == &object)
		return *this;
	this->pages = object.pages;
	this->name = object.name;
	this->author = object.author;
	return *this;
}

void Magazine::show()
{
	cout << "Name: " << name;
	cout << "\nAuthor: " << author;
	cout << "\nPages: " << pages;
	cout << endl;
}
void Magazine::input()
{
	cout << "Name(str): "; cin >> name;
	cout << "Author(str): "; cin >> author;
	cout << "Pages(int): "; cin >> pages;
}

