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

	int get_first() { return first; }
	double get_second() { return second; }
	void set_first(int first) { this->first = first; }
	void set_second(double second) { this->second = second; }

	Pair operator-(const Pair& pair) const;
	Pair operator+(const Pair& pair) const;
	Pair operator+(const int data) const;
	Pair operator+(const double data) const;
	Pair& operator++();
	Pair operator++(int);
	Pair operator/(double n);
	Pair& operator=(const Pair& pair);
	bool operator<(const Pair& pair) const;
	bool operator>(const Pair& pair) const;

	~Pair();

};