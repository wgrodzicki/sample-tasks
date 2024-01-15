#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#define _CRTDBG_MAP_ALLOC
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
			Task3();
			break;
		case 4:
			//Task4();
			break;
		default:
			break;
	}
	
	// Report any memory leaks
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

	return 0;
}