#include "List.h"
#include "Error.h"

// 3 realizations

int main()
{
	system("color F0");
	system("chcp 1251 >> null");

	try
	{
		List lst;
		lst.pop_back();

		/*List lst;
		lst.push_back(10);
		lst[1];*/

		/*List lst;
		cout << lst[0];*/

		//List lst;
		//lst.push_back(10);
		//lst.show_list();
	}
	catch (Error &err)
	{
		err.what();
	}

	return 0;
}