#pragma once

#include <list>
#include <algorithm>
#include <ctime>

void fill_list(list<Pair>& lst)
{
	int n;
	cout << "Input size: "; cin >> n; cout << endl;

	for (size_t i = 0; i < n; i++)
	{
		Pair p((rand() % 300 - 50) / 10, (double)(rand() % 300 - 50) / 10);
		lst.push_back(p);
	}
}
void show_list(const list<Pair>& lst)
{
	if (!lst.empty())
	{
		cout << "List: ";
		for_each(lst.begin(), lst.end(), [](const Pair& p) { cout << p << " "; });
		cout << endl;
	}
}
void add_average(list<Pair>& lst)
{
	if (!lst.empty())
	{
		Pair temp;
		for_each(lst.begin(), lst.end(), [&temp](const Pair& p) {temp = temp + p; });
		lst.push_back(temp / lst.size());
	}
}
void find_el(list<Pair>& lst)
{
	if (!lst.empty())
	{
		Pair temp;
		cout << "\n\t[Input Pair]\n"; cin >> temp;
		if (find(lst.begin(), lst.end(), temp) != lst.end())
			cout << "\nelement: " << temp << " - was found\n";
		else
			cout << "\nelement: " << temp << " - not found\n";
	}
}
void del(list<Pair>& lst)
{
	if (!lst.empty())
	{
		Pair start, end;
		cout << "\n\t[Start position]\n"; cin >> start;
		cout << "\t[End position]\n"; cin >> end;

		auto it = remove_if(lst.begin(), lst.end(), [&start, &end](const Pair& p) { return (start < p && p < end); });
		lst.erase(it, lst.end());
	}
}
void add_min_max(list<Pair>& lst)
{
	if (!lst.empty())
	{
		Pair itMin = *min_element(lst.begin(), lst.end());
		Pair itMax = *max_element(lst.begin(), lst.end());

		for_each(lst.begin(), lst.end(), [&itMin, &itMax](Pair& p) { p = p + itMin + itMax; });
	}
}

void foo1()
{
	system("cls");

	cout << "\t\t\tEXERCISE 1\n\n";
	srand(time(0));
	list<Pair> lst;

	fill_list(lst);
	cout << "---------------------- [initial list] ----------------------\n";
	show_list(lst);

	cout << "\n---------------------- [find_el from list] ----------------------\n";
	find_el(lst);

	add_average(lst);
	cout << "\n--------------------- [list + average] ---------------------\n";
	show_list(lst);

	del(lst);
	cout << "\n------------------- [list after deletion] ------------------\n";
	show_list(lst);

	add_min_max(lst);
	cout << "\n------------------- [list + (min + max)] -------------------\n";
	show_list(lst);

	lst.sort([](const Pair& p, const Pair& p2) { return p > p2; });
	cout << "\n------------------- [descending list] -------------------\n";
	show_list(lst);

	lst.sort();
	cout << "\n------------------- [ascending list] -------------------\n";
	show_list(lst);

	cout << endl;
	system("pause");
}