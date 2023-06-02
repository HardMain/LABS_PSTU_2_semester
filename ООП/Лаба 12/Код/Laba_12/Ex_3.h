#pragma once

#include <iostream>
#include <set>
#include <string>
using namespace std;

template <typename T>
class List_3
{
private:
	multiset<T> st;
	int len;
public:
	List_3();
	List_3(int n);
	~List_3();

	void make_list();
	void show();
	void average();
	void remove();
	void add_min_max();

	int get_size() { return size; }

	List_3& operator=(const List_3& object);
};

template <typename T>
List_3<T>::List_3()
{
	len = 0;
}
template<typename T>
List_3<T>::List_3(int n)
{
	T a;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a;
		st.push();
	}
}
template <typename T>
List_3<T>::~List_3()
{
}

template<typename T>
void List_3<T>::make_list()
{
	int n;
	cout << "Input size: "; cin >> n; cout << endl;

	T a;
	for (size_t i = 0; i < n; i++)
	{
		a.set_first((int)(rand() % 500 - 50) / 10);
		a.set_second((double)(rand() % 500 - 50) / 10);
		st.insert(a);
	}
	len = st.size();
}
template<typename T>
void List_3<T>::show()
{
	if (len != 0)
	{
		cout << "multiset: ";
		for (auto& i : st)
			cout << i << " ";
		cout << endl;
	}
}
template<typename T>
void List_3<T>::average()
{
	if (len != 0)
	{
		int av_first = 0;
		double av_second = 0;

		Pair temp;
		for (auto& i : st)
		{
			temp = i;
			av_first += temp.get_first();
			av_second += temp.get_second();
		}

		av_first /= st.size();
		av_second /= st.size();
		temp.set_first(av_first);
		temp.set_second(av_second);

		st.insert(temp);
	}
}
template<typename T>
void List_3<T>::remove()
{
	if (len != 0)
	{
		Pair start, end;
		cout << "\n\t[Start position]\n"; cin >> start;
		cout << "\t[End position]\n"; cin >> end;

		Pair temp;
		for (auto i = st.begin(); i != st.end();)
		{
			temp = *i;
			if ((start.get_first() <= temp.get_first() && start.get_second() <= temp.get_second()) && (temp.get_first() <= end.get_first() && temp.get_second() <= end.get_second()))
				i = st.erase(i);
			else
				++i;
		}
	}
}
template<typename T>
void List_3<T>::add_min_max()
{
	if (len != 0)
	{
		Pair p_min, p_max;
		Pair tempP = *st.begin();

		p_max.set_first(tempP.get_first());
		p_max.set_second(tempP.get_second());
		p_min.set_first(tempP.get_first());
		p_min.set_second(tempP.get_second());

		for (auto& i : st)
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
		for (auto& i : st)
		{
			tempP = i;
			tempP2.set_first(tempP.get_first() + p_max.get_first() + p_min.get_first());
			tempP2.set_second(tempP.get_second() + p_max.get_second() + p_min.get_second());

			tempM.insert(tempP2);
		}
		st = tempM;
	}
}

template <typename T>
List_3<T>& List_3<T>::operator=(const List_3& object)
{
	if (this != &object)
		if (this->head != nullptr)
		{
			this->~List_3();
			for (int i = 0; i < object.size; i++)
				this->push_back(object[i]);
		}
		else
			for (int i = 0; i < object.size; i++)
				this->push_back(object[i]);
	return *this;
}

void foo_3()
{
	system("cls");

	cout << "\t\t\tEXERCISE 3\n\n";
	srand(time(0));
	List_3<Pair> lst5;

	lst5.make_list();
	cout << "---------------------- [initial multiset] ----------------------\n";
	lst5.show();

	lst5.average();
	cout << "\n--------------------- [multiset + average] ---------------------\n";
	lst5.show();

	lst5.remove();
	cout << "\n------------------- [multiset after deletion] ------------------\n";
	lst5.show();

	lst5.add_min_max();
	cout << "\n------------------- [multiset + (min + max)] -------------------\n";
	lst5.show();

	cout << endl;
	system("pause");
}