#ifndef STAR_H
#define STAR_H
#include "Planet.h"

class Star {
	private:
        int current_planets;
        int next_id;
	public:
        Planet **planets;
        Star();
	~Star();
        int addPlanet();
        Planet getFurthest();
        void orbit();
        void printStarInfo();
        int getCurrentNumPlanets();
        int getMaxPlanets();
        //you may add any additional methodas you may need.
};
#endif
