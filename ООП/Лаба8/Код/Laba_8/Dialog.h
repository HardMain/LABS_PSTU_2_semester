#pragma once
#include "Tree.h"
#include "Event.h"

class Dialog : public Tree
{
protected:
	int endState;
public:
	Dialog();
	~Dialog() {};

	void execute();
	void getEvent(Event& event);
	void handleEvent(Event& event);
	void clearEvent(Event& event);
	bool valid();
	void endExec();
};

