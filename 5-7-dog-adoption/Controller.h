#pragma once
#include "Repository.h"

class Controller {
private:
	Repository* repo;
	DynVec<Dog> adopted;
public:
	/* CONTSTRUCTORS */
	Controller();
	~Controller();

	/* GETTERS */
	Repository* getRepo();
	DynVec<Dog> getAdopted();

	/* OPERATIONS */
	std::string add(Dog d);
	std::string remove(Dog d);
	std::string update(Dog d);
	void adopt(Dog d);
	DynVec<Dog> filter(string breed, int age);

};