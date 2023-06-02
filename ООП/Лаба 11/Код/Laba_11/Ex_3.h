#pragma once

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List_3
{
private:
	class Node
	{
		friend class List_3;
	public:
		Node(T data);

		T data;
		Node* pnext = nullptr;
		Node* pprev = nullptr;
	};
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	class Iterator
	{
		friend class List_3;
	private:
		Node* it = nullptr;
	public:
		Iterator();
		Iterator(const Iterator& it);

		bool operator==(const Iterator& it);
		bool operator!=(const Iterator& it);
		void operator++();
		void operator--();
		Iterator& operator=(const Iterator& it);
		T& operator*();
	};
	List_3();
	List_3(List_3& object);
	~List_3();

	void push_back(T data);
	Iterator erase(Iterator& it);
	int get_size() { return size; }

	void fill_List_3();
	void show_List_3();
	void average();
	void remove();
	void add_min_max();

	List_3& operator=(const List_3& object);

	Iterator& begin();
	Iterator& end();
private:
	Iterator pbeg;
	Iterator pend;
};

template <typename T>
List_3<T>::List_3()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template <typename T>
List_3<T>::List_3(List_3& object)
{
	for (int i = 0; i < object.size; i++)
		(*this).push_back(object[i]);
}
template <typename T>
List_3<T>::~List_3()
{
	if (head != nullptr)
	{
		Node* current = head;
		while (current != nullptr)
		{
			Node* next = current->pnext;
			delete current;
			current = next;
		}
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
}
template <typename T>
List_3<T>::Node::Node(T data)
{
	this->data = data;
}


template <typename T>
void List_3<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		Node* current = tail;
		current->pnext = new Node(data);
		tail = current->pnext;
		tail->pprev = current;
		tail->pnext = 0;
	}
	++size;
}
template<typename T>
typename List_3<T>::Iterator List_3<T>::erase(Iterator& it)
{
	Node* t = it.it;

	if (t == head)
	{
		t = head->pnext;
		delete head;
		head = t;
		it.it = head;
		if (head != nullptr)
			head->pprev = nullptr;
		else
			tail = nullptr;
	}
	else if (t == tail)
	{
		t = tail->pprev;
		delete tail;
		tail = t;
		it.it = head;
		if (tail != nullptr)
			tail->pnext = nullptr;
		else
			head = nullptr;
	}
	else
	{
		Iterator temp = it;

		t = t->pprev;
		++temp;

		delete it.it;

		t->pnext = temp.it;
		temp.it->pprev = t;

		it = temp;
	}
	--size;

	return it;
}

template<typename T>
void List_3<T>::fill_List_3()
{
	int n = 0;
	Pair p;
	cout << "Input size: "; cin >> n; cout << endl;
	for (size_t i = 0; i < n; i++)
	{
		p.set_first((int)(rand() % 500 - 50) / 10);
		p.set_second((double)(rand() % 500 - 50) / 10);
		(*this).push_back(p);
	}
}
template<typename T>
void List_3<T>::show_List_3()
{
	if ((*this).get_size() != 0)
	{
		cout << "List_3: ";
		for (auto& i : (*this))
			cout << i << " ";
		cout << endl;
	}
}
template<typename T>
void List_3<T>::average()
{
	if ((*this).get_size() != 0)
	{
		int av_first = 0;
		double av_second = 0;

		for (auto i = (*this).begin(); i != (*this).end(); ++i)
		{
			av_first += (*i).get_first();
			av_second += (*i).get_second();
		}

		av_first /= (*this).get_size();
		av_second /= (*this).get_size();
		Pair p(av_first, av_second);
		(*this).push_back(p);
	}
}
template<typename T>
void List_3<T>::remove()
{
	if ((*this).get_size() != 0)
	{
		Pair start, end;
		cout << "\n\t[ Start position ]\n"; cin >> start;
		cout << "\t[ End position ]\n"; cin >> end;
		for (auto& i = (*this).begin(); i != (*this).end();)
		{
			if ((start.get_first() <= (*i).get_first() && start.get_second() <= (*i).get_second()) && ((*i).get_first() <= end.get_first() && (*i).get_second() <= end.get_second()))
				i = (*this).erase(i);
			else
				++i;
		}
	}
}
template<typename T>
void List_3<T>::add_min_max()
{
	if ((*this).get_size() != 0)
	{
		Pair p_min, p_max;
		auto& i = (*this).begin();

		p_max.set_first((*i).get_first());
		p_max.set_second((*i).get_second());
		p_min.set_first((*i).get_first());
		p_min.set_second((*i).get_second());

		for (auto& i : (*this))
		{
			if (p_max < i)
			{
				p_max.set_first(i.get_first());
				p_max.set_second(i.get_second());
			}
			else if (i < p_min)
			{
				p_min.set_first(i.get_first());
				p_min.set_second(i.get_second());
			}
		}
		for (auto& i : (*this))
		{
			i = i + (p_max.get_first() + p_min.get_first());
			i = i + (p_max.get_second() + p_min.get_second());
		}
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

template <typename T>
List_3<T>::Iterator::Iterator()
{
	it = nullptr;
}
template <typename T>
List_3<T>::Iterator::Iterator(const Iterator& it)
{
	this->it = it.it;
}

template <typename T>
bool List_3<T>::Iterator::operator==(const Iterator& it)
{
	return this->it = it.it;
}
template <typename T>
bool List_3<T>::Iterator::operator!=(const Iterator& it)
{
	return this->it != it.it;
}
template <typename T>
void List_3<T>::Iterator::operator++()
{
	it = it->pnext;
}
template <typename T>
void List_3<T>::Iterator::operator--()
{
	it = it->pprev;
}
template<typename T>
typename List_3<T>::Iterator& List_3<T>::Iterator::operator=(const Iterator& it)
{
	this->it = it.it;
	return *this;
}
template <typename T>
T& List_3<T>::Iterator::operator*()
{
	return this->it->data;
}

template<typename T>
typename List_3<T>::Iterator& List_3<T>::begin()
{
	if (head != nullptr)
		pbeg.it = head;
	return pbeg;
}
template<typename T>
typename List_3<T>::Iterator& List_3<T>::end()
{
	if (tail != nullptr)
		pend.it = tail->pnext;
	return pend;
}

typedef List_3<Pair> lst3;

void fill_List_3(lst3& l)
{
	int n = 0;
	Pair p;
	cout << "Input size: "; cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		p.set_first((int)(rand() % 500 - 50) / 10);
		p.set_second((double)(rand() % 500 - 50) / 10);
		l.push_back(p);
	}
	cout << endl;
}
void show_List_3(lst3& l)
{
	if (l.get_size() != 0)
	{
		cout << "List_3: ";
		for (auto& i : l)
			cout << i << " ";
		cout << endl;
	}
}
void average(lst3& l)
{
	if (l.get_size() != 0)
	{
		int av_first = 0;
		double av_second = 0;

		for (auto i = l.begin(); i != l.end(); ++i)
		{
			av_first += (*i).get_first();
			av_second += (*i).get_second();
		}

		av_first /= l.get_size();
		av_second /= l.get_size();
		Pair p(av_first, av_second);
		l.push_back(p);
	}
}
void remove(lst3& l)
{
	if (l.get_size() != 0)
	{
		Pair start, end;
		cout << "\n\t[Start position]\n"; cin >> start;
		cout << "\t[End position]\n"; cin >> end;
		for (auto& i = l.begin(); i != l.end();)
		{
			if ((start.get_first() <= (*i).get_first() && start.get_second() <= (*i).get_second()) && ((*i).get_first() <= end.get_first() && (*i).get_second() <= end.get_second()))
				i = l.erase(i);
			else
				++i;
		}
	}
}
void add_min_max(lst3& l)
{
	if (l.get_size() != 0)
	{
		Pair p_min, p_max;
		auto& i = l.begin();

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

void foo_3()
{
	system("cls");

	cout << "\t\t\tEXERCISE 3\n\n";
	srand(time(0));
	List_3<Pair> lst3;

	lst3.fill_List_3();
	cout << "---------------------- [initial List_3] ----------------------\n";
	lst3.show_List_3();

	average(lst3);
	cout << "\n--------------------- [List_3 + average] ---------------------\n";
	lst3.show_List_3();

	lst3.remove();
	cout << "\n------------------- [List_3 after deletion] ------------------\n";
	lst3.show_List_3();

	lst3.add_min_max();
	cout << "\n------------------- [List_3 + (min + max)] -------------------\n";
	lst3.show_List_3();

	cout << endl;
	system("pause");
}