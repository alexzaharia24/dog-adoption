#include <iostream>

#include "DynVec.h"
#include "Dog.h"

using namespace std;

int main() {
	DynVec<int> a;
	Dog d("Husky", "Sven", 4, "url");
	cout << d << endl;
	a.add(2);
	cout << a.toString();


	system("pause");
	return 0;
}
