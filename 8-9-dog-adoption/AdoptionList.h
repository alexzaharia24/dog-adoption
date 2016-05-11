#pragma once
#include <vector>
#include "Dog.h"

class AdoptionList {
private:
	std::vector<Dog> adopted;
	int current;
public:
	AdoptionList();
	
	std::vector<Dog> getAdopted();

	void add(const Dog& dog);

	Dog getCurrentDog();

	bool display();

	void next();

	bool isEmpty();

	virtual ~AdoptionList() {}
};