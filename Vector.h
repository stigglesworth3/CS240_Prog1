#pragma once

class Vector {
	private:
		Planet* array;

	public:
		void insert(int, Planet *p);
		~Vector();

		Planet* read(int);
		bool remove(int);
		unsigned size();
		//you may add any additional methods you may need.
};
