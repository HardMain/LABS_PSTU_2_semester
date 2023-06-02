#pragma once
#include "Object.h"

class Print : public Object
{
protected:
	string name;
	string author;

public:
	Print();
	Print(const Print& object);
	~Print();

	void setName(string name) { this->name = name; };
	void setAuthor(string author) { this->author = author; };
	string getName() override { return name; };
	string getAuthor() { return author; };

	Print& operator=(const Print& object);

	void show() override;
	void input() override;
};