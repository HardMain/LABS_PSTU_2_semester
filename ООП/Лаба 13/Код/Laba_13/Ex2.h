#pragma once

#include <queue>

typedef priority_queue<Pair> p_q;

void fill_list(p_q& l)
{
	int n = 0;
	Pair p;
	cout << "Input size: "; cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		p.set_first((int)(rand() % 500 - 50) / 10);
		p.set_second((double)(rand() % 500 - 50) / 10);
		l.emplace(p);
	}
	cout << endl;
}
void show_list(p_q l)
{
	if (l.size() != 0)
	{
		cout << "List: ";
		while (!l.empty())
		{
			cout << l.top() << " ";
			l.pop();
		}
		cout << endl;
	}
}
void average(p_q& l)
{
	p_q temp;
	Pair p;

	if (l.size() != 0)
	{
		int av_first = 0;
		double av_second = 0;
		while (!l.empty())
		{
			p = l.top();
			temp.push(p);
			av_first += p.get_first();
			av_second += p.get_second();
			l.pop();
		}
		av_first /= temp.size();
		av_second /= temp.size();

		p.set_first(av_first);
		p.set_second(av_second);

		l = temp;
		l.push(p);
	}
}
void remove(p_q& l)
{
	if (l.size() != 0)
	{
		Pair start, end;
		cout << "\n\t[Start position]\n"; cin >> start;
		cout << "\t[End position]\n"; cin >> end;

		p_q temp;
		Pair p;
		while (!l.empty())
		{
			p = l.top();
			if (!((start.get_first() <= p.get_first() && start.get_second() <= p.get_second()) && (p.get_first() <= end.get_first() && p.get_second() <= end.get_second())))
				temp.push(p);
			l.pop();
		}
		l = temp;
	}
}
void add_min_max(p_q& l)
{
	if (l.size() != 0)
	{
		Pair p_min, p_max;
		Pair p = l.top();

		p_max.set_first(p.get_first());
		p_max.set_second(p.get_second());
		p_min.set_first(p.get_first());
		p_min.set_second(p.get_second());

		p_q temp;
		while (!l.empty())
		{
			p = l.top();
			temp.push(p);
			if ((p_max.get_first() + p_max.get_second()) < (p.get_first() + p.get_second()))
			{
				p_max.set_first(p.get_first());
				p_max.set_second(p.get_second());
			}
			else if ((p_min.get_first() + p_min.get_second()) > (p.get_first() + p.get_second()))
			{
				p_min.set_first(p.get_first());
				p_min.set_second(p.get_second());
			}
			l.pop();
		}
		while (!temp.empty())
		{
			p = temp.top();
			p = p + p_max.get_first() + p_min.get_first();
			p = p + p_max.get_second() + p_min.get_second();
			l.push(p);
			temp.pop();
		}
	}
}

void foo2()
{
	system("cls");

	cout << "\t\t\tEXERCISE 2\n\n";
	srand(time(0));
	priority_queue<Pair> queue;

	fill_list(queue);
	cout << "---------------------- [initial priority_queue] ----------------------\n";
	show_list(queue);

	average(queue);
	cout << "\n--------------------- [priority_queue + average] ---------------------\n";
	show_list(queue);

	remove(queue);
	cout << "\n------------------- [priority_queue after deletion] ------------------\n";
	show_list(queue);

	add_min_max(queue);
	cout << "\n------------------- [priority_queue + (min + max)] -------------------\n";
	show_list(queue);

	cout << endl;
	system("pause");
}