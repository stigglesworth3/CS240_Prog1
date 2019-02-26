#include "Star.h"
#include "List.h"
#include "Vector.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

StarList::StarList()
{
	this->plans->head = NULL;
	this->plans->tail = NULL;
	this->numPlanets = 0;
}

StarList::~StarList()
{
	while (this->head != this->tail)
	{
		this->head = this->head->next;
		delete this->head->prev;
	}
	delete head;
	head = tail = NULL;
}

long StarList::addPlanet()
{
	Node toAdd;
	Planet * p = new Planet(rand() % 10000);
	toAdd->plan = p;
	this->numPlanets++;
	this->plans->insert(toAdd->plan->getID(),p);
	return toAdd->plan->getID();
}

bool StarList::removePlanet(int index)
{
	this->numPlanets--;
	return this->plans->remove(index);
}

Planet * StarList::getPlanet(int index)
{
	return this->plans->read(index);
}

void StarList::orbit()
{
	Node * temp = this->head;
	while (temp != NULL)
	{
		temp->plan->orbit();
		temp = temp->next;
	}
	
}

void StarList::printStarInfo()
{
	Node * temp = this->head;
	cerr << "The star currently has " << getCurrentNumPlanets() << " planets." << endl;
	cerr << "Planets: " << endl;
	while (temp != NULL)
	{
		cerr << "Planet " << temp->plan->getID() << " is " << temp->plan->getDistance() << " million miles away at position " << temp->plan->getPos() << "." << endl;
		temp = temp->next;
	}
}


StarVector::StarVector()
{
  v = new Vector(1);
}

StarVector::~StarVector()
{
  delete v;
}

StarVector::long addPlanet()
{
  int size = v.size();
  int dist = rand() % 10000;
  Planet * p = new Planet(dist);
  v->insert(size, p);
  return p->getID();
}

StarVector::bool removePlanet(int id)
{
  Planet * p;
  for (int i=0; i<v.size(); i++) {
    p = v.read(i);
    if (p->getID() == (long)(id)) {
      v.removePlanet(i);
      return true;
    }
  }
  return false;
}

StarVector::Planet * getPlanet(int id)
{
  Planet * p;
  for (int i=0; i<v.size(); i++) {
    if (p->getID() == (long)(id)) return p;
  }
  return NULL;
}

StarVector::void orbit()
{
  Planet * p;
  for (int i=0; i<v.size(); i++) {
    p = v.read(i);
    p->orbit();
  }
}

StarVector::void printStarInfo()
{
  std::cout << "The star currently has " << getCurrentNumPlanets() << " planets.\nPlanets:\n";
  for (int i=0; i<v.size(); i++) {
    Planet * p = v.getPlanet(i)
    std::cout << "Planet " << p->getID() << " is " <<  p->getDistance() << " million miles away at position " <<  p->getPos() << " around the star.\n";
  }
}

StarVector::unsigned int getCurrentNumPlanets()
{
  return (unsigned int)(v.size());
}
