#pragma once

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List
{
private:
	class Node
	{
		friend class List;
	private:
		T data;
		Node* pnext = nullptr;
		Node* pprev = nullptr;
	public:
		Node(T data);
	};
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	class Iterator
	{
		friend class List;
	private:
		Node* it = nullptr;
	public:
		Iterator();
		Iterator(const Iterator& it);

		bool operator==(const Iterator& it);
		bool operator!=(const Iterator& it);
		void operator++();
		void operator--();
		int operator*();
	};
	List();
	List(List& object);
	~List();

	void push_front(T data);
	void pop_front();
	void push_back(T data);
	void pop_back();
	void show_list();
	void add_after(int number, T data);
	void pop_element(int number);

	T& operator[](int index) const;
	int& operator()();
	List& operator=(const List& object);
	List operator*(List& object);

	Iterator first()
	{
		if (head != nullptr)
			beg.it = head;
		return beg;
	}
	Iterator last()
	{
		if (tail != nullptr)
			end.it = tail->pnext;
		return end;
	}
private:
	Iterator beg;
	Iterator end;
};

template <typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template <typename T>
List<T>::List(List& object)
{
	for (int i = 0; i < object.size; i++)
		(*this).push_back(object[i]);
}
template <typename T>
List<T>::~List()
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
List<T>::Node::Node(T data)
{
	this->data = data;
}

template <typename T>
void List<T>::push_front(T data)
{
	if (head == nullptr)
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		Node* temp = head;
		head = new Node(data);
		temp->pprev = head;
		head->pnext = temp;
	}
	++size;
}
template <typename T>
void List<T>::pop_front()
{
	if (head != nullptr)
	{
		Node* temp = head->pnext;
		delete head;
		head = temp;
		if (head != nullptr)
			head->pprev = 0;
		else
			tail = nullptr;
		--size;
	}
	else
	{
		system("cls"); cout << "List is empty!\n\n";
	}
}
template <typename T>
void List<T>::push_back(T data)
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
template <typename T>
void List<T>::pop_back()
{
	if (head != nullptr)
	{
		Node* current = tail->pprev;
		delete tail;
		tail = current;
		if (tail != nullptr)
			current->pnext = nullptr;
		else
			head = nullptr;
		--size;
	}
	else { system("cls"); cout << "List is empty!\n\n"; }
}
template <typename T>

void List<T>::show_list()
{
	if (head != nullptr)
	{
		int choice = 1;
		switch (choice)
		{
		case 1:
		{
			Node* current = head;
			for (size_t i = 0; i < size; i++)
			{
				cout << current->data << " ";
				current = current->pnext;
			}
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "List: ";
			Node* current = tail;
			for (size_t i = size; i > 0; i--)
			{
				cout << current->data << " ";
				current = current->pprev;
			}
			cout << endl;
			break;
		}
		default:
			system("cls"); cout << "Input error!\n";
			break;
		}
	}
	else { system("cls"); cout << "List is empty!\n"; }
}
template <typename T>
void List<T>::add_after(int number, T data)
{
	if (head != nullptr)
	{
		if (number >= 0 && number <= size)
		{
			if (number == size)
				pushback(data);
			else if (number == 0)
				push_front(data);
			else
			{
				if (number <= size / 2)
				{
					Node* current = head;
					for (int i = 0; i < number - 1; i++)
						current = current->pnext;
					Node* temp = current->pnext;
					current->pnext = new Node(data);
					current->pprev = current;
					current = current->pnext;
					current->pnext = temp;
					++size;
				}
				else
				{
					Node* current = tail;
					for (int i = size; i > number; i--)
						current = current->pprev;
					Node* temp = current->pnext;
					Node* temp2 = current;
					current->pnext = new Node(data);
					temp->pprev = current->pnext;
					current = current->pnext;
					current->pprev = temp2;
					current->pnext = temp;
					++size;
				}
			}
		}
		else { system("cls"); cout << "Input error!\n\n"; }
	}
	else { system("cls"); cout << "List is empty!\n\n"; }
}
template <typename T>
void List<T>::pop_element(int number)
{
	if (head != nullptr)
	{
		if (number >= 1 && number <= size)
		{
			if (number == size)
				pop_back();
			else if (number == 1)
				pop_front();
			else
			{
				if (number <= size / 2)
				{
					Node* current = head;
					for (int i = 0; i < number - 1; i++)
						current = current->pnext;
					Node* temp = current->pprev;
					Node* temp2 = current->pnext;
					delete current;
					temp->pnext = temp2;
					temp2->pprev = temp;
				}
				else
				{
					Node* current = tail;
					for (int i = size; i > number; i--)
						current = current->pprev;
					Node* temp = current->pprev;
					Node* temp2 = current->pnext;
					delete current;
					temp->pnext = temp2;
					temp2->pprev = temp;
				}
				--size;
			}
		}
		else { system("cls"); cout << "Input error!\n\n"; }
	}
	else { system("cls"); cout << "List is empty!\n\n"; }
}

template <typename T>
T& List<T>::operator[](const int index) const
{
	if (index >= 0 && index < size)
	{
		if (index <= size / 2)
		{
			Node* current = head;
			for (int i = 0; i < index; ++i)
				current = current->pnext;
			return current->data;
		}
		else
		{
			Node* current = tail;
			for (int i = size - 1; i > index; --i)
				current = current->pprev;
			return current->data;
		}
	}
	else
		throw out_of_range("Out of range");
}
template <typename T>
int& List<T>::operator()()
{
	return size;
}
template <typename T>
List<T>& List<T>::operator=(const List& object)
{
	if (this != &object)
		if (this->head != nullptr)
		{
			this->~List();
			for (int i = 0; i < object.size; i++)
				this->push_back(object[i]);
		}
		else
			for (int i = 0; i < object.size; i++)
				this->push_back(object[i]);
	return *this;
}
template <typename T>
List<T> List<T>::operator*(List& object)
{
	if (object.size > size)
	{
		List temp;
		Node* current = (*this).head;
		for (int i = 0; i < object.size; i++)
		{
			if (current != nullptr)
				temp.push_back((*this)[i] * object[i]);
			else
				temp.push_back(T());
			if (current != 0)
				current = current->pnext;
		}
		return temp;
	}
	else
	{
		List temp;
		Node* current = object.head;
		for (int i = 0; i < size; i++)
		{
			if (current != nullptr)
				temp.push_back((*this)[i] * object[i]);
			else
				temp.push_back(T());
			if (current != 0)
				current = current->pnext;
		}
		return temp;
	}
}

template <typename T>
List<T>::Iterator::Iterator()
{
	it = nullptr;
}
template <typename T>
List<T>::Iterator::Iterator(const Iterator& it)
{
	this->it = it.it;
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& it)
{
	return this->it = it.it;
}
template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& it)
{
	return this->it != it.it;
}
template <typename T>
void List<T>::Iterator::operator++()
{
	it = it->pnext;
}
template <typename T>
void List<T>::Iterator::operator--()
{
	it = it->pprev;
}
template <typename T>
int List<T>::Iterator::operator*()
{
	return this->it->data;
}