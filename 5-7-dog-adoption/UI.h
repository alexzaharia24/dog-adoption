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

	/* OPERATIONS */
	void printDogs();

};