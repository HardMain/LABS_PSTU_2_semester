#pragma once

template<typename T>
class Stack
{
private:
	struct Node
	{
		Node(T data)
		{
			this->data = data;
		}
		Node* pnext = nullptr;
		T data;
	};

	Node* head;
	int size;
public:
	Stack() = default;
	~Stack();

	void push(T data);
	void pop();
	int getSize();
	bool empty();
	void top();

};

template<typename T>
inline Stack<T>::~Stack()
{
	if (head != 0)
	{
		while (!this->empty())
			this->pop();
		head = nullptr;
	}
}

template<typename T>
bool Stack<T>::empty()
{
	return head == nullptr;
}
template<typename T>
void Stack<T>::push(T data)
{
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node* temp = head;
		head = new Node(data);
		head->pnext = temp;
	}
	++size;
}
template<typename T>
void Stack<T>::pop()
{
	if (head != nullptr)
	{
		Node* temp = head;
		head = temp->pnext;
		delete temp;
		--size;
	}
	else
		cout << "Stack is empty!" << endl;
}
template<typename T>
int Stack<T>::getSize()
{
	return size;
}
template<typename T>
void Stack<T>::top()
{
	if (head != nullptr)
		cout << head->data << endl;
	else
		cout << "Stack is empty!" << endl;
}