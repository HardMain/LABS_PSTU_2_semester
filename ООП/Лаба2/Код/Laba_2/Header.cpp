#include "Header.h"

Salary::Salary()
{
	cout << "The default constructor for the object was called: " << this << endl;
	full_name = "NULL";
	salary = 0;
	percent = 0;
	prem = 0;
}
Salary::Salary(string full_name, double salary, int percent)
{
	cout << "The constructor was called with parameters for the object: " << this << endl;
	this->full_name = full_name;
	this->salary = salary;
	this->percent = percent;
	premium();
}
Salary::Salary(const Salary& object)
{
	cout << "Copy constructor for object called: " << this << endl;
	cout << "Copy object: " << &object << endl;
	this->full_name = object.full_name;
	this->salary = object.salary;
	this->percent = object.percent;
	this->prem = object.prem;
}

void Salary::setFull_name(string full_name)
{
	this->full_name = full_name;
}
void Salary::setSalary(double salary)
{
	this->salary = salary;
}
string Salary::getFull_name()
{
	return full_name;
}
double Salary::getSalary()
{
	return salary;
}
int Salary::getPercent()
{
	return percent;
}
void Salary::setPercent(int percent)
{
	this->percent = percent;
}
double Salary::premium()
{
	prem = (salary / 100) * percent;
	return prem;
}

Salary::~Salary()
{

}
