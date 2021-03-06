#include "Vector.h"
#include "Planet.h"
#include <stdlib.h>

#define MAX_SIZE 100

Vector::Vector(){
	this->array = new Planet*[0];
	arrLength = 0;
}

Vector::Vector(int size){
	this->array = new Planet*[size];
	arrLength = size;
}

Planet* Vector::read(int index) {
	if (index > this->size() || index < 0) return NULL;
	if (this->array[index] == NULL) return NULL;
	return this->array[index];
}

Vector::~Vector() {
	int max = size();
	for (int i=0; i<max; i++) delete this->array[i];
}

void Vector::insert(int index, Planet * p) {
	if (index < this->size()) {
		this->array[index] = p;
		this->arrLength = arrLength + 1;
	}
	else {
		// newSize = (arrLength + arrLength-index-1)
		Planet** arr = new Planet*[index+1];
		for (int i=0; i<this->size(); i++) {
			arr[i] = this->array[i];
		}
		arr[index] = p;
		this->arrLength = index + 1;
		delete this->array;
		this->array = arr;
	}
}


int Vector::size() {
    return this->arrLength;
}

bool Vector::remove(int index) {
	if (index == 0 && this->size() == 1) {
		this->arrLength = 0;
		this->array[0] = NULL;
		this->array = NULL;
		return true;
	}
	if (index < this->size() && index >= 0) {
		Planet** arr = new Planet*[this->size()-1];
		int k = 0;
		for (int i=0; i<this->size()-1; i++) {
			if (index != i) {
				arr[i] = this->array[i];
				k++;
			}
			else {
				arr[i] = arr[k+1];
				k += 2;
			}
		}
	delete this->array;
	this->array = NULL;
	this->array = arr;
	this->arrLength -= 1;
	return true;
	}
	return false;
}
