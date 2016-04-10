#include "Repository.h"

/* CONSTRUCTORS */
Repository::Repository() {
}
Repository::~Repository() {}

/* GETTERS */
vector<Dog> Repository::getDogs() {
	return this->dogs;
}

/* OPERATIONS */
std::string Repository::add(Dog d) {
	vector<Dog>::iterator found = find(this->dogs.begin(), this->dogs.end(), d);
	if (found != dogs.end()) {
		return "Dog already in the list. Cannot add.";
	}
	this->dogs.push_back(d);
	return "Dog added with success.";
}
std::string Repository::remove(Dog d) {
	vector<Dog>::iterator found = find(this->dogs.begin(), this->dogs.end(), d);
	if (found == dogs.end()) {
		return "Dog not in the list. Cannot remove.";
	}
	this->dogs.erase(found);
	return "Dog removed with success.";
}
std::string Repository::update(Dog d) {
	vector<Dog>::iterator found = find(this->dogs.begin(), this->dogs.end(), d);
	if (found == dogs.end()) {
		return "Dog not in the list. Cannot update.";
	}
	*found = d;
	return "Dog updated with success.";
}
