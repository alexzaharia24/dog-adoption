#pragma once
#include <vector>
#include "DogValidator.h"
#include "Repository.h"
#include "FileAdoptionList.h"

class Controller {
private:
	Repository repo;
	FileAdoptionList *adoptionList;
	DogValidator validator;
	string export_type;
public:
	/* CONTSTRUCTORS */
	Controller(const Repository& r, FileAdoptionList *a, string e) : repo{ r }, adoptionList{ a }, export_type{ e } {};
	/* Controller constructor. */
	~Controller();
	/* Controller destructor. */

	/* GETTERS */
	Repository& getRepo();
	/* Get a refference to the repository. */
	vector<Dog> getAdopted();
	/* Get the list of adopted dogs. */
	AdoptionList* getAdoptionList() const;
	/* Get object to the adoption list. */

	/* OPERATIONS */
	std::vector<std::string> addDogToRepository(Dog dog);
	/* Add a dog to the whole list of dogs. */
	std::vector<std::string> addDogToAdoptionList(const Dog& dog);
	/* Add a dog to the adoption list. */
	std::vector<std::string> removeDogFromRepository(Dog d);
	/* Remove a dog from the list of dogs. */
	std::vector<std::string> updateDogFromRepository(Dog d);
	/* Update a dog from the list of dogs. */
	//void adopt(Dog d);
	/* User adopts a dog. The adopted dog will be deleted from the initial list and added to the adopted dogs list.
		Input:	d (Dog) - the dog to be adopted */
	vector<Dog> filter(string breed, int age);
	/* Filter the list of dogs. Return the list of dogs that have a given breed and whose age is smaller than the given one. 
		Input:	breed (string)  - the given breed 
				age (int)		- the given age
		Output: the list of dogs that match the criteria. */

	void saveAdoptionListToFile(string fname);
	void openAdoptionList();
};