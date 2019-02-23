#ifndef STAR_H
#define STAR_H
#include "Planet.h"
#include "List.h"
#include "Vector.h"

class StarList
{
	private:
	List stars;
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
class StarVector
{
	private:
	Vector v;
	unsigned int numPlanets;

	public:
	StarVector();
	~StarList();
	long addPlanet();
	bool removePlanet(int);
	Planet * getPlanet(int);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets();
}

#endif
