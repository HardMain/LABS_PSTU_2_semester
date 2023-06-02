#include "Pair.h"
#include "make_file.h"

int main()
{
	system("color F0");
	system("chcp 1251 >> null");

	int choice, count = 0; 

	string path;
	cout << "Input file name: "; cin >> path;
	if (path.find(".txt") == -1)
		path += ".txt";
	remove(path.c_str());
	system("cls");

	do
	{
		cout << "0. Exit\n";
		cout << "1. Make file / deleting an existing file + Make file\n";
		cout << "2. Print file\n";
		cout << "3. Deleting objects from file\n";
		cout << "4. Add elements / Make file + Add elements\n";
		cout << "5. Add number to pairs\n";
		cout << "--> "; cin >> choice;
		system("cls");

		try
		{
			switch (choice)
			{
			case 0:
				cout << "Program completion.\n";
				break;
			case 1:
				count = make_file(path);
				cout << endl;
				print_file(path, count);
				break;
			case 2:
				print_file(path, count);
				break;
			case 3:
				print_file(path, count);
				cout << endl;
				count = del_from_file(path, count);
				cout << endl;
				print_file(path, count);
				break;
			case 4:
				print_file(path, count);
				cout << endl;
				count = add_elements(path, count);
				cout << endl;
				print_file(path, count);
				break;
			case 5:
				print_file(path, count);
				cout << endl;
				add_number(path, count);
				cout << endl;
				print_file(path, count);
				break;
			default:
				cout << "Unknown command!\n--[Try again]--\n\n";
				break;
			}

			pause();
		}
		catch (int error)
		{
			system("cls");

			switch (error)
			{
			case 1:
				cout << "File open error!\n";
				break;
			case 2:
				cout << "Input error!\n";
				break;
			case 3:
				cout << "Out of range!\n";
				break;
			case 4:
				cout << "File is empty!\n";
				break;
			default:
				cout << "Unknown error!\n";
				break;
			}

			pause();
		}
	} while (choice != 0);
	
	return 0;
}