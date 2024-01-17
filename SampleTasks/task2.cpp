#include "task2.h"
#include <string>
#include <iostream>
using namespace std;

Car::Car()
{
	brand = "No brand";
	mileage = 0;
	value = 0;
}

Car::Car(std::string inputBrand, int inputMileage, int inputValue)
{
	brand = inputBrand;
	mileage = inputMileage;
	value = inputValue;
}

Car::Car(const Car& car)
{
	brand = car.brand;
	mileage = car.mileage;
	value = car.value;
}

bool Car::operator==(Car anotherCar)
{
	bool result = false;

	if (brand != anotherCar.brand)
	{
		return false;
	}

	if (mileage == anotherCar.mileage)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Car::operator<(Car anotherCar)
{
	bool result = false;
	
	if (brand != anotherCar.brand)
	{
		return false;
	}

	if (mileage < anotherCar.mileage)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Car::operator>(Car anotherCar)
{
	bool result = false;

	if (brand != anotherCar.brand)
	{
		return false;
	}

	if (mileage > anotherCar.mileage)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Car Car::operator+(Car anotherCar)
{
	Car resultingCar;

	string resultingBrand = "";
	int resultingValue = 0;
	int resultingMileage = 0;

	// Determine brand
	resultingBrand = value > anotherCar.value ? brand : anotherCar.brand;

	// Determine value
	double averageValue = ((double)value + (double)anotherCar.value) / 2;
	resultingValue = averageValue + 20;

	// Determine mileage
	resultingMileage = mileage < anotherCar.mileage ? mileage : anotherCar.mileage;

	resultingCar.brand = resultingBrand;
	resultingCar.value = resultingValue;
	resultingCar.mileage = resultingMileage;

	return resultingCar;
}

Car Car::operator+=(Car anotherCar)
{
	if (value > anotherCar.value)
	{
		cout << "Cannot enrich car. Its value (" << value << ") is already higher than the value of the other car";
		cout << " (" << anotherCar.value << ")." << endl;
		cout << endl;
		return *this;
	}
	else
	{
		value += 10000;
		return *this;
	}
}

/// <summary>
/// Returns the brand of the car
/// </summary>
/// <returns></returns>
string Car::GetBrand()
{
	return brand;
}

/// <summary>
/// Returns the mileage of the car
/// </summary>
/// <returns></returns>
int Car::GetMileage()
{
	return mileage;
}

/// <summary>
/// Returns the value of the car
/// </summary>
/// <returns></returns>
int Car::GetValue()
{
	return value;
}

/// <summary>
/// Changes the brand of the car
/// </summary>
void Car::SetBrand()
{
	string carBrand = "";
	cout << "Car brand: ";
	cin >> carBrand;
	brand = carBrand;
}

/// <summary>
/// Changes the mileage of the car
/// </summary>
void Car::SetMileage()
{
	int carMileage = 0;
	cout << "Car mileage: ";
	cin >> carMileage;
	mileage = carMileage;
}

/// <summary>
/// Changes the value of the car
/// </summary>
void Car::SetValue()
{
	int carValue = 0;
	cout << "Car value: ";
	cin >> carValue;
	value = carValue;
}

/// <summary>
/// Decreases the mileage of the car
/// </summary>
void Car::DecreaseMileage()
{
	int amount = 0;
	cout << "Decrease mileage by: ";
	cin >> amount;

	if (amount <= mileage)
	{
		mileage -= amount;
	}
	else
	{
		cout << "Error: mileage cannot be less than 0." << endl;
	}
}

/// <summary>
/// Prints the stats of the car
/// </summary>
/// <param name="car"></param>
void PrintCar(Car car)
{
	cout << endl;
	cout << "Car's brand: " << car.GetBrand() << endl;
	cout << "Car's mileage: " << car.GetMileage() << endl;
	cout << "Car's value: " << car.GetValue() << endl;
	cout << endl;
}

/// <summary>
/// Compares mileages between 2 cars
/// </summary>
/// <param name="car1"></param>
/// <param name="car2"></param>
void CompareMileages(Car car1, Car car2)
{
	if (car1 < car2)
	{
		cout << "Mileage of car 1 (" << car1.GetBrand() << ", mileage: " << car1.GetMileage() << ") is less than the mileage of car 2 ";
		cout << "(" << car2.GetBrand() << ", mileage: " << car2.GetMileage() << ")." << endl;
	}
	else if (car1 > car2)
	{
		cout << "Mileage of car 1 (" << car1.GetBrand() << ", mileage: " << car1.GetMileage() << ") is greater than the mileage of car 2 ";
		cout << "(" << car2.GetBrand() << ", mileage: " << car2.GetMileage() << ")." << endl;
	}
	else if (car1 == car2)
	{
		cout << "Mileage of car 1 (" << car1.GetBrand() << ", mileage: " << car1.GetMileage() << ") is equal to the mileage of car 2 ";
		cout << "(" << car2.GetBrand() << ", mileage: " << car2.GetMileage() << ")." << endl;
	}
	else
	{
		cout << "Cannot compare cars of different brands." << endl;
	}
	cout << endl;
}

/// <summary>
/// Demonstrates the functioning of the Car class
/// </summary>
void Task2()
{
	// Initializing an instance of the Car class
	cout << "Creating car 1..." << endl;

	Car car1 = Car();

	PrintCar(car1);

	// Methods to set attributes
	cout << "Car 1 stats" << endl;

	car1.SetBrand();
	car1.SetMileage();
	car1.SetValue();

	PrintCar(car1);

	// Method to decrease mileage
	car1.DecreaseMileage();

	cout << endl << "Decreased mileage: " << car1.GetMileage() << endl;
	cout << endl;

	// Copy contructor
	cout << "Creating car 2 based on car 1..." << endl;
	cout << endl;

	Car car2 = Car(car1);

	cout << "Car 1: ";
	PrintCar(car1);

	cout << "Car 2: ";
	PrintCar(car2);

	cout << "Changing car 2..." << endl;
	cout << endl;

	cout << "Car 2 stats" << endl;
	car2.SetBrand();
	car2.SetMileage();
	car2.SetValue();

	PrintCar(car2);

	// Comparison operators (<, >, ==)
	cout << "Comparing mileages between car 1 and car 2..." << endl;
	cout << endl;

	CompareMileages(car1, car2);
	
	// Addition operator (+)
	cout << "Merging car 1 and car 2..." << endl;
	cout << endl;

	cout << "Car 1: ";
	PrintCar(car1);
	cout << "Car 2: ";
	PrintCar(car2);

	Car mergedCar = car1 + car2;

	cout << "Merged car";
	PrintCar(mergedCar);

	// Addition assignment operator (+=)
	cout << "Enriching car 1 with car 2..." << endl;
	cout << endl;

	cout << "Car 1: ";
	PrintCar(car1);

	cout << "Car 2: ";
	PrintCar(car2);

	car1 += car2;

	cout << "Enriched car";
	PrintCar(car1);
}