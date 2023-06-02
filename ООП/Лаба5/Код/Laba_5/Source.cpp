#pragma once

#include "Objects.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"

ostream& operator<<(ostream& out, Person& object)
{
	object.showData();
	return out;
}
ostream& operator<<(ostream& out, const Vector& object)
{
	if (object.beg == nullptr) 
	{
		out << "Empty!" << endl;
		return out;
	}
	Object** p = object.beg;
	for (size_t i = 0; i < object.cur; i++)
	{
		cout << "(" << i + 1 << ")" << endl;
		(*p++)->showData();
		cout << endl;
	}
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

	Student student_1, student_2;
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

	cin >> student_2;

	cout << "___________________________________\n\n";
	cout << student_2;
	student_2.gradeCheck();
	cout << "___________________________________\n\n";

	Vector v(3);

	v.Add(&student_1);
	v.Add(&human_1);
	v.Add(&student_2);

	cout << "\n---------- Vector output ----------\n" << v;

	return 0;
}