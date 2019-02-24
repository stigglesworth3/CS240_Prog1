#include "Star.h"
#include "List.h"
#include "Vector.h"
#include <stdlib.h>
#include <iostream>

StarList::StarList()
{
	this->stars->head = NULL;
	this->stars->tail = NULL;
	this->numPlanets = 0;
}

StarList::~StarList()
{
}

long StarList::addPlanet()
{
}

bool StarList::removePlanet(int)
{
}

Planet * StarList::getPlanet(int)
{
}

void StarList::orbit()
{
}

void StarList::printStarInfo()
{
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
