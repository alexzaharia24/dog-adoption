#include <assert.h>
#include <iostream>
#include "Test.h"
#include "DogValidator.h"
#include "CSVAdoptionList.h"

void Test::testDog() {
	Dog d{ "abc", "Xyz", 1, "http" };
	assert(d.getBreed() == "abc");
	assert(d.getName() == "Xyz");
	assert(d.getAge() == 1);
	assert(d.getPhoto() == "http");

	d.setBreed("A");
	d.setName("Abc");
	d.setAge(10);
	d.setPhoto("www");
	try {
		assert(d.getBreed() == "A");
		assert(d.getName() == "Abc");
		assert(d.getAge() == 10);
		assert(d.getPhoto() == "www");
	}
	catch (DogException&) {
	}

}

void Test::testRepo() {
	Repository r;
	vector<Dog> dogs = r.getDogs();
	Dog d1{ "abc", "Abc", 1, "http" };
	Dog d2{ "def", "Def", 2, "www" };
	Dog d3{ "ghi", "Ghi", 3, "http" };
	

	assert(r.getDogs().size() == 0);
	r.add(d1);
	assert(r.getDogs().size() == 1);
	r.add(d1);
	assert(r.getDogs().size() == 1);
	r.add(d2);
	assert(r.getDogs().size() == 2);

	r.remove(d2);
	assert(r.getDogs().size() == 1);
	r.remove(d2);
	assert(r.getDogs().size() == 1);

	r.update(d3);
	assert(r.getDogs().size() == 1);
	assert(r.getDogs()[0].getBreed() == "abc");
	assert(r.getDogs()[0].getName() == "Abc");
	assert(r.getDogs()[0].getAge() == 1);
	assert(r.getDogs()[0].getPhoto() == "http");
}

void Test::testCtrl() {
	Repository r;
	FileAdoptionList* a = new CSVAdoptionList();
	Controller c(r, a, "");
	vector<Dog> dogs = c.getRepo().getDogs();
	assert(c.getRepo().getDogs().size() == 0);

	Dog d1{ "abc", "Abc", 1, "http" };
	Dog d2{ "def", "Def", 2, "www" };
	Dog d3{ "ghi", "Ghi", 3, "http" };
	Dog d4{ "def", "Jkl", 4, "www" };

	c.addDogToRepository(d1);
	c.addDogToRepository(d2);
	c.addDogToRepository(d3);
	c.addDogToRepository(d4);
	assert(c.getRepo().getDogs().size() == 4);

	c.addDogToAdoptionList(d1);
	assert(c.getRepo().getDogs().size() == 3);
	assert(c.getAdopted().size() == 1);

	assert(c.filter("abc", 10).size() == 1);
	assert(c.filter("def", 10).size() == 2);
	assert(c.filter("a", 0).size() == 0);
}

void Test::testAll() {
	testDog();
	testRepo();
	testCtrl();
}