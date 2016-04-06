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

void adminMenu() {
	cout << "--- Admin panel ---\n";
	cout << "add	- Add a dog.\n";
	cout << "rem	- Remove a dog.\n";
	cout << "upd	- Update a dog.\n";
	cout << "show	- Show the dogs.\n";
	cout << "\n";
}

void userMenu() {
	cout << "--- User panel ---\n";

	cout << "\n";
}

/* MENU */
void UI::mainMenu() {
	Dog d1("Husky", "Sven", 4, "url1");
	Dog d2("German shepard", "Lycan", 6, "url2");
	Dog d3("Rotweiller", "Dragonknight", 3, "url3");
	Dog d4("Husky", "Sven", 5, "url1_1");

	cout << this->ctrl->add(d1) << endl;
	cout << this->ctrl->add(d2) << endl;
	cout << this->ctrl->add(d3) << endl;
	cout << this->ctrl->update(d4) << endl;
	
	this->printDogs();
	cout << "--- Main Menu ---" << endl;
	cout << "admin - Admin panel.\n";
	cout << "user - User panel.\n";
	cout << "\n";
}

/* OPERATIONS */
void UI::printDogs() {
	cout << this->ctrl->getRepo()->getDogs()->toString() << endl;
}