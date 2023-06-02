#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

class Pair
{
	friend ostream& operator<<(ostream& out, const Pair& ob);
	friend istream& operator>>(istream& in, Pair& ob);
private:
	int first;
	double second;
public:
	Pair();
	Pair(int first, double second);
	Pair(const Pair& ob);
	~Pair();

	Pair operator-(Pair& pair) const;
	Pair operator+(Pair& pair) const;
	Pair operator+(const int data) const;
	Pair operator+(const double data) const;
	Pair& operator++();
	Pair operator++(int);
	Pair operator*(Pair& pair);
	Pair& operator=(const Pair& pair);
};