#pragma once

#include <iostream>
#include <queue>
#include <string>
using namespace std;

template <typename T>
class List_5
{
private:
	priority_queue<T> st;
	int len;
public:
	List_5();
	List_5(int n);
	~List_5();

	void make_list();
	void show();
	void average();
	void remove();
	void add_min_max();

	int get_size() { return size; }

	List_5& operator=(const List_5& object);
};

template <typename T>
List_5<T>::List_5()
{
}
template<typename T>
List_5<T>::List_5(int n)
{
	T a;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a;
		st.push();
	}
}
template <typename T>
List_5<T>::~List_5()
{
}

template<typename T>
void List_5<T>::make_list()
{
	int n;
	cout << "Input size: "; cin >> n; cout << endl;

	T a;
	for (size_t i = 0; i < n; i++)
	{
		a.set_first((int)(rand() % 500 - 50) / 10);
		a.set_second((double)(rand() % 500 - 50) / 10);
		st.push(a);
	}
	len = st.size();
}
template<typename T>
void List_5<T>::show()
{
	if (len != 0)
	{
		priority_queue<T> temp;
		for (size_t i = 0; i < len; i++)
		{
			cout << st.top() << " ";
			temp.push(st.top());
			st.pop();
		}
		st = temp;
		cout << endl;
	}
}
template<typename T>
void List_5<T>::average()
{
	if (len != 0)
	{
		T p;
		priority_queue<T> temp;

		for (size_t i = 0; i < len; ++i)
		{
			p = p + st.top();
			temp.push(st.top());
			st.pop();
		}

		p = p / len;
		temp.push(p);
		len = temp.size();
		st = temp;
	}
}
template<typename T>
void List_5<T>::remove()
{
	if (len != 0)
	{
		T start, end;
		cout << "\n\t[Start position]\n"; cin >> start;
		cout << "\t[End position]\n"; cin >> end;

		priority_queue<T> temp;
		T p;
		while (!st.empty())
		{
			p = st.top();
			if (start > p || p > end )
				temp.push(p);
			st.pop();
		}
		st = temp;
		len = st.size();
	}
}
template<typename T>
void List_5<T>::add_min_max()
{
	if (len != 0)
	{
		T p_min, p_max;
		T p = st.top();

		p_max.set_first(p.get_first());
		p_max.set_second(p.get_second());
		p_min.set_first(p.get_first());
		p_min.set_second(p.get_second());

		priority_queue<T> temp;
		while (!st.empty())
		{
			p = st.top();
			temp.push(p);
			if (p_max < p)
			{
				p_max.set_first(p.get_first());
				p_max.set_second(p.get_second());
			}
			else if (p < p_min)
			{
				p_min.set_first(p.get_first());
				p_min.set_second(p.get_second());
			}
			st.pop();
		}
		while (!temp.empty())
		{
			p = temp.top();
			p = p + p_max.get_first() + p_min.get_first();
			p = p + p_max.get_second() + p_min.get_second();
			st.push(p);
			temp.pop();
		}
		len = st.size();
	}
}

template <typename T>
List_5<T>& List_5<T>::operator=(const List_5& object)
{
	if (this != &object)
		if (this->head != nullptr)
		{
			this->~List_5();
			for (int i = 0; i < object.size; i++)
				this->push_back(object[i]);
		}
		else
			for (int i = 0; i < object.size; i++)
				this->push_back(object[i]);
	return *this;
}

typedef List_5<Pair> l_p;

void foo_5()
{
	system("cls");

	cout << "\t\t\tEXERCISE 5\n\n";
	srand(time(0));
	l_p lst5;

	lst5.make_list();
	cout << "---------------------- [initial List] ----------------------\n";
	lst5.show();

	lst5.average();
	cout << "\n--------------------- [List_5 + average] ---------------------\n";
	lst5.show();

	lst5.remove();
	cout << "\n------------------- [List_5 after deletion] ------------------\n";
	lst5.show();

	lst5.add_min_max();
	cout << "\n------------------- [List_5 + (min + max)] -------------------\n";
	lst5.show();

	cout << endl;
	system("pause");
}