#include "Planet.h"

Planet::Planet(int distance){
	this->id = (long)(&this);
	this->distance = distance;

	//⚠️
  this->pos = rand() % 360;
	char[] types = {'h', 'r', 'g'};
	this->type = types[rand() % 3];
}

int Planet::orbit() {
	if (pos >= 359) pos = 0;
	else pos++;
	return pos;
}
