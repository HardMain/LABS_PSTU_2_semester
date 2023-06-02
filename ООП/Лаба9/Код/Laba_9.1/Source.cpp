#include "List.h"

// 1 realizations

int main()
{
	system("color F0");
	system("chcp 1251 >> null");

	try
	{
		/*List lst;
		lst.pop_back();*/

		/*List lst;
		cout << lst[0];*/

		/*List lst;
		lst.push_back(10);
		lst[1];*/

		List lst;
		lst.push_back(10);
		lst.show_list();
	}
	catch (int error)
	{
		if (error == 1)
			cout << "Input Error!\n";
		if (error == 2)
			cout << "Out of range!\n";
		if (error == 3)
			cout << "List is empty!\n";
	}

	return 0;
}