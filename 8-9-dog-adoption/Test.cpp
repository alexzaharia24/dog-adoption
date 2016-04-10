#include<assert.h>
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
	DynVec<Dog>* dogs = r.getDogs();
	Dog d1{ "a", "b", 0, "c" };
	Dog d2{ "x", "y", 0, "z" };
	Dog d3{ "a", "b", 1, "f" };

	assert(dogs->getSize() == 0);
	r.add(d1);
	assert(dogs->getSize() == 1);
	r.add(d1);
	assert(dogs->getSize() == 1);
	r.add(d2);
	assert(dogs->getSize() == 2);

	r.remove(d2);
	assert(dogs->getSize() == 1);
	r.remove(d2);
	assert(dogs->getSize() == 1);

	r.update(d3);
	assert(dogs->getSize() == 1);
	assert((*dogs)[0].getBreed() == "a");
	assert((*dogs)[0].getName() == "b");
	assert((*dogs)[0].getAge() == 1);
	assert((*dogs)[0].getPhoto() == "f");
}

void Test::testCtrl() {
	Controller c;
	DynVec<Dog>* dogs = c.getRepo()->getDogs();
	assert(dogs->getSize() == 0);

	Dog d1{ "a", "b", 0, "c" };
	Dog d2{ "x", "y", 0, "z" };
	Dog d3{ "m", "n", 1, "f" };
	Dog d4{ "m", "o", 2, "f" };

	c.add(d1);
	c.add(d2);
	c.add(d3);
	c.add(d4);
	assert(dogs->getSize() == 4);

	c.adopt(d1);
	assert(dogs->getSize() == 3);
	assert(c.getAdopted().getSize() == 1);

	assert(c.filter("a", 10).getSize() == 1);
	assert(c.filter("m", 10).getSize() == 2);
	assert(c.filter("a", 0).getSize() == 0);
}

void Test::testAll() {
	testDog();
	testRepo();
	testCtrl();
}