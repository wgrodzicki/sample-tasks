#include "task1.h"
#include <iostream>
using namespace std;

int main()
{
	int task = 0;
	cout << "Choose task: ";
	cin >> task;

	switch (task)
	{
		case 1:
			Task1();
			break;
		case 2:
			//Task2();
			break;
		case 3:
			//Task3();
			break;
		case 4:
			//Task4();
			break;
		default:
			break;
	}

	return 0;
}