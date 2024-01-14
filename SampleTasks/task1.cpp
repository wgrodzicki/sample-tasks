#include <iostream>
using namespace std;


/// <summary>
/// Shuffles an array of the given size and puts the results in the other array
/// </summary>
/// <param name="we"></param>
/// <param name="count"></param>
/// <param name="wy"></param>
void Shuffle(int* we, int count, int* wy)
{
	int afterBreakpoint = 1;

	for (int i = 0; i < count; i++)
	{
		if (i * 2 <= count - 1)
		{
			wy[i * 2] = we[i];
		}
		else
		{
			wy[afterBreakpoint] = we[i];
			afterBreakpoint += 2;
		}
	}
}


/// <summary>
/// Handles shuffling of an arbitrarily sized array
/// </summary>
void Task1()
{
	int size = 0;
	cout << "Array size: ";
	cin >> size;

	int* we = new int[size];
	int* wy = new int[size];

	// Make sure allocation succeeded
	if (we == NULL || wy == NULL)
	{
		cout << "Memory allocation failed";
		return;
	}
	
	// Ask user to populate the we array
	for (int i = 0; i < size; i++)
	{
		int element = 0;
		cout << "Element " << i << " value: ";
		cin >> element;
		we[i] = element;
	}

	Shuffle(we, size, wy);
	
	// Print shuffle results
	for (int i = 0; i < size; i++)
	{
		cout << "Element " << i << "\t" << "we: " << we[i] << "\twy: " << wy[i] << endl;
	}

	// Free memory
	delete[] we;
	delete[] wy;

	// Reset pointers
	we = NULL;
	wy = NULL;
}