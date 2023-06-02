#pragma once
#include "Print.h"

class Magazine : public Print
{
protected:
	int pages;
public:
	Magazine();
	Magazine(const Magazine& object);
	~Magazine();

	void setPages(int pages) { this->pages = pages; }
	int getPages() { return pages; };

	Magazine& operator=(const Magazine& object);

	void show() override;
	void input() override;
};