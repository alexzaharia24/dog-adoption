#include <assert.h>
#include <iostream>
#include "Test.h"

void Test::testDog() {
	Dog d{ "a", "b", 0, "c" };
	assert(d.getBreed() == "a");
	assert(d.getName() == "b");
	assert(d.getAge() == 0);
	assert(d.getPhoto() == "c");

	d.setBreed("A");
	d.setName("B");
	d.setAge(10);
	d.setPhoto("C");
	assert(d.getBreed() == "A");
	assert(d.getName() == "B");
	assert(d.getAge() == 10);
	assert(d.getPhoto() == "C");

}

void Test::testRepo() {
	Repository r;
	vector<Dog> dogs = r.getDogs();
	Dog d1{ "a", "b", 0, "c" };
	Dog d2{ "x", "y", 0, "z" };
	Dog d3{ "a", "b", 1, "f" };

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
	assert(r.getDogs()[0].getBreed() == "a");
	assert(r.getDogs()[0].getName() == "b");
	assert(r.getDogs()[0].getAge() == 1);
	assert(r.getDogs()[0].getPhoto() == "f");
}

void Test::testCtrl() {
	Controller c;
	vector<Dog> dogs = c.getRepo()->getDogs();
	assert(c.getRepo()->getDogs().size() == 0);

	Dog d1{ "a", "b", 0, "c" };
	Dog d2{ "x", "y", 0, "z" };
	Dog d3{ "m", "n", 1, "f" };
	Dog d4{ "m", "o", 2, "f" };

	c.add(d1);
	c.add(d2);
	c.add(d3);
	c.add(d4);
	assert(c.getRepo()->getDogs().size() == 4);

	c.adopt(d1);
	assert(c.getRepo()->getDogs().size() == 3);
	assert(c.getAdopted().size() == 1);

	assert(c.filter("a", 10).size() == 1);
	assert(c.filter("m", 10).size() == 2);
	assert(c.filter("a", 0).size() == 0);
}

void Test::testAll() {
	testDog();
	testRepo();
	testCtrl();
}