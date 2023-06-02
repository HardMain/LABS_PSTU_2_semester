#pragma once

typedef multiset<Pair> lst2;

void fill_list(lst2& l)
{
	int n = 0;
	Pair p;
	cout << "Input size: "; cin >> n; cout << endl;
	for (size_t i = 0; i < n; i++)
	{
		p.set_first((int)(rand() % 500 - 50) / 10);
		p.set_second((double)(rand() % 500 - 50) / 10);
		l.insert(p);
	}
}
void show_list(lst2& l)
{
	if (l.size() != 0)
	{
		cout << "multiset: ";
		for (auto& i : l)
			cout << i << " ";
		cout << endl;
	}
}
void average(lst2& l)
{
	if (l.size() != 0)
	{
		int av_first = 0;
		double av_second = 0;

		Pair temp;
		for (auto& i : l)
		{
			temp = i;
			av_first += temp.get_first();
			av_second += temp.get_second();
		}

		av_first /= l.size();
		av_second /= l.size();
		temp.set_first(av_first);
		temp.set_second(av_second);

		l.insert(temp);
	}
}
void remove(lst2& l)
{
	if (l.size() != 0)
	{
		Pair start, end;
		cout << "\n\t[Start position]\n"; cin >> start;
		cout << "\t[End position]\n"; cin >> end;

		Pair temp;
		for (auto i = l.begin(); i != l.end();)
		{
			temp = *i;
			if ((start.get_first() <= temp.get_first() && start.get_second() <= temp.get_second()) && (temp.get_first() <= end.get_first() && temp.get_second() <= end.get_second()))
				i = l.erase(i);
			else
				++i;
		}
	}
}
void add_min_max(lst2& l)
{
	if (l.size() != 0)
	{
		Pair p_min, p_max;
		Pair tempP = *l.begin();

		p_max.set_first(tempP.get_first());
		p_max.set_second(tempP.get_second());
		p_min.set_first(tempP.get_first());
		p_min.set_second(tempP.get_second());

		for (auto& i : l)
		{
			tempP = i;
			if ((p_max.get_first() + p_max.get_second()) < (tempP.get_first() + tempP.get_second()))
			{
				p_max.set_first(tempP.get_first());
				p_max.set_second(tempP.get_second());
			}
			else if ((p_min.get_first() + p_min.get_second()) > (tempP.get_first() + tempP.get_second()))
			{
				p_min.set_first(tempP.get_first());
				p_min.set_second(tempP.get_second());
			}
		}
		lst2 tempM;
		Pair tempP2;
		for (auto& i : l)
		{
			tempP = i;
			tempP2.set_first(tempP.get_first() + p_max.get_first() + p_min.get_first());
			tempP2.set_second(tempP.get_second() + p_max.get_second() + p_min.get_second());

			tempM.insert(tempP2);
		}
		l = tempM;
	}
}

void foo_2()
{
	system("cls");

	cout << "\t\t\tEXERCISE 2\n\n";
	srand(time(0));
	lst2 lst2;

	fill_list(lst2);
	cout << "---------------------- [initial multiset] ----------------------\n";
	show_list(lst2);

	average(lst2);
	cout << "\n--------------------- [multiset + average] ---------------------\n";
	show_list(lst2);

	remove(lst2);
	cout << "\n------------------- [multiset after deletion] ------------------\n";
	show_list(lst2);

	add_min_max(lst2);
	cout << "\n------------------- [multiset + (min + max)] -------------------\n";
	show_list(lst2);

	cout << endl;
	system("pause");
}