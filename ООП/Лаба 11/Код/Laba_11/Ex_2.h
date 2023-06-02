#pragma once

typedef list<Pair> lst2;

void fill_list(lst2& l)
{
	int n = 0;
	Pair p;
	cout << "Input size: "; cin >> n; cout << endl;
	for (size_t i = 0; i < n; i++)
	{
		p.set_first((int)(rand() % 500 - 50) / 10);
		p.set_second((double)(rand() % 500 - 50) / 10);
		l.push_back(p);
	}
}
void show_list(lst2& l)
{
	if (l.size() != 0)
	{
		cout << "List: ";
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
		for (auto& i : l)
		{
			av_first += i.get_first();
			av_second += i.get_second();
		}
		av_first /= l.size();
		av_second /= l.size();
		Pair p(av_first, av_second);
		l.push_back(p);
	}
}
void remove(lst2& l)
{
	if (l.size() != 0)
	{
		Pair start, end;
		cout << "\n\t[Start position]\n"; cin >> start;
		cout << "\t[End position]\n"; cin >> end;
		for (auto i = l.begin(); i != l.end();)
		{
			if ((start.get_first() <= (*i).get_first() && start.get_second() <= (*i).get_second()) && ((*i).get_first() <= end.get_first() && (*i).get_second() <= end.get_second()))
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
		auto i = l.begin();

		p_max.set_first((*i).get_first());
		p_max.set_second((*i).get_second());
		p_min.set_first((*i).get_first());
		p_min.set_second((*i).get_second());

		for (auto& i : l)
		{
			if ((p_max.get_first() + p_max.get_second()) < (i.get_first() + i.get_second()))
			{
				p_max.set_first(i.get_first());
				p_max.set_second(i.get_second());
			}
			else if ((p_min.get_first() + p_min.get_second()) > (i.get_first() + i.get_second()))
			{
				p_min.set_first(i.get_first());
				p_min.set_second(i.get_second());
			}
		}
		for (auto& i : l)
		{
			i = i + (p_max.get_first() + p_min.get_first());
			i = i + (p_max.get_second() + p_min.get_second());
		}
	}
}

void foo_2()
{
	system("cls");

	cout << "\t\t\tEXERCISE 2\n\n";
	srand(time(0));
	list<Pair> lst2;
	
	fill_list(lst2);
	cout << "---------------------- [initial list] ----------------------\n";
	show_list(lst2);

	average(lst2);
	cout << "\n--------------------- [list + average] ---------------------\n";
	show_list(lst2);

	remove(lst2);
	cout << "\n------------------- [list after deletion] ------------------\n";
	show_list(lst2);

	add_min_max(lst2);
	cout << "\n------------------- [list + (min + max)] -------------------\n";
	show_list(lst2);

	cout << endl;
	system("pause");
}