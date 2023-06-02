#pragma once
#include "Header.h"

arithmetic::arithmetic()
{
	first = 0;
	second = 0;
}
double arithmetic::element(int j)
{
	return first * pow(second, j-1);
}
void arithmetic::setFirst(double first)
{
	this->first = first;
}
void arithmetic::setSecond(int second)
{
	this->second = second;
}
double arithmetic::getFirst()
{
	return first;
}
int arithmetic::getSecond()
{
	return second;
}
arithmetic::arithmetic(double first, int second)
{
	this->first = first;
	this->second = second;
}
arithmetic::arithmetic(const arithmetic& object)
{
	this->first = object.first;
	this->second = object.second;
}
arithmetic::~arithmetic()
{
	first = 0;
	second = 0;
}