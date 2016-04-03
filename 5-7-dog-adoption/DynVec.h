#pragma once
template <typename T>
class DynVec {
private:
	int capacity;
	int size;
	T* elems;
	void resize(int factor = 2);
public:
	DynVec(int capacity = 10);
	DynVec(const DynVec& v);
	~DynVec();
	DynVec& operator=(const DynVec<T>& v);
	int getSize();
	int getCapacity();

	T operator[](int pos);
	void add(T e);
	void remove(T e);
	
};

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

template <typename T>
DynVec<T>::DynVec(int capacity) {
	this->capacity = capacity;
	this->size = 0;
	this->elems = new T[capacity];
}

template <typename T>
DynVec<T>::DynVec(const DynVec& v) {
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

/* GETTERS */
template <typename T>
int DynVec<T>::getSize() {
	return this->size;
}

template <typename T>
int DynVec<T>::getCapacity() {
	return this->capacity;
}

template <typename T>
T DynVec<T>::operator[](int pos) {
	return this->elems[pos];
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
}

