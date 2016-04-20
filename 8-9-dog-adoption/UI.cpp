#include <iostream>
#include <fstream>
#include "UI.h"

using namespace std;

/* CONSTRUCTORS */
UI::UI() {
	this->ctrl = new Controller();
}
UI::~UI() {
	delete ctrl;
}

/* OPERATIONS */
void UI::printShelterDogs() {
	for (auto d : this->ctrl->getRepo()->getDogs())
		cout << d << "\n";
}
void UI::printAdoptedDogs() {
	for (auto d : this->ctrl->getAdopted())
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
		response = this->ctrl->add(Dog{ breed, name, age, photo });
		if (response[0] != "Dog added with success." &&
			response[0] != "Dog already in the list. Cannot add.") {
			cout << ">>> Incorrect dog. Cannot add. <<< \n";
		}
		printResponse(response);

		cout << "\n";
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
		response = this->ctrl->remove(Dog{ breed, name, 0, "http" });
		if (response[0] != "Dog removed with success." &&
			response[0] != "Dog not in the list. Cannot remove.") {
			cout << ">>> Incorrect dog. Cannot remove. <<< \n";
		}
		printResponse(response);

		cout << "\n";
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
		response = this->ctrl->remove(Dog{ breed, name, age, photo});
		if (response[0] != "Dog updated with success." &&
			response[0] != "Dog not in the list. Cannot update." ) {
			cout << ">>> Incorrect dog. Cannot update. <<< \n";
		}
		printResponse(response);

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
		vector<Dog> dogs = this->ctrl->getRepo()->getDogs();
		browseDogsMenu(dogs);
		cout << "\n";
		return 0;
	}
	else if (cmd == "fil") {
		string breed;
		int age;

		cout << "breed = ";
		getline(cin, breed);
		cin.ignore();
		cout << "<<" << breed << "\n";

		cout << "age = ";
		age = readNumber();
		if (age == -1) {
			return 0;
		}
		cout << "\n";

		vector<Dog> result = this->ctrl->filter(breed, age);
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
		if (this->ctrl->getAdopted().size() == 0) {
			cout << "\nNo adoption yet.";
		}
		browseDogsMenu(this->ctrl->getAdopted());
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

void UI::browseDogsMenu(vector<Dog> dogs) {
	
	
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

void readFromFile(string fname, Controller* ctrl) {
	ifstream fin;
	string b, n, p, sep;
	int a;
	
	fin.open(fname, std::fstream::in);

	while (!fin.eof()) {
		fin >> b >> sep >> n >> sep >> a >> sep >> p;
		ctrl->add(Dog{ b,n,a,p });
		/*cout << b << " " << n << " " << a << " " << p << "\n";*/
	}

	fin.close();
}

void writeToFile(string fname, Controller* ctrl) {
	ofstream fout;
	fout.open(fname);
	for (auto i : ctrl->getRepo()->getDogs()) {
		fout << i << "\n";
	}
	fout.close();
}

void UI::mainMenu() {
	string cmd, fname = "dogs.txt";

	readFromFile(fname, this->ctrl);
	
	do { 
		menuCommands();
		cmd = readCmd();
	} while (!mainExecute(cmd));

	writeToFile(fname, this->ctrl);
}

