#include "DogValidator.h"

using namespace std;

DogException::DogException (std::vector<std::string> _errors) {
	this->errors = _errors;
}
std::vector<std::string> DogException::getErrors() const {
	return this->errors;
}

DogValidator::DogValidator() {

}
void DogValidator::validate(Dog& d) {
	vector<string> errors;
	if (d.getBreed().size() < 2) {
		errors.push_back(string("Breed should be longer than 2 letters.\n"));
	}
	if (!isupper(d.getName()[0])) {
		errors.push_back(string("Name should begin with capital letter. \n"));
	}
	if (d.getAge() < 0) {
		errors.push_back(string("Age sould be >= 0.\n"));
	}
	
	int posWww = d.getPhoto().find("www");
	int posHttp = d.getPhoto().find("http");
	if (posWww != 0 && posHttp != 0) {
		errors.push_back(string("Url must begin with \"www\" or \"http\". \n"));
	}

	if (errors.size() > 0) {
		throw DogException(errors);
	}
}