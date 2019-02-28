#include "Star.h"
#include "List.h"
#include "Vector.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

StarList::StarList()
{
	this->plans.head = NULL;
	this->plans.tail = NULL;
	this->numPlanets = 0;
}

StarList::~StarList()
{
	while (this->plans.head != this->plans.tail)
	{
		this->plans.head = this->plans.head->next;
		delete this->plans.head->prev;
	}
	delete this->plans.head;
	this->plans.head = this->plans.tail = NULL;
}

long StarList::addPlanet()
{
	Node * toAdd;
	Planet * p = new Planet(rand() % 10000);
	toAdd->plan = p;
	this->numPlanets++;
	this->plans.insert(toAdd->plan->getID(),p);
	return toAdd->plan->getID();
}

bool StarList::removePlanet(int index)
{
	this->numPlanets--;
	return this->plans.remove(index);
}

Planet * StarList::getPlanet(int index)
{
	return this->plans.read(index);
}

void StarList::orbit()
{
	Node * temp = this->plans.head;
	while (temp != NULL)
	{
		temp->plan->orbit();
		temp = temp->next;
	}

}

void StarList::printStarInfo()
{
	Node * temp = this->plans.head;
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
  this->vector = new Vector();
}

StarVector::~StarVector()
{
  delete this->vector;
}

long StarVector::addPlanet()
{
  int size = this->vector.size();
  int dist = rand() % 10000;
  Planet * p = new Planet(dist);
  this->vector.insert(size, p);
  return p->getID();
}

bool StarVector::removePlanet(int id)
{
  Planet * p;
  for (int i=0; i<this->vector.size(); i++) {
    p = this->vector.read(i);
    if (p->getID() == (long)(id)) {
      this->vector.remove(i);
      return true;
    }
  }
  return false;
}

Planet * StarVector::getPlanet(int id)
{
  Planet * p;
  for (int i=0; i<this->vector.size(); i++) {
    if (p->getID() == (long)(id)) return p;
  }
  return NULL;
}

void StarVector::orbit()
{
  Planet * p;
  for (int i=0; i<this->vector.size(); i++) {
    p = this->vector.read(i);
    p->orbit();
  }
}

void StarVector::printStarInfo()
{
  std::cout << "The star currently has " << getCurrentNumPlanets() << " planets.\nPlanets:\n";
  for (int i=0; i<this->vector.size(); i++) {
    Planet * p = this->getPlanet(i);
    std::cout << "Planet " << p->getID() << " is " <<  p->getDistance() << " million miles away at position " <<  p->getPos() << " around the star.\n";
  }
}

unsigned int StarVector::getCurrentNumPlanets()
{
  return ((this->vector.size()));
}
