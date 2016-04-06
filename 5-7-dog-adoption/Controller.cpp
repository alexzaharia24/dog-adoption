#include "Controller.h"

/* CONSTRUCTORS */
Controller::Controller() {
	this->repo = new Repository();
}
Controller::~Controller() {
	delete repo;
}

/* GETTERS */
Repository * Controller::getRepo() {
	return this->repo;
}

/* OPERATIONS*/
std::string Controller::add(Dog d) {
	return this->repo->add(d);
}
std::string Controller::remove(Dog d) {
	return this->repo->remove(d);
}
std::string Controller::update(Dog d) {
	return this->repo->update(d);
}


