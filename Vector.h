#ifndef VECTOR_H
#define VECTOR_H
#include "Planet.h"

class Vector {
	private:
		Planet** array;

	public:
		void insert(int, Planet *);
		~Vector();
		Vector();
		Vector(int);
		

		Planet* read(int);
		bool remove(int);
		int size();
		void setSize(int);
		//you may add any additional methods you may need.
};
#endif
