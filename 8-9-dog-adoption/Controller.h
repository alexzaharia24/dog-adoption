#pragma once
#include <vector>
#include "Repository.h"
#include "DogValidator.h"

class Controller {
private:
	Repository* repo;
	vector<Dog> adopted;
	DogValidator validator;
	string export_type;
public:
	/* CONTSTRUCTORS */
	Controller(string export_type);
	/* Controller constructor. */
	~Controller();
	/* Controller destructor. */

	/* GETTERS */
	Repository* getRepo();
	/* Get a refference to the repository. */
	vector<Dog> getAdopted();
	/* Get the list of adopted dogs. */

	/* OPERATIONS */
	std::vector<std::string> add(Dog d);
	/* Add a dog to the list of dogs. */
	std::vector<std::string> remove(Dog d);
	/* Remove a dog from the list of dogs. */
	std::vector<std::string> update(Dog d);
	/* Update a dog from the list of dogs. */
	void adopt(Dog d);
	/* User adopts a dog. The adopted dog will be deleted from the initial list and added to the adopted dogs list.
		Input:	d (Dog) - the dog to be adopted */
	vector<Dog> filter(string breed, int age);
	/* Filter the list of dogs. Return the list of dogs that have a given breed and whose age is smaller than the given one. 
		Input:	breed (string)  - the given breed 
				age (int)		- the given age
		Output: the list of dogs that match the criteria. */
};