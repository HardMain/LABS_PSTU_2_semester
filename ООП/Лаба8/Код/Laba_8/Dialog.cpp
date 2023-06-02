#include "Dialog.h"

void pause()
{
	cout << "\npress any key to continue . . . ";
	while (true)
		if (_kbhit())
		{
			_getch();
			break;
		}
	system("cls");
}

Dialog::Dialog()
{
	endState = 0;
}
//Dialog::~Dialog()
//{
//	if (beg != nullptr)
//	{
//		for (size_t i = 0; i < size; i++)
//			delete beg[i];
//		delete beg;
//	}
//}

void Dialog::execute()
{
	Event event;
	do
	{	
		system("cls");

		cout << "m: Create a group\n";
		cout << "+: Add element \n";
		cout << "-: Delete group\n";
		cout << "s: Group data\n";
		cout << "z: Name\n";
		cout << "q: End of work\n";

		endState = 0;
		getEvent(event);
		handleEvent(event);
		pause();

	} while (valid());
}
void Dialog::getEvent(Event& event)
{
	string operation = "m+-szq";
	char choice;
	cout << "--> "; cin >> choice;
	if (operation.find(choice) != -1)
	{
		event.what = evMessage;
		switch (choice)
		{
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case 'z': event.command = cmGet; break;
		case 'q': event.command = cmQuit; break;
		}
	}
	else
		cout << "\n[Input operation is invalid]\n";
}
void Dialog::handleEvent(Event& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake: 
			create(); 
			clearEvent(event);
			break;
		case cmAdd:
			add();
			clearEvent(event);
			break;
		case cmDel:
			del();
			clearEvent(event);
			break;
		case cmShow:
			show();
			clearEvent(event);
			break;
		case cmQuit:
			endExec();
			clearEvent(event);
			break;
		case cmGet:
			get_name();
			clearEvent(event);
			break;
		}
	}
}
void Dialog::clearEvent(Event& event)
{
	event.what = evNothing;
}
bool Dialog::valid()
{
	return !endState;
}
void Dialog::endExec()
{
	endState = 1;
}
