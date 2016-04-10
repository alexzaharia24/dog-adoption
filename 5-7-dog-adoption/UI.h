#pragma once
#include "Controller.h"

class UI {
private:
	Controller* ctrl;
public:
	/* CONSTRUCTORS */
	UI();
<<<<<<< HEAD
	~UI();

	/* MENU */
	void mainMenu();

	/* OPERATIONS */
	void printDogs();
=======
	/* Constructor for the UI */
	~UI();
	/* Destructor for the UI */


	/* MENU */
	void mainMenu();
	/* Main menu for the application. From here we initiate the execution.*/
	int mainExecute(string cmd);
	/* Execute the commands of the Main Menu. 
		Input:	cmd (string)	- the command to be executed. 
		Output: 1 - if the user entered "exit"
		0 - otherwise */
	void browseDogsMenu(DynVec<Dog>* dogs);
	/* User browses the list of dogs. Show for each dog the option to adopt, next (to move to the next dog), exit (go back). It will also open a browser window with the photo of the dog. */
	int adminExecute(string cmd);
	/* Execute the commands of the Admin Panel. 
		Input:	cmd (string)	- the command to be executed.
		Output: 1 - if the user entered "exit"
				0 - otherwise */
	void adminMenu();
	/* Admin Panel for the application. From here we call the functions for this panel. */
	int userExecute(string cmd);
	/* Execute the commands of the User Panel.
		Input:	cmd (string)	- the command to be executed. 
		Output: 1 - if the user entered "exit" 
				0 - otherwise */
	void userMenu();
	/* User Panel for the application. From here we call the functions for this panel. */

	/* OPERATIONS */
	void printShelterDogs();
	/* Print the list of dogs that are not adopted, each dog on a line. */
	void printAdoptedDogs();
	/* Print the list of dogs that are adopted, each dog on a line. */



>>>>>>> develop

};