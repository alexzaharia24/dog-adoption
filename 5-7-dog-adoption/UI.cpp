#include <iostream>
#include "UI.h"

using namespace std;

/* CONSTRUCTORS */
UI::UI() {
	this->ctrl = new Controller();
}
UI::~UI() {
	delete ctrl;
}

/* MENU */
void UI::mainMenu() {
	Dog d1("Husky", "Sven", 4, "url1");
	Dog d2("German shepard", "Lycan", 6, "url2");
	Dog d3("Rotweiller", "Dragonknight", 3, "url3");

	cout << this->ctrl->add(d1) << endl;
	cout << this->ctrl->add(d2) << endl;
	cout << this->ctrl->add(d3) << endl;
	
	this->printDogs();
	cout << "--- Main Menu ---" << endl;
	
}

/* OPERATIONS */
void UI::printDogs() {
	cout << this->ctrl->getRepo()->getDogs()->toString() << endl;
}