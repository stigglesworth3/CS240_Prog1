#ifndef VECTOR_H
#define VECTOR_H

class Vector {
	private:
		Planet* array;

	public:
		void insert(int, Planet *p);
		~Vector();

		Planet* read(int);
		bool remove(int);
		unsigned size();
		void setSize(int);
		//you may add any additional methods you may need.
};
#endif
