#include <iostream>
#include "UI.h"
<<<<<<< HEAD
=======
#include "Test.h"
>>>>>>> develop

using namespace std;

class App {
private:
	UI* ui;
public:
	App() {
		this->ui = new UI();
	}
	~App() {
		delete this->ui;
	}
	void run() {
		ui->mainMenu();
	}
};
<<<<<<< HEAD

int main() {
=======

int main() {
	Test t;
	t.testAll();

>>>>>>> develop
	App app;
	app.run();

	system("pause");
	return 0;
}
