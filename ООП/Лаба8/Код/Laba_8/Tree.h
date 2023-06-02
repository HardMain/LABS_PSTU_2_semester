#pragma once
#include "Object.h"

class Tree
{
protected:
	Object** beg;
	int capacity;
	int size;
public:
	Tree();
	Tree(int a);
	~Tree();

	void create();
	void add();
	void del();
	void show();
	void get_name();

	int operator()();
};