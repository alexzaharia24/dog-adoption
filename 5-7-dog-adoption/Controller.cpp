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
<<<<<<< HEAD
=======
DynVec<Dog> Controller::getAdopted() {
	return this->adopted;
}
>>>>>>> develop

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
<<<<<<< HEAD

=======
void Controller::adopt(Dog d) {
	adopted.add(d);
	repo->remove(d);
}
DynVec<Dog> Controller::filter(string breed, int age) {
	DynVec<Dog>* in_shelter = this->getRepo()->getDogs();
	DynVec<Dog> adopted = this->getAdopted();
	DynVec<Dog> result;
	for (int i = 0; i < in_shelter->getSize(); i++) {
		Dog d((*in_shelter)[i]);
		if (d.getBreed() == breed && d.getAge() < age) {
			result.add(d);
		}
	}
	for (int i = 0; i < adopted.getSize(); i++) {
		Dog d(adopted[i]);
		if (d.getBreed() == breed && d.getAge() < age) {
			result.add(d);
		}
	}
	return result;
}
>>>>>>> develop

