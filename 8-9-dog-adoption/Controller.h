#pragma once
#include "Repository.h"

class Controller {
private:
	Repository* repo;
	DynVec<Dog> adopted;
public:
	/* CONTSTRUCTORS */
	Controller();
	/* Controller constructor. */
	~Controller();
	/* Controller destructor. */

	/* GETTERS */
	Repository* getRepo();
	/* Get a refference to the repository. */
	DynVec<Dog> getAdopted();
	/* Get the list of adopted dogs. */

	/* OPERATIONS */
	std::string add(Dog d);
	/* Add a dog to the list of dogs. */
	std::string remove(Dog d);
	/* Remove a dog from the list of dogs. */
	std::string update(Dog d);
	/* Update a dog from the list of dogs. */
	void adopt(Dog d);
	/* User adopts a dog. The adopted dog will be deleted from the initial list and added to the adopted dogs list.
		Input:	d (Dog) - the dog to be adopted */
	DynVec<Dog> filter(string breed, int age);
	/* Filter the list of dogs. Return the list of dogs that have a given breed and whose age is smaller than the given one. 
		Input:	breed (string)  - the given breed 
				age (int)		- the given age
		Output: the list of dogs that match the criteria. */
};