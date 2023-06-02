#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct List
{
	void push_front();
	int pop_front();
	void push_back();
	int pop_back();
	int add_after(int number);
	void pop_element();
	void add_several_elements();
	void delete_several_elements();
	void show_list();

	struct Node
	{
		Node(T data)
		{
			this->data = data;
		}
		Node* pnext = nullptr;
		T data;
	};

	Node* head = nullptr;
	int size = 0;
};

template <typename T>
void List<T>::push_front()
{
	T data;
	cout << "Enter the data: ";
	cin >> data;
	Node* temp = head;
	head = new Node(data);
	head->pnext = temp;
	++size;
}
template<typename T>
int List<T>::pop_front()
{
	if (head != nullptr)
	{
		Node* temp = head->pnext;
		delete head;
		head = temp;
		--size;
		return 1;
	}
	else { system("cls"); cout << "The list is empty!\n\n"; return 0; }
}
template<typename T>
void List<T>::push_back()
{
	T data;
	cout << "Enter the data: ";
	cin >> data;
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node* current = head;
		while (current->pnext != nullptr)
			current = current->pnext;
		current->pnext = new Node(data);
	}
	++size;
}
template<typename T>
int List<T>::pop_back()
{
	if (head != nullptr)
	{
		Node* current = head;
		for (int i = 0; i < size - 1; i++)
			current = current->pnext;
		delete current->pnext;
		current->pnext = nullptr;
		--size;
		return 1;
	}
	else { system("cls"); cout << "The list is empty!\n\n"; return 0; }
}

template<typename T>
void List<T>::show_list()
{
	if (head != nullptr)
	{
		cout << "List: ";
		Node* current = head;
		for (size_t i = 0; i < size; i++)
		{
			cout << current->data << " ";
			current = current->pnext;
		}
		cout << endl << endl;
	}
	else
		cout << "The list is empty!\n\n";

}

template<typename T>
int List<T>::add_after(int number)
{
	if (head != nullptr)
	{
		if (number >= 0 && number <= size)
		{
			if (number == size)
				push_back();
			else if (number == 0)
				push_front();
			else
			{
				T data;
				cout << "Enter data: ";
				cin >> data;
				Node* current = head;
				for (int i = 0; i < number - 1; i++)
					current = current->pnext;
				Node* temp = current->pnext;
				current->pnext = new Node(data);
				current = current->pnext;
				current->pnext = temp;
				++size;
			}
			return 1;
		}
		else { system("cls"); cout << "Input error!\n\n"; return 0; }
	}
	else { system("cls"); cout << "The list is empty!\n\n"; return 0; }
}
template<typename T>
void List<T>::add_several_elements()
{
	int n, choice;
	T data;
	cout << "Enter 1 - add items to the top of the list\nEnter 2 - add items after the selected item\nEnter 3 - add items to the end of the list\n\n";
	cout << "Your choice of answer: ";
	cin >> choice;

	system("cls");
	switch (choice)
	{
	case 1:
		cout << "Number of added elements: ";
		cin >> n;
		cout << endl;
		for (int i = 0; i < n; i++)
			push_front();
		system("cls"); cout << "Data has been successfully added!\n\n";
		break;
	case 2:
		if (head != nullptr)
		{
			show_list();
			cout << "Number of added elements: ";
			cin >> n;
			int number;
			cout << "After which element number to add new ones: ";
			cin >> number;
			cout << endl;
			for (int i = 0; i < n; i++)
				add_after(number++);
			system("cls"); cout << "Data has been successfully added!\n\n";
		}
		else { system("cls"); cout << "The list is empty!\n\n"; }
		break;
	case 3:
		cout << "Number of added elements: ";
		cin >> n;
		cout << endl;
		for (int i = 0; i < n; i++)
			push_back();
		system("cls"); cout << "Data has been successfully added!\n\n";
		break;
	default:
		cout << "Input error. Try again.\n\n";
		break;
	}
}

template<typename T>
void List<T>::pop_element()
{
	if (head != nullptr)
	{
		show_list();
		int number;
		cout << "The element under which number to delete: ";
		cin >> number;
		if (number >= 1 && number <= size)
		{
			if (number == size)
				pop_back();
			else if (number == 1)
				pop_front();
			else
			{
				Node* current = head;
				for (int i = 0; i < number - 2; i++)
					current = current->pnext;
				Node* temp = current->pnext;
				current->pnext = temp->pnext;
				delete temp;
				--size;
			}
			system("cls"); cout << "Data has been successfully deleted!\n\n";
		}
		else { system("cls"); cout << "Input error!\n\n"; }
	}
	else { system("cls"); cout << "The list is empty!\n\n"; }

}
template<typename T>
void List<T>::delete_several_elements()
{
	show_list();

	if (head != nullptr)
	{
		int start, count;
		cout << "Which element to start deleting from: ";
		cin >> start;

		if (start >= 1 && start <= size)
		{
			cout << "Number of deleted items: ";
			cin >> count;
			if (start + count <= size + 1)
			{
				if (start == 1)
					for (int i = 0; i < count; i++)
						pop_front();
				else
				{
					Node* current = head;
					for (int i = 0; i < start - 2; i++)
						current = current->pnext;
					for (int i = 0; i < count; i++)
					{
						Node* temp = current->pnext;
						current->pnext = temp->pnext;
						delete temp;
					}
					size -= count;
				}
				system("cls"); cout << "Data has been successfully deleted!\n\n";
			}
			else { system("cls"); cout << "Input error!\n\n"; }
		}
		else { system("cls"); cout << "Input error!\n\n"; }
	}
}

int main()
{
	system("chcp 1251 >> null");

	List<int> list1;
	int data;

	int f = 1;
	while (f)
	{
		int choice;
		cout << "Enter 1 - add an element to the beginning of the list\nEnter 2 - add an element to the end of the list\nEnter 3 - add an element after the specified\nEnter 4 - add several elements\nEnter 5 - remove an element from the beginning of the list\nEnter 6 - remove an element from the end of the list\nEnter 7 - remove an element after the given\nEnter 8 - delete several items\nEnter 9 - view the list\nEnter 10 - terminate the program\n\n";
		cout << "Your choice of answer: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			list1.push_front();
			system("cls");
			cout << "Data has been successfully added!\n\n";
			break;
		case 2:
			system("cls");
			list1.push_back();
			system("cls");
			cout << "Data has been successfully added!\n\n";
			break;
		case 3:
			if (list1.head != nullptr)
			{
				system("cls");
				list1.show_list();
				int number;
				cout << "After which element number to add a new one: ";
				cin >> number;
				if (list1.add_after(number) == 1)
				{
					system("cls");
					cout << "The data has been successfully deleted!\n\n";
				}
			}
			else { system("cls"); cout << "The list is empty!\n\n"; }
			break;
		case 4:
			system("cls");
			list1.add_several_elements();
			break;
		case 5:
			system("cls");
			if (list1.pop_front() == 1)
			{
				system("cls");
				cout << "The data has been successfully deleted!\n\n";
			}
			break;
		case 6:
			system("cls");
			if (list1.pop_back() == 1)
			{
				system("cls");
				cout << "The data has been successfully deleted!\n\n";
			}
			break;
		case 7:
			system("cls");
			list1.pop_element();
			break;
		case 8:
			system("cls");
			list1.delete_several_elements();
			break;
		case 9:
			system("cls");
			list1.show_list();
			break;
		case 10:
			system("cls"); cout << "Program shutdown.\n";
			f = 0;
			break;
		default:
			system("cls"); cout << "Input error. Try again.\n\n";
			break;
		}
	}
	return 0;
}