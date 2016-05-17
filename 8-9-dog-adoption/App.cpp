#include <iostream>
#include <algorithm>
#include "UI.h"
#include "CSVAdoptionList.h"
#include "Test.h"

using namespace std;

class App {
private:
	UI ui;
public:
	App(const UI& ui) : ui{ ui } {}
	void run() {
		ui.mainMenu();
	}
};

string chooseExportType() {
	string export_type;
	cout << "CSV or HTML ?\n";
	while (export_type != "CSV" && export_type != "HTML") {
		cin >> export_type;
		transform(export_type.begin(), export_type.end(), export_type.begin(), toupper);
		if (export_type != "CSV" && export_type != "HTML") {
			cout << "Wrong type.\n";
		}
		else {
			break;
		}
	}
	cout << "You chose " << export_type << "\n\n";
	return export_type;
}

int main() {
	Test t;
	t.testAll();

	string export_type;
	export_type = chooseExportType();

	Repository repo;
	FileAdoptionList* adop = new CSVAdoptionList();
	Controller ctrl(repo, adop, export_type);
	UI ui(ctrl);
	App app(ui);
	app.run();

	delete adop;

	system("pause");
	return 0;
}
