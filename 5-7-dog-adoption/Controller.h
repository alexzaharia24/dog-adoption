#pragma once
#include "Repository.h"

class Controller {
private:
	Repository* repo;
public:
	/* CONTSTRUCTORS */
	Controller();
	~Controller();

	/* GETTERS */
	Repository* getRepo();

	/* OPERATIONS */
	std::string add(Dog d);
	std::string remove(Dog d);
	std::string update(Dog d);

};