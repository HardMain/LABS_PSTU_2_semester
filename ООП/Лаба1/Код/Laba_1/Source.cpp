#include "Header.h"

int main()
{
	system("color F0");
	setlocale(0, "");
	arithmetic a;

	double first = 0;
	cout << "Enter the first number of the sequence: "; cin >> first;
	a.setFirst(first);

	double second = 0;
	cout << "Enter sequence divisor: "; cin >> second;
	a.setSecond(second);

	int j;
	cout << "Calculated item number: "; cin >> j;
	cout << j << " element = " << a.element(j) << endl;

	system("pause");

	return 0;
}