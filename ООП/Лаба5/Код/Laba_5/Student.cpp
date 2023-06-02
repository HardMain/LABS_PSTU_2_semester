#pragma once

#include "Student.h"

Student::Student() : Person()
{
	subject = "null";
	grade = 0;
}
Student::Student(string name, int age, string subject, int grade) : Person(name, age)
{
	this->subject = subject;
	this->grade = grade;
}
Student::Student(const Student& object) : Person(object)
{
	this->subject = object.subject;
	this->grade = object.grade;
}
Student::~Student()
{
}

void Student::gradeCheck()
{
	if (grade > 2)
		cout << "The grade is satisfactory!" << endl;
	else
		cout << "Unsatisfactory grade!" << endl;
}
void Student::showData()
{
	cout << "name:    " << name << endl;
	cout << "age:     " << age << endl;
	cout << "subject: " << subject << endl;
	cout << "grade:   " << grade << endl;
}
void Student::inputData()
{
	cout << "Enter student name: "; cin >> name;
	cout << "Enter the student's age: "; cin >> age;
	cout << "Enter the subject to be graded: "; cin >> subject;
	cout << "Grade in this subject: "; cin >> grade;
}