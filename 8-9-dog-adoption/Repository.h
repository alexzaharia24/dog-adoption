#pragma once	
#include <vector>
#include "Dog.h"

class Repository {
private:
	vector<Dog> dogs;
public:
	/* CONSTRUCTORS */
	Repository();
	/* Repository constructor */
	~Repository();
	/* Repository destructor */

	/* GETTERS */
	vector<Dog> getDogs();
	/* Get a pointer to the vector of dogs. */

	/* OPERATIONS */
	std::vector<std::string> add(Dog d);
	/* Add a dog to the list.
	Input: d (Dog) - the dog to be added. 
	Output: "Dog added with success." - if the add was successfull
			"Dog already in the list. Cannot add." - if there was a dog with the same name and breed in the list. */
	std::vector<std::string> remove(Dog d);
	/* Remove a dog from the list.
	Input: d (Dog) - the dog to be removed.
	Output: "Dog removed with success." - if the removal was successfull
	"Dog not in the list. Cannot remove." - if there isn't such a dog in the list */
	std::vector<std::string> update(Dog d);
	/* Update a dog from the list.
	Input: d (Dog) - the dog to be updated.
	Output: "Dog updated with success." - if the update was successfull
		"Dog not in the list. Cannot update." - if there isn't such a dog in the list */
};