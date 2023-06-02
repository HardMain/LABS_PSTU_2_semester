#pragma once

#include <iostream>
#include <string>
using namespace std;

class Salary
{
	friend ostream& operator<<(ostream& os, const Salary& salary);
private:
	string full_name = "Null";
	double salary = 0;
	int percent = 0;
	double prem = 0;
public:
	Salary();
	Salary(string full_name, double salary, int percent);
	Salary(Salary const& object);

	void setFull_name(string full_name);
	void setSalary(double salary);
	string getFull_name();
	double getSalary();	
	int getPercent();
	void setPercent(int percent);
	double premium();

	~Salary();
};