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

void List::insert(int index, Planet * p)
{
	if (this->head == NULL)
	{
		this->head = p;
		this->tail = p;
		this->numNodes++;
	}
	else
	{
		if (index >= this->size())
		{
			this->tail->next = p;
			p->prev = this->tail;
			this->tail = p;
			this->numNodes++;
		}
		else
		{
			if (index == 0)
			{
				this->head->prev = p;
				p->next = this->head;
				this->head = p;
				this->numNodes++;
			}
			else
			{
				Planet * in = this->head->next;
				for (int i=1; i<this->size(); i++)
				{
					if (i == index)
					{
						in->prev->next = p;
						p->next = in;
						in->prev = p;
						this->numNodes++;
						break;
					}
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
