#include <iostream>
#include "UI.h"

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

int main() {
	App app;
	app.run();

	system("pause");
	return 0;
}
