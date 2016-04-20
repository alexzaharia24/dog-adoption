#pragma once
#include<string>
#include<vector>
#include "Dog.h"

class DogException {
private:
	std::vector<std::string> errors;
public:
	DogException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;

};

class DogValidator {
public:
	DogValidator();
	static void validate(Dog& d);

};
