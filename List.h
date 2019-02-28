#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstdlib>
#include "Planet.h"
#include "Star.h"

class Node
{
	public:
	Planet * plan;
	Node * next;
	Node * prev;
};

class List
{
	private:
	unsigned numNodes;
	public:
	Node * head;
	Node * tail;
	List();
	~List();
	void insert(long, Planet*);
	Planet * read(int);
	bool remove(int);
	unsigned size();
	
};
#endif
