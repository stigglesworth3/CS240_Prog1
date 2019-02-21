#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstdlib>
#include "Planet.h"
#include "Star.h"

class List
{
	public:
	Node * head;
	Node * tail;
	unsigned numNodes;
	~List();
	void insert(int, Planet*);
	Planet * read(int);
	bool remove(int);
	unsigned size();
	
};

class Node
{
	Planet * plan;
	Node * next;
	Node * prev;
};
#endif
