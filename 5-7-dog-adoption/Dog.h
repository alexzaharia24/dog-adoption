#pragma once	
#include <string>
using namespace std;

class Dog {
private:
	string breed;
	string name;
	int age;
	string photo;
public:
	/* CONSTURCTOR */
	Dog();
	Dog(string breed, string name, int age, string photo);
	Dog(const Dog& d);
	~Dog();

	/* GETTERS */
	string getBreed();
	string getName();
	int getAge();
	string getPhoto();

	/* SETTERS */
	void setBreed(string b);
	void setName(string n);
	void setAge(int a);
	void setPhoto(string p);

	/* OPERATORS */
	void operator=(const Dog& d);
	bool operator==(const Dog& d);
	bool operator<(const Dog& d);
	
	friend ostream& operator<<(ostream& Str, const Dog& d);

};