#include <iostream>
#include <ctime>
#include "TBoolMatrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	TBoolMatrixAnalizer obj;
	obj.ShowAll();
	cout << "\nМатрица с наибольшим количеством единиц:\n" << obj.SearchMaxTrue() << "\n\n";
	system("pause");
	return 0;
}