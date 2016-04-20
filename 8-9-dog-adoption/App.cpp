#include <iostream>
#include <algorithm>
#include "UI.h"
#include "Test.h"

using namespace std;

class App {
private:
	UI* ui;
public:
	App(string export_type) {
		this->ui = new UI(export_type);
	}
	~App() {
		delete this->ui;
	}
	
	void run() {
		
		ui->mainMenu();
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

	App app(export_type);
	app.run();

	system("pause");
	return 0;
}
