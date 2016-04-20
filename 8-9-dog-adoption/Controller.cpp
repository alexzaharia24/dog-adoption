#include <algorithm>
#include <iterator>
#include "Controller.h"

/* CONSTRUCTORS */
Controller::Controller(string export_type) {
	this->repo = new Repository();
	this->export_type = export_type;
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
		copy_if(in_shelter.begin(), in_shelter.end(), back_inserter(result), [=](Dog& d) { return 1; });
		copy_if(adopted.begin(), adopted.end(), back_inserter(result), [=](Dog& d) { return 1; });

		/*for (auto i : in_shelter) {
			Dog d(i);
			result.push_back(d);
		}
		for (auto i : adopted) {
			Dog d(i);
			result.push_back(d);
		}
		return result;*/
	}
	copy_if(in_shelter.begin(), in_shelter.end(), back_inserter(result), [=](Dog& d) { return d.getBreed() == breed && d.getAge() < age; });
	copy_if(adopted.begin(), adopted.end(), back_inserter(result), [=](Dog& d) { return d.getBreed() == breed && d.getAge() < age; });
	/*for (auto i : in_shelter) {

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
	}*/
	return result;
}


