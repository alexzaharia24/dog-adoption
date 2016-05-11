#include "AdoptionList.h"

AdoptionList::AdoptionList() {
	current = 0;
}

std::vector<Dog> AdoptionList::getAdopted() {
	return adopted;	
}

void AdoptionList::add(const Dog& dog) {
	adopted.push_back(dog);
}

Dog AdoptionList::getCurrentDog() {
	if (current = adopted.size()) {
		current = 0;
	}
	return adopted[current];
}

bool AdoptionList::display() {
	if (adopted.size() == 0) {
		return NULL;
	}
	Dog currentDog = getCurrentDog();
	currentDog.display();
	return true;
}

void AdoptionList::next() {
	if (display() != NULL) {
		current++;
	}
}

bool AdoptionList::isEmpty() {
	return adopted.size() == 0;
}

