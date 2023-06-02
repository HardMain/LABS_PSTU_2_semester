#pragma once

#include "Objects.h"

class Vector
{
	friend ostream& operator<<(ostream& out, const Vector& object);
private:
	Object** beg;
	int size;
	int cur;
public:
	Vector();
	Vector(int n);
	void Add(Object *p);
	~Vector();
};

