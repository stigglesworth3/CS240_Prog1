#ifndef STARLIST_H
#define STARLIST_H
#include <iostream>
#include <cstdlib>
#include "Planet.h"
#include "Star.h"

class StarList
{
	private:
	//list
	unsigned int numPlanets;
	public:
	StarList();
	~StarList();
	long addPlanet();
	bool removePlanet(int);
	Planet * getPlanet(int);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets() {return numPlanets;}
};
#endif
