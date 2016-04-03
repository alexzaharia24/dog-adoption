#include <iostream>

#include "DynVec.h"

using namespace std;

int main() {
	DynVec<int> a;
	cout << a.getCapacity() << endl;

	system("pause");
	return 0;
}
