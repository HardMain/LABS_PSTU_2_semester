	#pragma once

	#include <iostream>
	#include <string>
	using namespace std;

	class List
	{
	private:
		class Node
		{
			friend class List;
		private:
			int data;
			Node* pnext = nullptr;
			Node* pprev = nullptr;
		public:
			Node(int data);
		};
		int size = 0;
		Node* head = nullptr;
		Node* tail = nullptr;

	public:
		List();
		List(List& object);
		~List();

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

		void push_front(int data);
		void pop_front();
		void push_back(int data);
		void pop_back();
		void show_list();
		void add_after(int number, int data);
		void pop_element(int number);

		int& operator[](int index) const;
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