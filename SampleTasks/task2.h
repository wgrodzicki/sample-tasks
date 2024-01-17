#pragma once
#include <string>

void Task2();

class Car
{
public:

	// Costructors
	Car();
	Car(std::string, int, int);
	Car(const Car&);

	// Operators
	bool operator==(Car);
	bool operator<(Car);
	bool operator>(Car);
	Car operator+(Car);
	Car operator+=(Car);

	// Methods
	std::string GetBrand();
	int GetMileage();
	int GetValue();
	void SetBrand();
	void SetMileage();
	void SetValue();
	void DecreaseMileage();

private:

	// Attributes
	std::string brand;
	int mileage;
	int value;
};