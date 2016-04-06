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
string readCmd() {
	string cmd;
	cout << ">> Enter a command\n";
	cin >> cmd;
	return cmd;
}

void adminCommands() {
	cout << "--- Admin panel ---\n";
	cout << "add	- Add a dog.\n";
	cout << "rem	- Remove a dog.\n";
	cout << "upd	- Update a dog.\n";
	cout << "show	- Show the dogs.\n";
	cout << "b		- Go back.\n";
	cout << "\n";
}
int UI::adminExecute(string cmd) {
	if (cmd == "b") {
		cout << "\n";
		return 1;
	}
	else if (cmd == "add") {
		string breed, name, photo;
		int age;

		cout << "breed = ";
		cin >> breed;
		cout << "name = ";
		cin >> name;
		cout << "age = ";
		cin >> age;
		cout << "photo = ";
		cin >> photo;

		cout << this->ctrl->add(Dog{ breed, name, age, photo });

		cout << "\n";
		return 0;
	}
	else if (cmd == "rem") {
		string breed, name;

		cout << "breed = ";
		cin >> breed;
		cout << "name = ";
		cin >> name;

		cout << this->ctrl->remove(Dog{ breed, name, 0, "" });
		cout << "\n";
		return 0;
	}
	else if (cmd == "upd") {
		string breed, name, photo;
		int age;

		cout << "breed = ";
		cin >> breed;
		cout << "name = ";
		cin >> name;
		cout << "age = ";
		cin >> age;
		cout << "photo = ";
		cin >> photo;

		cout << this->ctrl->update(Dog{ breed, name, age, photo });

		cout << "Update\n";
		return 0;
	}
	else if (cmd == "show") {
		cout << "\n";
		this->printDogs();
		cout << "\n";
		return 0;
	}
	else {
		cout << ">> Wrong command\n";
		cout << "\n";
		return 0;
	}
}
void UI::adminMenu() {
	string cmd;
	adminCommands();
	do {
		cmd = readCmd();
	} while (!adminExecute(cmd));
}

void userCommands() {
	cout << "--- User panel ---\n";
	cout << "bro	- Browose dogs.\n";
	cout << "fil	- Filter dogs.\n";
	cout << "lis	- See adoption list.\n";
	cout << "b		- Go back.\n";
	cout << "\n";
}

int UI::userExecute(string cmd) {
	if (cmd == "b") {
		cout << "Back\n";
		cout << "\n";
		return 1;
	}
	else if (cmd == "bro") {
		cout << "Browse dogs\n";
		browseDogsMenu();
		cout << "\n";
		return 0;
	}
	else if (cmd == "fil") {
		cout << "Filter dogs\n";
		cout << "\n";
		return 0;
	}
	else if (cmd == "lis") {
		cout << "See adoption lists\n";
		cout << "\n";
		return 0;
	}
	else {
		cout << ">> Wrong command\n";
		cout << "\n";
		return 0;
	}
}

void UI::userMenu() {
	string cmd;
	userCommands();
	do {
		cmd = readCmd();
	} while (!userExecute(cmd));
}

void UI::browseDogsMenu() {
	DynVec<Dog>* dogs = this->ctrl->getRepo()->getDogs();
	cout << dogs[1].toString();
}

void menuCommands() {
	cout << "--- Main Menu ---" << endl;
	cout << "admin	- Admin panel.\n";
	cout << "user	- User panel.\n";
	cout << "exit	- Exit application.\n";
	cout << "\n";
}

int UI::mainExecute(string cmd) {
	if (cmd == "exit") {
		cout << "\n";
		return 1;
	}
	else if (cmd == "admin") {
		adminMenu();
		cout << "\n";
		return 0;
	}
	else if (cmd == "user") {
		userMenu();
		cout << "\n";
		return 0;
	}
	else {
		cout << ">> Wrong command\n";
		cout << "\n";
		return 0;
	}
}

void UI::mainMenu() {
	string cmd; 

	Dog d1("Husky", "Sven", 4, "url1");
	Dog d2("German shepard", "Lycan", 6, "url2");
	Dog d3("Rotweiller", "Dragonknight", 3, "url3");
	Dog d4("Husky", "Sven", 5, "url1_1");

	//cout << this->ctrl->add(d1) << endl;
	//cout << this->ctrl->add(d2) << endl;
	//cout << this->ctrl->add(d3) << endl;
	//cout << this->ctrl->update(d4) << endl;

	this->ctrl->add(d1);
	this->ctrl->add(d2);
	this->ctrl->add(d3);
	this->ctrl->update(d4);
	
	//this->printDogs();
	
	do {
		menuCommands();
		cmd = readCmd();
	} while (!mainExecute(cmd));

}

/* OPERATIONS */
void UI::printDogs() {
	cout << this->ctrl->getRepo()->getDogs()->toString() << endl;
}