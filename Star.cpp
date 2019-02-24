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

