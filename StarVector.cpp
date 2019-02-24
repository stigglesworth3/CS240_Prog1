#include "Star.h"
#include <stdlib.h>
#include <iostream>

Star::Star() {
	current_planets = 0;
	planets = NULL;
}

Star::~Star() {
	for (int i=0; i<current_planets; i++) delete planets[i];
}

int Star::addPlanet() {
	  Planet* newPlanet = new Planet(current_planets);
		Planet ** newArray = (Planet **) malloc (current_planets + 1);
		for (int i=0; i<current_planets; i++) {
			newArray[i] = planets[i];
		}
		newArray[current_planets] = newPlanet;
		free(planets);
		planets = newArray;
		current_planets++;
		return current_planets-1;
}

bool Star::removePlanet() {
		for (int i=0; i<current_planets; i++) {
			newArray[i] = planets[i];
		}
		newArray[current_planets] = newPlanet;
		free(planets);
		planets = newArray;
		current_planets++;
		return current_planets-1;
}

Planet Star::getFurthest() {
  //	if (current_planets < 1) return NULL;
	int maxIndex = 0;
	for (int i=1; i<current_planets; i++) {
	  if (planets[maxIndex].getDistance() < planets[i].getDistance()) maxIndex = i;
	}
	return planets[maxIndex];
}

void Star::orbit() {
	for (int i=0; i<current_planets; i++) {
		planets[i].orbit();
	}
}

void Star::printStarInfo() {
	std::cout << "The star currently has " << current_planets << " planets.\nThe star can support up to " << max_planets << " planets.\nPlanets:\n";
	for (int i=0; i<current_planets; i++) std::cout << "Planet " << planets[i].getID() << " is " <<  planets[i].getDistance() << " million miles away at " <<  planets[i].getPos() << " around the star.\n";
}

int Star::getCurrentNumPlanets() {
	return current_planets;
}
