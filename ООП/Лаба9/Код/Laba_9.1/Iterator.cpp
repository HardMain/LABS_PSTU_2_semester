#include "List.h"

List::Iterator::Iterator()
{
	it = nullptr;
}
List::Iterator::Iterator(const Iterator& it)
{
	this->it = it.it;
}

bool List::Iterator::operator==(const Iterator& it)
{
	return this->it == it.it;
}
bool List::Iterator::operator!=(const Iterator& it)
{
	return this->it != it.it;
}
void List::Iterator::operator++()
{
	this->it = it->pnext;
}
void List::Iterator::operator--()
{
	it = it->pprev;
}
int List::Iterator::operator*()
{
	return this->it->data;
}