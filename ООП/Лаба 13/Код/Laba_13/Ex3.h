#pragma once

#include <map>
#include <algorithm>

typedef map<int, Pair> m_p;

istream& operator>>(istream& in, pair<int, Pair>& p)
{
	cout << "key: "; in >> p.first;
	cout << "\t[input Pair]\n"; in >> p.second;
	return in;
}
ostream& operator<<(ostream& out, const pair<int, Pair>& p)
{
	cout << p.first << " " << p.second;
	return out;
}

void fill_map(m_p& lst)
{
	int n;
	cout << "Input size: "; cin >> n; cout << endl;

	for (size_t i = 0; i < n; i++)
	{
		Pair p((rand() % 300 - 50) / 10, (double)(rand() % 300 - 50) / 10);
		int m = rand() % (n * 4);

		auto check = lst.emplace(m, p);
		if (check.second == false)
			--i;
	}
}
void show_map(m_p& lst, const string& message = "")
{
	cout << message;
	for_each(lst.begin(), lst.end(), [](const pair<int, Pair>& p) { cout << p.first << " " << p.second << endl; });
}
int add_average(m_p& lst)
{
	pair<int, Pair> temp;
	for_each(lst.begin(), lst.end(), [&temp](const pair<int, Pair>& p) { temp.first += p.first; temp.second = temp.second + p.second; });
	auto check = lst.emplace(temp.first / lst.size(), temp.second / lst.size());
	if (check.second == false)
		return -1;
}
void find_el(m_p& lst)
{
	cout << endl;
	pair<int, Pair> p;
	cin >> p;

	if (find_if(lst.begin(), lst.end(), [&p](const pair<int, Pair>& p2) { return (p.first == p2.first && p.second == p2.second); }) != lst.end())
		cout << "\n-> element: " << p << " - was found!\n";
	else
		cout << "\n-> element: " << p << " - not found!\n";
}

void foo3()
{
	system("cls");

	cout << "\t\t\tEXERCISE 3\n\n";
	srand(time(0));
	map<int, Pair> lst;
	string message;

	fill_map(lst);
	message = "---------------------- [initial map] ----------------------\n\n";
	show_map(lst, message);

	message = "\n--------------------- [map + average] ---------------------\n\n";
	auto p = add_average(lst);
	show_map(lst, message);
	if (p == -1)
		cout << "\n-> average can't be add for key!\n";

	message = "\n---------------------- [find_el from list] ----------------------\n\n";
	show_map(lst, message);
	find_el(lst);

	cout << endl;
	system("pause");
}