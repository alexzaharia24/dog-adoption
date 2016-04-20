#include <fstream>
#include "Repository.h"
#include "RepositoryExceptions.h"

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

void Repository::readFromFile(string fname) {
	ifstream fin;
	string b, n, p, sep;
	int a;

	fin.open(fname, std::fstream::in);
	if (!fin.is_open()) {
		throw FileException("The file could not be opened for reading.");
	}

	while (!fin.eof()) {
		fin >> b >> sep >> n >> sep >> a >> sep >> p;
		add(Dog{ b,n,a,p });
		/*cout << b << " " << n << " " << a << " " << p << "\n";*/
	}

	fin.close();
}

void Repository::writeToFile(string fname) {
	ofstream fout;
	
	fout.open(fname);
	if (!fout.is_open()) {
		throw FileException("The file could not be opened for writing.");
	}

	for (auto i : getDogs()) {
		fout << i << "\n";
	}
	fout.close();
}