#include "Tree.h"
#include "Print.h"
#include "Magazin.h"

Tree::Tree()
{
	beg = nullptr;
	capacity = 0;
	size = 0;
}
Tree::Tree(int a)
{
	beg = new Object *[a];
	size = 0;
	capacity = a;
}
Tree::~Tree()
{
	if (beg != nullptr)
		delete[] beg;
	beg = nullptr;
}

void Tree::create()
{
	if (beg != nullptr)
		del();
	cout << "\nEnter size: "; cin >> capacity;
	beg = new Object * [capacity];
	size = 0;
}
void Tree::add()
{
	if (size < capacity && capacity != 0)
	{
		unsigned int answer;
		cout << "\n----- enter -----\n1 - Print\n2 - Magazine\n--> "; cin >> answer;
		cout << endl;

		if (answer == 1)
		{
			Print* a = new Print;
			a->input();
			beg[size] = a;
			++size;
			cout << "\ndata added successfully!\n";
		}
		else if (answer == 2)
		{
			Magazine* b = new Magazine;
			b->input();
			beg[size] = b;
			++size;
			cout << "\ndata added successfully!\n";
		}
		else
			cout << "\n[Try again]\n";
	}
	else
		cout << "\n[Out of range or the group was not created]\n";
}
void Tree::del()
{
	if (beg != nullptr)
	{
		for (size_t i = 0; i < size; i++)
			delete beg[i];
		delete beg;

		beg = nullptr;
		size = 0;
		capacity = 0;

		cout << "\nThe group was successfully deleted!\n";
	}
	else
		cout << "\n[group is empty]\n";
	size = 0;
}
void Tree::show()
{
	if (size == 0)
		cout << "\n[group is empty]\n";
	else
		for (size_t i = 0; i < size; i++)
		{
			cout << "(" << i + 1 << ")\n";
			beg[i]->show();
		}
}
void Tree::get_name()
{
	if (size == 0)
		cout << "\n[group is empty]\n";
	else
		for (size_t i = 0; i < size; i++)
			cout << "(" << i + 1 << ")\n" << beg[i]->getName() << endl;
}

int Tree::operator()()
{
	return size;
}