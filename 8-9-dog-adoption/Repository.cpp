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
std::vector<string> Repository::add(Dog d) {
	vector<Dog>::iterator found = find(this->dogs.begin(), this->dogs.end(), d);
	vector<string> response;

	if (found != dogs.end()) {
		response.push_back("Dog already in the list. Cannot add.");
		return response;
	}
	this->dogs.push_back(d);
	response.push_back("Dog added with success.");
	return response;

}
std::vector<std::string> Repository::remove(Dog d) {
	vector<Dog>::iterator found = find(this->dogs.begin(), this->dogs.end(), d);
	vector<string> response;

	if (found == dogs.end()) {
		response.push_back("Dog not in the list. Cannot remove.");
		return response;
	}
	this->dogs.erase(found);
	response.push_back("Dog removed with success.");
	return response;
}
std::vector<std::string> Repository::update(Dog d) {
	vector<Dog>::iterator found = find(this->dogs.begin(), this->dogs.end(), d);
	vector<string> response;
	
	if (found == dogs.end()) {
		response.push_back("Dog not in the list. Cannot update.");
		return response;
	}
	*found = d;
	response.push_back("Dog updated with success.");
	return response;
}
