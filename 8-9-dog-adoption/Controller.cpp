#include <algorithm>
#include <iterator>
#include <iostream>
#include "Controller.h"

/* CONSTRUCTORS */
Controller::~Controller() {
}

/* GETTERS */
Repository& Controller::getRepo() {
	return this->repo;
}
vector<Dog> Controller::getAdopted() {
	return adoptionList->getAdopted();
}

AdoptionList* Controller::getAdoptionList() const {
	return adoptionList;
}
string Controller::getExportType() const {
	return this->export_type;
}
/* OPERATIONS*/
std::vector<std::string> Controller::addDogToRepository(Dog dog)
{
	try {
		this->validator.validate(dog);
	}
	catch (DogException& e) {
		return e.getErrors();
	}
	return this->repo.add(dog);
}

std::vector<std::string> Controller::addDogToAdoptionList(const Dog& dog) {
	adoptionList->add(dog);
	repo.remove(dog);
	return vector<string>{"Adopted\n"};
}

vector<string> Controller::removeDogFromRepository(Dog d) {
	try {
		this->validator.validate(d);
	}
	catch (DogException& e) {
		return e.getErrors();
	}
	return this->repo.remove(d);
}
vector<string> Controller::updateDogFromRepository(Dog d) {
	try {
		this->validator.validate(d);
	}
	catch (DogException& e) {
		return e.getErrors();
	}
	return this->repo.update(d);
}

//void Controller::adopt(Dog d) {
//	adopted.push_back(d);
//	repo.remove(d);
//}


vector<Dog> Controller::filter(string breed, int age) {
	vector<Dog> in_shelter = this->repo.getDogs();
	vector<Dog> adopted = this->getAdopted();
	vector<Dog> result;

	if (breed == "" || breed == "\n") {
		copy_if(in_shelter.begin(), in_shelter.end(), back_inserter(result), [=](Dog& d) { return 1; });
		copy_if(adopted.begin(), adopted.end(), back_inserter(result), [=](Dog& d) { return 1; });
	}
	copy_if(in_shelter.begin(), in_shelter.end(), back_inserter(result), [=](Dog& d) { return d.getBreed() == breed && d.getAge() < age; });
	copy_if(adopted.begin(), adopted.end(), back_inserter(result), [=](Dog& d) { return d.getBreed() == breed && d.getAge() < age; });
	return result;
}

void Controller::saveAdoptionListToFile(string fname) {
	if (this->adoptionList == nullptr) {
		return;
	}
	this->adoptionList->writeToFile(fname);
}

void Controller::openAdoptionList(string prog) {
	try {
		this->adoptionList->displayAdoptionList(prog);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

