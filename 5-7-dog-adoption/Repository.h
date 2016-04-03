#pragma once	

#include "Dog.h"
#include "DynVec.h"

class Repository {
private:
	DynVec<Dog>* dogs;
public:
	/* CONSTRUCTORS */
	Repository();
	~Repository();

	/* GETTERS */
	DynVec<Dog>* getDogs();

	/* OPERATIONS */
	std::string add(Dog d);
	std::string remove(Dog d);
	std::string update(Dog d);

};