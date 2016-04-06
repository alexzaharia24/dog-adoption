#pragma once
#include "Controller.h"

class UI {
private:
	Controller* ctrl;
public:
	/* CONSTRUCTORS */
	UI();
	~UI();

	/* MENU */
	void mainMenu();
	int mainExecute(string cmd);
	void browseDogsMenu();
	int adminExecute(string cmd);
	void adminMenu();
	int userExecute(string cmd);
	void userMenu();

	/* OPERATIONS */
	void printShelterDogs();
	void printAdoptedDogs();



};