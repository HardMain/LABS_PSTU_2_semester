#pragma once

#include "Person.h";

class Student : public Person
{
private:
	string subject;
	int grade;
public:
	Student();
	Student(string name, int age, string subject, int grade);
	Student(const Student& object);
	~Student() override;

	void setName(string subject) { this->subject = subject; }
	void setAge(int grade) { this->grade = grade; }

	string getSubject() { return subject; }
	int getGrade() { return grade; }

	void gradeCheck();
	void showData() override;
	void inputData() override;

};

