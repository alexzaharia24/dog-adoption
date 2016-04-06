#pragma once
#include <sstream>

template <typename T>
class DynVec {
private:
	int capacity;
	int size;
	T* elems;
	void resize(int factor = 2);
public:
	/* CONSTRUCTORS */
	DynVec(int capacity = 10);
	DynVec(const DynVec& v);
	~DynVec();

	/* OPERATORS */
	DynVec& operator=(const DynVec& v);
	T& operator[](int pos);
	

	/* GETTERS */
	int getSize();
	int getCapacity();

	/* OPERATIONS */
	int find(T e);
	void add(T e);
	void remove(T e);
	void update(T e);
	std::string toString();
};

/* PRIVATE METHODS */
template <typename T>
void DynVec<T>::resize(int factor) {
	this->capacity *= factor;
	T* temp = new T[this->capacity];
	for (int i = 0; i < this->size; i++) {
		temp[i] = this->elems[i];
	}
	delete[] this->elems;
	this->elems = temp;
}

/* CONSTRUCTORS */
template <typename T>
DynVec<T>::DynVec(int capacity) {
	this->capacity = capacity;
	this->size = 0;
	this->elems = new T[capacity];
}
template <typename T>
DynVec<T>::DynVec(const DynVec<T>& v) {
	this->capacity = v.capacity;
	this->size = v.size;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++) {
		this->elems[i] = v.elems[i];
	}
}
template <typename T>
DynVec<T>::~DynVec() {
	delete[] this->elems;
}

/* OPERATORS */
template <typename T>
DynVec<T>& DynVec<T>::operator=(const DynVec<T>& v) {
	if (this == &v) {
		return *this;
	}

	delete[] this->elems;

	this->capacity = v.capacity;
	this->size = v.size;
	this->elems = new T[capacity];
	for (int i = 0; i < this->size; i++) {
		this->elems[i] = v.elems[i];
	}
	return *this;
}
template <typename T>
T& DynVec<T>::operator[](int pos) {
	return this->elems[pos];
}

/* GETTERS */
template <typename T>
int DynVec<T>::getSize() {
	return this->size;
}
template <typename T>
int DynVec<T>::getCapacity() {
	return this->capacity;
}

/* OPERATIONS */
template <typename T>
int DynVec<T>::find(T e) {
	for (int i = 0; i < this->size; i++) {
		if (this->elems[i] == e) {
			return i;
		}
	}
	return -1;
}
template <typename T>
void DynVec<T>::add(T e) {
	if (this->size == this->capacity) {
		this->resize();
	}
	this->elems[this->size] = e;
	this->size++;
}
template <typename T>
void DynVec<T>::remove(T e) {
	int found = this->find(e);
	for (int i = found; i < this->size; i++) {
		this->elems[i] = this->elems[i + 1];
	}
	this->size--;
}
template <typename T>
void DynVec<T>::update(T e) {
	int found = this->find(e);
	this->elems[found] = e;
}
template <typename T>
std::string DynVec<T>::toString() {
	stringstream Str;
	for (int i = 0; i < this->size; i++) {
		Str << this->elems[i] << "\n";
	}
	return Str.str();
}


