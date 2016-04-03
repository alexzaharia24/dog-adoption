#include "Repository.h"

/* CONSTRUCTORS */
Repository::Repository() {
	this->dogs = new DynVec<Dog>;
}
Repository::~Repository() {
	delete dogs;
}

/* GETTERS */
DynVec<Dog>* Repository::getDogs() {
	return this->dogs;
}

/* OPERATIONS */
std::string Repository::add(Dog d) {
	if (this->dogs->find(d) != -1) {
		return "Dog already in the list. Cannot add.";
	}
	this->dogs->add(d);
	return "Dog added with success.";
}
std::string Repository::remove(Dog d) {
	int found = this->dogs->find(d);
	if (found == -1) {
		return "Dog not in the list. Cannot delete.";
	}
	this->dogs->remove(d);
	return "Dog removed with success.";
}
std::string Repository::update(Dog d) {
	int found = this->dogs->find(d);
	if (found == -1) {
		return "Dog not in the list. Cannot update.";
	}
	this->dogs->update(d);
	return "Dog updated with success.";
}
