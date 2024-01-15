#include <cctype>
#include <string>
#include <iostream>
using namespace std;

struct employee
{
	string name;
	string surname;
	char* position;
	double salary;
	char sex;
};

/// <summary>
/// Checks if the given string consists only of alphabetical characters
/// </summary>
/// <param name="targetString"></param>
/// <returns></returns>
bool CheckStringAlpha(string targetString)
{
	for (int i = 0; i < targetString.length(); i++)
	{
		if (!isalpha(targetString[i]))
		{
			return false;
		}
	}
	return true;
}

/// <summary>
/// Checks if the given string consists only of digital characters
/// </summary>
/// <param name="targetString"></param>
/// <returns></returns>
bool CheckStringDigital(string targetString)
{
	int pointCounter = 0;

	for (int i = 0; i < targetString.length(); i++)
	{
		// Must start with a digit
		if (i == 0)
		{
			if (!isdigit(targetString[i]))
			{
				return false;
			}
		}
		
		if (!isdigit(targetString[i]))
		{
			// Allow for a point
			if (targetString[i] == '.')
			{
				pointCounter++;

				// No more than 1 point allowed
				if (pointCounter > 1)
				{
					return false;
				}
				continue;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

/// <summary>
/// Gets and validates user input for the employee's name/surname
/// </summary>
/// <returns></returns>
string GetName(string message)
{
	string name = "";
	bool inputValid = false;

	do
	{
		cout << message << ": ";
		cin >> name;

		inputValid = CheckStringAlpha(name);

	} while (!inputValid);

	return name;
}

/// <summary>
/// Gets and validates user input for the employee's position
/// </summary>
/// <returns></returns>
char* GetPosition()
{
	string input = "";
	bool inputValid = false;

	// Get a valid string
	do
	{
		cout << "Position: ";
		cin >> input;
		inputValid = CheckStringAlpha(input);

	} while (!inputValid);

	// Determine how much space is needed
	const int inputLength = input.length();

	// Allocate memory for the char* equal to the string's length
	char* position = new char[inputLength + 1];

	// Convert string to char*
	/* c_str()
	   "Returns a pointer to an array that contains a null-terminated sequence of characters
	   (i.e., a C-string) representing the current value of the string object."
	   (https://cplusplus.com/reference/string/string/c_str/)
	*/
	strcpy_s(position, inputLength + 1, input.c_str());

	return position;
}

/// <summary>
/// Gets and validates user input for the employee's salary
/// </summary>
/// <returns></returns>
double GetSalary()
{
	string input = "";
	bool inputValid = false;
	double salary = 0;

	do
	{
		cout << "Salary: ";
		cin >> input;
		
		// Validate the string input
		inputValid = CheckStringDigital(input);

		if (inputValid)
		{
			// Convert input to a double
			salary = stod(input);

			if (salary <= 0)
			{
				inputValid = false;
			}
		}

	} while (!inputValid);

	return salary;
}

/// <summary>
/// Gets and validates user input for the employee's sex
/// </summary>
/// <returns></returns>
char GetSex()
{
	char sex = NULL;
	bool inputValid = false;

	do
	{
		cout << "Sex: ";
		cin >> sex;

		// F = female, M = male
		if (sex == 'F' || sex == 'M')
		{
			inputValid = true;
		}

	} while (!inputValid);

	return sex;
}

/// <summary>
/// Populates the given array of employees with user input
/// </summary>
/// <param name="n"></param>
/// <param name="employees"></param>
void PopulateStructArray(int n, employee* employees)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Employee " << i + 1 << endl;

		// Name
		employees[i].name = GetName("Name");

		// Surname
		employees[i].surname = GetName("Surname");

		// Position
		char* position = GetPosition();
		employees[i].position = position;

		// Salary
		employees[i].salary = GetSalary();

		// Sex
		employees[i].sex = GetSex();
	}
}

/// <summary>
/// Handles population of an employee array and prints its content
/// </summary>
void Task3()
{
	// Get array size
	int n = 0;
	cout << "Number of employees: ";
	cin >> n;

	employee* employees = new employee[n];

	// Make sure allocation succeeded
	if (employees == NULL)
	{
		cout << "Memory error";
		return;
	}

	PopulateStructArray(n, employees);

	// Print all employees
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Employee " << i + 1 << endl;
		cout << "Name: " << employees[i].name << endl;
		cout << "Surname: " << employees[i].surname << endl;
		cout << "Position: " << employees[i].position << endl;
		cout << "Salary: " << employees[i].salary << endl;
		cout << "Sex: " << employees[i].sex;
		cout << endl;

		// Free memory
		delete[] employees[i].position;

		// Reset pointer
		employees[i].position = NULL;
	}

	// Free memory
	delete[] employees;
	
	// Reset pointer
	employees = NULL;
}