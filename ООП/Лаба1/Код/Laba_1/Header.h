#pragma once
#include <iostream>
using namespace std;

class arithmetic
{
private:
	double first;
	int second;
public:
	arithmetic();
	arithmetic(double first, int second);
	arithmetic(arithmetic const& object);

	double element(int j);
	void setFirst(double first);
	void setSecond(int second);
	double getFirst();
	int getSecond();

	~arithmetic();
};