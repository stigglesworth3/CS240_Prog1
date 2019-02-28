#include <iostream>
#include <cstdlib>
#include "Planet.h"
#include "Star.h"

List::List()
{
	this->head = NULL;
	this->tail = NULL;
}

List::~List()
{
	for (int j=0; j<this->size(); j++)
	{
		this->head = this->head->next;
		delete this->head->prev;
	}
}

void List::insert(long index, Planet * p)
{
	if (this->head == NULL)
	{
		Node * first;
		first->plan = p;
		this->head = first;
		this->tail = first;
		this->numNodes++;
	}
	else
	{
		Node * put;
		put->plan = p;
		if (this->head->plan->getID() > index)
		{
			put->next = this->head;
			put->prev = NULL;
			this->head = put;
			this->numNodes++;
		}
		else if (this->tail->plan->getID() < index)
		{
			put->next = NULL;
			put->prev = tail;
			this->tail = put;
			this->numNodes++;
		}
		else 
		{
			Node * temp = this->head;
			while (temp != tail)
			{
				if (index > temp->plan->getID() && index < temp->next->plan->getID())
				{
					put->next = temp->next;
					put->prev = temp;
					temp->next->prev = put;
					temp->next = put;
					this->numNodes++;
					break;
				}
			}
		}	
	}
}

Planet * List::read(int index)
{
	if (index < 0 || index >= this->size())
	{
		return NULL;
	}
	Node * ret = this->head;
	for (int i=0; i<index; i++)
	{
		ret = ret->next;
	}
	return ret->plan;
}

bool List::remove(int index)
{
	if (index < 0 || index >=size())
	{
		return false;
	}
	Node * gone;
	gone->plan = this->read(index);
	if (gone->plan == NULL)
	{
		return false;
	}
	gone->prev->next = gone->next;
	gone->next->prev = gone->prev;
	delete gone->plan;
	gone->plan = NULL;
	this->numNodes--;
	return true;
}

unsigned List::size()
{
	return this->numNodes;
}
