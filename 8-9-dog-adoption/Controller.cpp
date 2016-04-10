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
vector<Dog> Controller::getAdopted() {
	return this->adopted;
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

void Controller::adopt(Dog d) {
	adopted.push_back(d);
	repo->remove(d);
}
vector<Dog> Controller::filter(string breed, int age) {
	vector<Dog> in_shelter = this->getRepo()->getDogs();
	vector<Dog> adopted = this->getAdopted();
	vector<Dog> result;
	for (unsigned i = 0; i < in_shelter.size(); i++) {
		Dog d(in_shelter[i]);
		if (d.getBreed() == breed && d.getAge() < age) {
			result.push_back(d);
		}
	}
	for (unsigned i = 0; i < adopted.size(); i++) {
		Dog d(adopted[i]);
		if (d.getBreed() == breed && d.getAge() < age) {
			result.push_back(d);
		}
	}
	return result;
}


