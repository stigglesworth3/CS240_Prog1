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
		this->head = p;
		this->tail = p;
		this->numNodes++;
	}
	else
	{
		if (this->head->plan->getID() > index)
		{
			p->next = this->head;
			p->prev = NULL;
			this->head = p;
			this->numNodes++;
		}
		else if (this->tail->plan->getID() < index)
		{
			p->next = NULL;
			p->prev = tail;
			this->tail = p;
			this->numNodes++;
		}
		else 
		{
			Node * temp = this->head;
			while (temp != tail)
			{
				if (index > this->temp->plan->getID() && index < this->temp->next->plan->getID())
				{
					p->next = temp->next;
					p->prev = temp;
					temp->next->prev = p;
					temp->next = p;
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
	PLanet * ret = this->head;
	for (int i=0; i<index; i++)
	{
		ret = ret->next;
	}
	return ret;
}

bool List::remove(int index)
{
	if (index < 0 || index >=size())
	{
		return false;
	}
	Planet * gone = this->read(index);
	if (gone == NULL)
	{
		return false;
	}
	gone->prev->next = gone->next;
	gone->next->prev = gone->prev;
	delete gone;
	gone = NULL;
	this->numNodes--;
	return true;
}

unsigned List::size()
{
	return this->numNodes;
}
