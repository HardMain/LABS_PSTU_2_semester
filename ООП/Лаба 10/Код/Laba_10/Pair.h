#pragma once

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;

class Pair
{
	friend ostream& operator<<(ostream& out, const Pair& ob);
	friend istream& operator>>(istream& in, Pair& ob);

	friend fstream& operator>>(fstream& fin, Pair& ob);
	friend fstream& operator<<(fstream& fout, const Pair& ob);

	friend void print_file(const string& path, const int& count);
	friend int del_from_file(const string& path, const int& count);
	friend void add_number(const string& path, const int& count);
private:
	int first;
	double second;
public:
	Pair();
	Pair(int first, double second);
	Pair(const Pair& ob);
	Pair operator-(Pair& pair) const;
	Pair operator+(const int data) const;
	Pair operator+(const double data) const;
	Pair& operator=(const Pair& pair);

	~Pair();
};

