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
	/* Read a command from the user.
	Output: cmd (string) - the read command */
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
	cout << "exit	- Go back to Main Menu.\n";
	cout << "\n";
}
int UI::adminExecute(string cmd) {
	if (cmd == "exit") {
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

		return 0;
	}
	else if (cmd == "show") {
		cout << "\n";
		this->printShelterDogs();
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
	
	do {
		cout << "\n";
		adminCommands();
		cmd = readCmd();
	} while (!adminExecute(cmd));
}

void userCommands() {
	cout << "\n--- User panel ---\n";
	cout << "bro	- Browose dogs.\n";
	cout << "fil	- Filter dogs.\n";
	cout << "lis	- See adoption list.\n";
	cout << "exit	- Go back to Main Menu.\n";
	cout << "\n";
}

int UI::userExecute(string cmd) {
	if (cmd == "exit") {
		cout << "\n";
		return 1;
	}
	else if (cmd == "bro") {
		DynVec<Dog>* dogs = this->ctrl->getRepo()->getDogs();
		browseDogsMenu(dogs);
		cout << "\n";
		return 0;
	}
	else if (cmd == "fil") {
		string breed;
		int age;
		cout << "Filter dogs\n";

		cout << "breed = ";
		cin >> breed;
		cout << "age = ";
		cin >> age;
		cout << "\n";

		DynVec<Dog> result = this->ctrl->filter(breed, age);
		if (result.getSize() == 0) {
			cout << "No such dogs.";
		}
		else {
			browseDogsMenu(&result);
		}

		cout << "\n";
		return 0;
	}
	else if (cmd == "lis") {
		cout << "\n=== Adoption list. === \n";
		if (this->ctrl->getAdopted().getSize() == 0) {
			cout << "\nNo adoption yet.";
		}
		browseDogsMenu(&this->ctrl->getAdopted());
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
	do {
		userCommands();
		cmd = readCmd();
	} while (!userExecute(cmd));
}

void UI::browseDogsMenu(DynVec<Dog>* dogs) {
	
	
	int i = 0;
	string cmd;
	while (1) {
		if (dogs->getSize() == 0) {
			cout << "\nThere are no dogs up for adoption. \n";
			return;
		}
		if (i == dogs->getSize()) {
			i = 0;
		}
		Dog d = (*dogs)[i];
		d.display();


		cout << "\n";
		cout << d << "\n";
		cout << "ado	- Adopt "<<d.getName()<<". \n";
		cout << "next	- Next dog.\n";
		cout << "exit	- Go back to the User Panel.\n";
		cout << "\n";

		cmd = readCmd();
		if (cmd == "exit") {
			break;
		}
		else if (cmd == "ado") {
			cout << "\n";
			cout << ">>> "<<d.getName() << " was adopted.\n";
			this->ctrl->adopt(d);
			continue;
		}
		else if (cmd == "next") {
			i++;
			continue;
		}
		else {
			cout << ">> Wrong command.\n";
		}
	}
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

	Dog d1("Husky", "Sven", 4, "http://goo.gl/647s1X");
	Dog d2("Wolf", "Lycan", 6, "http://goo.gl/PUxwwT");
	Dog d3("Rotweiller", "Knight", 3, "https://goo.gl/5oIYRa");
	Dog d4("Husky", "Sven", 5, "http://goo.gl/hCINq1");

	this->ctrl->add(d1);
	this->ctrl->add(d2);
	this->ctrl->add(d3);
	this->ctrl->update(d4);
	
	do { 
		menuCommands();
		cmd = readCmd();
	} while (!mainExecute(cmd));

}

/* OPERATIONS */
void UI::printShelterDogs() {
	cout << this->ctrl->getRepo()->getDogs()->toString() << endl;
}
void UI::printAdoptedDogs() {
	cout << this->ctrl->getAdopted().toString() << endl;
}