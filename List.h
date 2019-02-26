#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstdlib>
#include "Planet.h"
#include "Star.h"

class Node
{
	private:
	Planet * plan;
	Node * next;
	Node * prev;
};

class List
{
	private:
	Node * head;
	Node * tail;
	unsigned numNodes;
	public:
	~List();
	void insert(long, Planet*);
	Planet * read(int);
	bool remove(int);
	unsigned size();
	
};
#endif
