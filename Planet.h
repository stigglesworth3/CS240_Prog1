#pragma once

class Planet {
	private:
		long id;
		int pos;
		int distance;
		char type;

	public:
		Planet(){this->id=-1;};
		Planet(int);
		Planet(int, int);

    		int orbit();
		long getID() { return id; }
		int getDistance() { return distance; }
		int getPos() { return pos; }
		char getType() { return type; }
		//you may add any additional methods you may need.
};
