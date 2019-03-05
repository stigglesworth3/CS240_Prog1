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
    // increment numNoddes
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
