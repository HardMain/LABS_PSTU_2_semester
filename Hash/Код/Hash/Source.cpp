#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <list>
using namespace std;

string full_name[5] = { "Smirnov Andrei Andreevich", "Maslov Ivan Ivanovich", "Safonov Petr Petrovich", "Kuznetsov Dmitry Dmitrievich", "Gorbachev Evgeniy Evgenievich" };
string dates[5] = { "15.11.1969", "27.01.1996", "23.10.1972", "13.04.1993", "20.07.1985" };
string number_pasport[5] = { "704120", "704121", "704122", "704123", "704124" };

int collisions_count = 0;

struct Data
{
	string full_name = "NULL";
	string date_of_birth = "NULL";
	string number_pasport = "NULL";
};

class HashTable
{
	int capacity;
	list<Data>* table;
	vector<Data>* array;
public:

	//		      generally
	HashTable(int V);
	int hashFunction(string full_name);
	~HashTable();
	//				 end


	//			 chain methods
	void insertItem(string full_name, const list<Data>::iterator& it);
	void deleteItem(string full_name);
	void displayHash();
	//				 end


	//		   open address methods
	void add(string full_name, const vector<Data>::iterator& it);
	void displayHash2();
	void find_index(string date_of_birth);
	void pop(string date_to_delete);
	//				 end

};


//										  generally methods
//------------------------------------------------------------------------------------------------------

HashTable::HashTable(int c)
{
	this->capacity = c;
	table = new list<Data>[capacity];
	array = new vector<Data>(c);
}
int HashTable::hashFunction(string full_name)
{
	int sum = 0;
	for (size_t i = 0; i < full_name.length(); i++)
		sum += (unsigned char)full_name[i];
	return (sum % capacity);
}
HashTable::~HashTable()
{
	table->clear();
}

//------------------------------------------------------------------------------------------------------
//										end generally methods



//										  method chains
//------------------------------------------------------------------------------------------------------

void HashTable::insertItem(string date_of_birth, const list<Data>::iterator& it)
{
	int index = hashFunction(date_of_birth);
	if (table[index].size() != 0)
		++collisions_count;
	table[index].push_back(*it);
}
void HashTable::deleteItem(string date_of_birth)
{
	int index = hashFunction(date_of_birth);
	bool f = 0;

	for (auto& i : table[index])
	{
		if (i.date_of_birth == date_of_birth)
		{
			i.full_name = "NULL";
			i.date_of_birth = "NULL";
			i.number_pasport = "NULL";
			cout << "person with the date_of_birth \"" << date_of_birth << "\" was successfully deleted\n\n";
			f = 1;
			break;
		}
	}
	if (f == 0)
		cout << "person with a date_of_birth \"" << date_of_birth << "\" could not be found\n\n";
}
void HashTable::displayHash()
{
	cout << "-----------| show hashTable |-----------\n";
	for (int i = 0; i < capacity; i++)
	{
		cout << "table[" << i << "]";
		for (auto x : table[i])
			cout << " --> " + x.full_name + "; " + x.date_of_birth + "; " + x.number_pasport;
		cout << endl;
	}
	cout << "-----------| end hashTable |-----------\n";
}

//------------------------------------------------------------------------------------------------------
//										  end method chains



//                                      method open address
//------------------------------------------------------------------------------------------------------


void HashTable::add(string date_of_birth, const vector<Data>::iterator& it)
{
	int hash = hashFunction(date_of_birth);

	int index = hash;

	if ((*array)[index].date_of_birth == "NULL")
	{
		(*array)[index] = *it;
		return;
	}
	else
	{
		++index;
		while (index < capacity)
		{
			if ((*array)[index].date_of_birth == "NULL")
			{
				(*array)[index] = *it;
				return;
			}
			++index;
			++collisions_count;
		}
		if (index == capacity)
		{
			index = 0;
			++collisions_count;
			while (index < hash)
			{
				if ((*array)[index].date_of_birth == "NULL")
				{
					(*array)[index] = *it;
					return;
				}
				++index;
				++collisions_count;
			}
		}
	}
}
void HashTable::find_index(string date_of_birth)
{
	int hash = hashFunction(date_of_birth);
	int index = hash;

	while (index < capacity && (*array)[index].date_of_birth != date_of_birth)
		++index;
	if (index == capacity)
	{
		index = 0;
		while (index < hash && (*array)[index].date_of_birth != date_of_birth)
			++index;
		if (index == hash)
			cout << "person with a date_of_birth \"" << date_of_birth << "\" could not be found\n\n";
		else
			cout << "person with the date_of_birth \"" << date_of_birth << "\" was successfully found by the index " << index << endl << endl;
	}
	else
		cout << "person with the date_of_birth \"" << date_of_birth << "\" was successfully found by the index " << index << endl << endl;
}
void HashTable::pop(string date_of_birth)
{
	int hash = hashFunction(date_of_birth);
	int index = hash;
	if ((*array)[index].date_of_birth == date_of_birth)
	{
		(*array)[index].full_name = "NULL";
		(*array)[index].date_of_birth = "NULL";
		(*array)[index].number_pasport = "NULL";
		cout << "person with the date_of_birth \"" << date_of_birth << "\" was successfully deleted by the index " << index << endl << endl;
		return;
	}
	else
	{
		++index;
		while (index < capacity)
		{
			if ((*array)[index].date_of_birth == date_of_birth)
			{
				(*array)[index].full_name = "NULL";
				(*array)[index].date_of_birth = "NULL";
				(*array)[index].number_pasport = "NULL";
				cout << "person with the date_of_birth \"" << date_of_birth << "\" was successfully deleted by the index " << index << endl << endl;
				return;
			}
			++index;
		}
		if (index == capacity)
		{
			index = 0;
			while (index < hash)
			{
				if ((*array)[index].date_of_birth == date_of_birth)
				{
					(*array)[index].full_name = "NULL";
					(*array)[index].date_of_birth = "NULL";
					(*array)[index].number_pasport = "NULL";
					cout << "person with the full name \"" << full_name << "\" was successfully deleted by the index " << index << endl << endl;
					return;
				}
				++index;
			}
		}
	}
	cout << "person with a full name \"" << full_name << "\" could not be found\n\n";
}
void HashTable::displayHash2()
{
	cout << "-----------| show hashTable |-----------\n";

	int number = 0;
	for (auto it = array->begin(); it != array->end(); ++it)
	{
		cout << "(" << number++ << "):\n";
		cout << (*it).full_name << endl;
		cout << (*it).date_of_birth << endl;
		cout << (*it).number_pasport << endl;
	}


}

//------------------------------------------------------------------------------------------------------
//								       end method open address


void fillList(list<Data>& obj, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		Data data;
		data.number_pasport = number_pasport[rand() % 5];
		data.full_name = full_name[rand() % 5];
		data.date_of_birth = dates[rand() % 5];
		obj.push_back(data);
	}
}
void fillVector(vector<Data>& obj, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		Data data;
		data.number_pasport = number_pasport[rand() % 5];
		data.full_name = full_name[rand() % 5];
		data.date_of_birth = dates[rand() % 5];
		obj.push_back(data);
	}
}

int main()
{
	srand(time(0));
	system("chcp 1251 >> null");

	int size = 0;
	cout << "size(for table): "; cin >> size;

	int choice = -1;
	cout << "\n\t1 - method chain\n\t2 - method open address\n\nyour answer: "; cin >> choice;

	switch (choice)
	{
	case 1:
	{
		list<Data> lst1;

		system("cls"); cout << "----------| show List |----------\n";
		fillList(lst1, size);

		int number = 0;
		for (auto it = lst1.begin(); it != lst1.end(); ++it)
		{
			cout << "(" << number++ << ")" << endl;
			cout << (*it).full_name << endl;
			cout << (*it).date_of_birth << endl;
			cout << (*it).number_pasport << endl;
		}

		cout << "-----------| end List |-----------\n\n";

		HashTable h(size);

		for (auto it = lst1.begin(); it != lst1.end(); ++it)
			h.insertItem((*it).full_name, it);

		h.displayHash(); cout << endl;
		h.deleteItem("15.11.1969");
		h.displayHash();
	}
	break;
	case 2:
	{
		vector<Data> array;

		system("cls"); cout << "----------| show Vector |----------\n";
		fillVector(array, size);

		int number = 0;
		for (auto it = array.begin(); it != array.end(); ++it)
		{
			cout << "(" << number++ << ")" << endl;
			cout << (*it).full_name << endl;
			cout << (*it).date_of_birth << endl;
			cout << (*it).number_pasport << endl;
		}

		cout << "-----------| end Vector |-----------\n\n";

		HashTable h2(size);

		for (auto it = array.begin(); it != array.end(); ++it)
			h2.add((*it).full_name, it);

		h2.displayHash2(); cout << endl;
		h2.find_index("15.11.1969");
		h2.pop("15.11.1969");
		h2.displayHash2();
	}
	break;
	default:
		break;
	}

	cout << endl << "collisions: " << collisions_count << endl;
}