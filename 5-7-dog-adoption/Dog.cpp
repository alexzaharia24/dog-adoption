#include "Dog.h"

/* CONSTRUCTORS */
Dog::Dog(string breed, string name, int age, string photo) {
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photo = photo;
}
Dog::Dog(const Dog & d) {
	this->breed = d.breed;
	this->name = d.name;
	this->age = d.age;
	this->photo = d.photo;
}
Dog::~Dog() {}

/* GETTERS */
string Dog::getBreed() {
	return this->breed;
}
string Dog::getName() {
	return this->name;
}
int Dog::getAge() {
	return this->age;
}
string Dog::getPhoto() {
	return this->photo;
}

/* SETTERS */
void Dog::setBreed(string b) {
	this->breed = b;
}
void Dog::setName(string n) {
	this->name = n;
}
void Dog::setAge(int a) {
	this->age = a;
}
void Dog::setPhoto(string p) {
	this->photo = p;
}

/* OPERATORS */
void Dog::operator=(const Dog & d) {
	this->breed = d.breed;
	this->name = d.name;
	this->age = d.age;
	this->photo = d.photo;
}
bool Dog::operator==(const Dog & d) {
	if (this->breed == d.breed && this->name == d.name) {
		return true;
	}
	return false;
}
bool Dog::operator<(const Dog & d) {
	return this->age < d.age;
}
ostream & Dog::operator<<(ostream & Str) {
	Str << this->name << " " << this->breed << " " << this->age << " " << this->photo;
	return Str;
}
