#include "Header.h"

ostream& operator<<(ostream &os, const Salary &salary)
{
	cout << "full_name: " << salary.full_name << endl;
	cout << "salary: " << salary.salary << endl;
	cout << "premium: " << salary.prem << endl;
	return os;
}

int main()
{
	system("color F0");
	system("chcp 1251 >> null");

	Salary zp1;
	cout << zp1 << endl;

	string full_name;
	double salary;
	int percent;
	cout << "Enter the full name of the employee: "; getline(cin, full_name);
	cout << "Enter employee's salary: "; cin >> salary;
	cout << "Enter percentage of salary to pay bonus: "; cin >> percent; cout << endl;

	Salary zp2(full_name, salary, percent);
	cout << zp2 << endl;	
	
	Salary zp3 = zp1;
	cout << zp3 << endl;

	system("pause");
	return 0;
}