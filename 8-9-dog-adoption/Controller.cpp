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
vector<string> Controller::add(Dog d) {
	try {
		this->validator.validate(d);
	}
	catch (DogException& e) {
		return e.getErrors();
	}
	return this->repo->add(d);
}
vector<string> Controller::remove(Dog d) {
	try {
		this->validator.validate(d);
	}
	catch (DogException& e) {
		return e.getErrors();
	}
	return this->repo->remove(d);
}
vector<string> Controller::update(Dog d) {
	try {
		this->validator.validate(d);
	}
	catch (DogException& e) {
		return e.getErrors();
	}
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

	if (breed == "" || breed == "\n") {
		for (auto i : in_shelter) {
			Dog d(i);
			result.push_back(d);
		}
		for (auto i : adopted) {
			Dog d(i);
			result.push_back(d);
		}
		return result;
	}
	for (auto i : in_shelter) {
		Dog d(i);
		if (d.getBreed() == breed && d.getAge() < age) {
			result.push_back(d);
		}
	}
	for (auto i : adopted) {
		Dog d(i);
		if (d.getBreed() == breed && d.getAge() < age) {
			result.push_back(d);
		}
	}
	return result;
}


