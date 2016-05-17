#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include "UI.h"
#include "RepositoryExceptions.h"

/* OPERATIONS */
void UI::printShelterDogs() {
	for (auto d : this->ctrl.getRepo().getDogs())
		cout << d << "\n";
}
void UI::printAdoptedDogs() {
	for (auto d : this->ctrl.getAdopted())
		cout << d << "\n";
}
void UI::printResponse(vector<string> response) {
	for (auto r : response) {
		cout << r;
	}
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

int readNumber() {
	/*	Read a number from the user.
			Output: nr (int) - the read number
					-1 (int) - for bad input. */
	int x;
	cin >> x;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "You need to enter a number. \n";
		return -1;
	}
	return x;
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
	string fname = "dogs.txt";
	if (cmd == "exit") {
		cout << "\n";
		return 1;
	}
	else if (cmd == "add") {
		string breed, name, photo;
		vector<string> response;
		int age;

		cout << "breed = ";
		cin >> breed;
		cout << "name = ";
		cin >> name;
		cout << "age = ";
		age = readNumber();
		if (age == -1) {
			return 0;
		}
		cout << "photo = ";
		cin >> photo;

		cout << "\n";
		try {
			response = this->ctrl.addDogToRepository(Dog{ breed, name, age, photo });
			if (response[0] != "Dog added with success." &&
				response[0] != "Dog already in the list. Cannot add.") {
				cout << ">>> Incorrect dog. Cannot add. <<< \n";
			}
			printResponse(response);
			cout << "\n";
			ctrl.getRepo().writeToFile(fname);
		}
		catch (RepositoryException& e) {
			cout << e.what() << "\n";
		}
		catch (FileException& e) {
			cout << e.what() << "\n";
		}

		return 0;
	}
	else if (cmd == "rem") {
		string breed, name;
		vector<string> response;

		cout << "breed = ";
		cin >> breed;
		cout << "name = ";
		cin >> name;

		cout << "\n";
		try {
			response = this->ctrl.removeDogFromRepository(Dog{ breed, name, 0, "http" });
			if (response[0] != "Dog removed with success." &&
				response[0] != "Dog not in the list. Cannot remove.") {
				cout << ">>> Incorrect dog. Cannot remove. <<< \n";
			}
			printResponse(response);
			cout << "\n";
			ctrl.getRepo().writeToFile(fname);
		}
		catch (RepositoryException& e) {
			cout << e.what() << "\n";
		}
		catch (FileException& e) {
			cout << e.what() << "\n";
		}
		return 0;
	}
	else if (cmd == "upd") {
		string breed, name, photo;
		int age;
		vector<string> response;

		cout << "breed = ";
		cin >> breed;
		cout << "name = ";
		cin >> name;
		cout << "age = ";
		age = readNumber();
		if (age == -1) {
			return 0;
		}
		cout << "photo = ";
		cin >> photo;

		cout << "\n";
		try {
			response = this->ctrl.updateDogFromRepository(Dog{ breed, name, age, photo });
			if (response[0] != "Dog updated with success." &&
				response[0] != "Dog not in the list. Cannot update.") {
				cout << ">>> Incorrect dog. Cannot update. <<< \n";
			}
			printResponse(response);
			cout << "\n";
			ctrl.getRepo().writeToFile(fname);
		}
		catch (RepositoryException& e) {
			cout << e.what() << "\n";
		}
		catch (FileException& e) {
			cout << e.what() << "\n";
		}
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
	cout << "sav	- Save adoption list to file. \n";
	cout << "opn	- Open saved file. \n";
	cout << "exit	- Go back to Main Menu.\n";
	cout << "\n";
}

int UI::userExecute(string cmd) {
	if (cmd == "exit") {
		cout << "\n";
		return 1;
	}
	else if (cmd == "bro") {
		vector<Dog> dogs = this->ctrl.getRepo().getDogs();
		browseDogsMenu(dogs);
		cout << "\n";
		return 0;
	}
	else if (cmd == "fil") {
		string breed;
		int age;

		cout << "breed = ";
		cin >> breed;
		cout << "age = ";
		age = readNumber();
		if (age == -1) {
			return 0;
		}
		cout << "\n";

		vector<Dog> result = this->ctrl.filter(breed, age);
		if (result.size() == 0) {
			cout << "No such dogs.";
		}
		else {
			browseDogsMenu(result);
		}

		cout << "\n";
		return 0;
	}
	else if (cmd == "lis") {
		cout << "\n=== Adoption list. === \n";
		if (this->ctrl.getAdopted().size() == 0) {
			cout << "\nNo adoption yet.";
		}
		browseAdoptedDogs(this->ctrl.getAdopted());
		return 0;
	}
	else if (cmd == "sav") {
		string fname;
		cout << "Enter file name: ";
		cin >> fname;

		try {
			this->ctrl.saveAdoptionListToFile(fname);
		}
		catch (FileException& e) {
			cout << e.what() << endl;
		}

		cout << "Saved\n";
	}
	else if (cmd == "opn") {
		try {
			if (this->ctrl.getExportType() == "CSV") {
				string prog = "";
				cout << "1 - Notepad\n";
				cout << "2 - Excel\n";
				cin >> prog;
				while (prog != "1" && prog != "2") {
					cout << "Wrong program.\n";
					cin >> prog;
				}
				cout << "\n";
				this->ctrl.openAdoptionList(prog);
			}
			else {
				this->ctrl.openAdoptionList("");
			}
		}
		catch (FileException& e) {
			cout << e.what() << endl;
		}
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



void UI::browseDogsMenu(vector<Dog>& dogs) {
	
	int i = 0;
	string cmd;
	while (1) {
		if (dogs.size() == 0) {
			cout << "\nThere are no dogs up for adoption. \n";
			return;
		}
		if (i == dogs.size() ) {
			i = 0;
		}
		Dog d = (dogs)[i];
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
			this->ctrl.addDogToAdoptionList(d);
			dogs.erase(dogs.begin() + i);
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

void UI::browseAdoptedDogs(vector<Dog>& dogs) {
	int i = 0;
	string cmd;
	while (1) {
		if (dogs.size() == 0) {
			cout << "\nThere are no adopted dogs. \n";
			return;
		}
		if (i == dogs.size()) {
			i = 0;
		}
		Dog d = (dogs)[i];
		d.display();

		cout << "\n";
		cout << d << "\n";
		cout << "next	- Next dog.\n";
		cout << "exit	- Go back to the User Panel.\n";
		cout << "\n";

		cmd = readCmd();
		if (cmd == "exit") {
			break;
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
	string cmd, fname = "dogs.txt";

	ctrl.getRepo().readFromFile(fname);
	
	do { 
		menuCommands();
		cmd = readCmd();
	} while (!mainExecute(cmd));

	ctrl.getRepo().writeToFile(fname);
}

