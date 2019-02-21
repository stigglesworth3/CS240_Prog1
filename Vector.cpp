#include "Vector.h"

Vector::Vector(int size){
	this->array = new Planet[size];
}

Planet* Vector::read(int index) {
	if (index >= this->size() || index < 0) return NULL;
	return this->array[index];
}

Vector::~Vector() {
	int max = size();
	for (int i=0; i<max; i++) delete this->array[i];
}

void Vector::insert(int index, Planet * p) {
	if (index < this->size()) this->array[index] = p;
	else {
		// increase size to index+1
		this->array = (Planet*) realloc (planets, sizeof(Planet));
		this->array[index] = p;
	}
}

void Vector::setSize() {
	
}

bool Vector::remove(int index) {
	if (index < this->size() && index >= 0) {
	this->array[index] = NULL;
	for (int i=index; i<this->size()-1; i++) {
		array[i] = array[i+1];
	}
	delete array[this->size()-1];
	setSize(this->size()-1);
	return true;
	}
	return false;
}
