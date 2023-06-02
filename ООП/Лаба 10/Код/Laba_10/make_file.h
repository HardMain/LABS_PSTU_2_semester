#pragma once
#include "Pair.h"

void pause()
{
	cout << "\npress any key to continue . . .";
	do
	{
		if (_kbhit())
		{
			_getch();
			break;
		}
	} while (true);
	system("cls");
}

int make_file(const string& path)
{
	fstream file(path, ios::out);
	if (!file.is_open())
		throw 1;

	int n; Pair p;
	cout << "Number of elements: "; cin >> n;
	if (n < 1)
		throw 2;

	cout << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << '(' << i + 1 << ")\n";
		cin >> p;
		file << p;
	}

	cout << "\nData added successfully!\n";

	file.close();
	return n;
}
void print_file(const string& path, const int& count)
{
	fstream file(path, ios::in);
	if (!file.is_open())
		throw 1;

	if (count == 0)
		throw 4;

	int n = 0; Pair p;

	cout << "File data:\n";
	while (file >> p)
	{
		cout << p.first << ' ' << p.second << '\n';
		++n;
	}
	if (n == 0)
		cout << "File is empty!\n--[Try again]--\n";

	file.close();
}
int del_from_file(const string& path, const int& count)
{
	fstream temp("temp.txt", ios::out);
	fstream file(path, ios::in);
	if (!file.is_open() || !temp.is_open())
		throw 1;

	if (count == 0)
		throw 4;

	Pair number, p;
	cout << "Enter a pair to remove elements less than this:\n"; cin >> number;	//введите пару для удаления элементов, меньше чем эта

	int i = 0;
	while (file >> p)
	{
		if (p.first >= number.first or p.second >= number.second)
			temp << p;
		else
			++i;
	}

	temp.close(); file.close();

	remove(path.c_str());
	rename("temp.txt", path.c_str());

	if (i == 0)
		cout << "\nNo items found to delete!\n";
	else
		cout << "\nData deleted successfully!\n";

	return count - i;
}
int add_elements(const string& path, const int& count)
{
	fstream file(path, ios::out | ios::in | ios::app);
	fstream temp("temp.txt", ios::out);
	if (!file.is_open() or !temp.is_open())
		throw 1;

	int number, new_count = 0;
	cout << "After which element to add new (with " << 0 << " - to " << count << "): "; cin >> number;	//после какого элемента добавить новые

	if (number < 0 or number > count)
		throw 3;

	cout << "Number of elements: "; cin >> new_count;	//количество вводимых элементов
	if (new_count < 1)
		throw 2;

	Pair p;

	if (number == count)
	{
		cout << endl;
		for (size_t i = 0; i < new_count; i++)
		{
			cout << '(' << i + 1 << ")\n";
			cin >> p;
			file << p;
		}

		file.close();
	}
	else
	{
		for (size_t i = 0; i < number; i++)
		{
			file >> p;
			temp << p;
		}
		for (size_t i = 0; i < new_count; i++)
		{
			cout << '(' << i + 1 << ")\n";
			cin >> p;
			temp << p;
		}
		for (size_t i = number; i < count; i++)
		{
			file >> p;
			temp << p;
		}

		file.close(); temp.close();

		remove(path.c_str());
		rename("temp.txt", path.c_str());
	}

	return count + new_count;
}
void add_number(const string& path, const int& count)
{
	fstream temp("temp.txt", ios::out);
	fstream file(path, ios::in);
	if (!file.is_open() || !temp.is_open())
		throw 1;
	if (count == 0)
		throw 4;

	double number; Pair compare;
	cout << "Enter the number to add to the pair: "; cin >> number;
	cout << "Pair to add:\n"; cin >> compare;

	Pair p; int i = 0;
	while (file >> p)
	{
		if (p.first == compare.first && p.second == compare.second && number == int(number))
		{
			p = p + int(number);
			++i;
		}
		else if (p.first == compare.first && p.second == compare.second && number != int(number))
		{
			p = p + number;
			++i;
		}
		temp << p;
	}

	file.close(); temp.close();


	remove(path.c_str());
	rename("temp.txt", path.c_str());

	if (i == 0)
		cout << "\nNo items found to change!\n";
	else
		cout << "\nData changed successfully!\n";

	return;
}