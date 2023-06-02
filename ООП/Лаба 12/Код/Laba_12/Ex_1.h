#pragma once

typedef multiset<double> lst;

void fill_list(lst& l)
{
	int n = 0;
	double el = 0;
	cout << "Input size: "; cin >> n; cout << endl;
	for (size_t i = 0; i < n; i++)
		l.insert((double)(rand() % 500 - 50) / 10);
}
void show_list(lst& l)
{
	if (l.size() != 0)
	{
		cout << "multiset: ";
		for (auto& i : l)
			cout << i << " ";
		cout << endl;
	}
}
void average(lst& l)
{
	if (l.size() != 0)
	{
		double av = 0;
		for (auto& i : l)
			av += i;
		l.insert(av / l.size());
	}
}
void remove(lst& l)
{
	if (l.size() != 0)
	{
		double start, end;
		cout << "\nStart position: "; cin >> start;
		cout << "End position: "; cin >> end;
		for (auto i = l.begin(); i != l.end();)
		{
			if (start <= *i && *i <= end)
				i = l.erase(i);
			else
				++i;
		}
	}
}
void add_min_max(lst& l)
{
	if (l.size() != 0)
	{
		double min = *l.begin(), max = *l.begin();
		for (auto& i : l)
		{
			if (i > max)
				max = i;
			if (i < min)
				min = i;
		}
		lst temp;
		for (auto& i : l)
			temp.insert(i + max + min);
		l = temp;
	}
}

void foo_1()
{
	cout << "\t\t\tEXERCISE 1\n\n";
	srand(time(0));
	lst lst1;

	fill_list(lst1);
	cout << "---------------------- [initial multiset] ----------------------\n";
	show_list(lst1);

	average(lst1);
	cout << "\n--------------------- [multiset + average] ---------------------\n";
	show_list(lst1);

	remove(lst1);
	cout << "\n------------------- [multiset after deletion] ------------------\n";
	show_list(lst1);

	add_min_max(lst1);
	cout << "\n------------------- [multiset + (min + max)] -------------------\n";
	show_list(lst1);

	cout << endl;
	system("pause");
}