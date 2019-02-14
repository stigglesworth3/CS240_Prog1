#pragma once

class Planet {
	private:
		long id;
		int pos;
		int distance;
		char type;

	public:
		void insert(int, Planet *p);
		~Vector();

    int orbit();
		long Planet::getID() { return id; }
		int Planet::getDistance() { return distance; }
		int Planet::getPos() { return pos; }
		char Planet::getType() { return type; }
		//you may add any additional methods you may need.
};
