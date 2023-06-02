#include <iostream>
using namespace std;

#include "Stack.h"

int main()
{
	system("color F0");
	system("chcp 1251 >> null");
	Stack<int> s1;
	s1.push(5);
	s1.push(10);
	s1.push(100);
	s1.pop();
	cout << s1.getSize() << endl;
	s1.top();
	return 0;
}