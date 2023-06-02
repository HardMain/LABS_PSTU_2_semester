#pragma once

#include "Person.h"
#include "Student.h"

ostream& operator<<(ostream& out, Person& object)
{
	object.showData();
	return out;
}
istream& operator>>(istream& in, Person& object)
{
	object.inputData();
	return in;
}

int main()
{
	system("color F0");
	system("chcp 1251 >> null");

	Student student_1;
	Person human_1;

	cin >> student_1;

	cout << "___________________________________\n\n";
	cout << student_1;
	student_1.gradeCheck(); 
	cout << "___________________________________\n\n";

	cin >> human_1;

	cout << "___________________________________\n\n";
	cout << human_1;
	cout << "___________________________________\n\n";

	return 0;
}