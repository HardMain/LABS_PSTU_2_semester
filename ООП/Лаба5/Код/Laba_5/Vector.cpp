#include "Vector.h"

Vector::Vector()
{
	beg = nullptr;
	size = 0;
	cur = 0;
}

Vector::Vector(int n)
{
	if (n > 0)
	{
		beg = new Object * [n];
		cur = 0;
		size = n;
	}
	else
	{
		cout << "\nVector creation error!\n";
		Vector();
	}
}

void Vector::Add(Object *p)
{
	if (cur < size)
	{
		beg[cur] = p;
		++cur;
	}
}

Vector::~Vector()
{
	if (size != 0) delete[] beg;
	beg = 0;
}