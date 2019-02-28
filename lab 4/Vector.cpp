#include <stdlib.h>

template <class T>
class Vector {

public:

	Vector(){
		this->array = new T*[0];
		arrLength = 0;
	}

	template <class T>
	<T>& operator [](std::size_t index) {

	}

	template <class T>
	Vector(const Vector<T> & v) {
		this->array = v->array;
		this->arrLength = v->arrLength;
	}

	template <class T>
	Vector(int size) {
		this->array = new T*[size];
		arrLength = size;
	}

	template <class T>
	void clear() {
		delete this->array;
		this->array = NULL;
		this->arrLength = 0;
		this->array = new T*[0];
	}

	template <class T>
	read(int index) {
		if (index > this->size() || index < 0) return NULL;
		if (this->array[index] == NULL) return NULL;
		return this->array[index];
	}

	template <class T>
	~Vector() {
		int max = size();
		for (int i=0; i<max; i++) delete this->array[i];
	}

	template <class T>
	void insert(int index, Planet * p) {
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

	template <class T>
	int size() {
		return this->arrLength;
	}

	template <class T> 
	bool remove(int index) {
		if (index == 0 && this->size() == 1) {
			this->arrLength = 0;
			delete this->array[0];
			this->array[0] = NULL;
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
			this->array = arr;
			this->arrLength -= 1;
			return true;
		}
		return false;
	}
}
