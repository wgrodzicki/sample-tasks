#include "task1.h"
#include "task2.h"
#include "task3.h"
#include <iostream>
using namespace std;

#define _CRTDBG_MAP_ALLOC

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
			Task2();
			break;
		case 3:
			Task3();
			break;
		case 4:
			Task3(true);
			break;
		default:
			break;
	}
	
	// Report any memory leaks
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

	return 0;
}