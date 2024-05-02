#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

double calcMPG(double gallons, double miles);

int main()
{
	const double MAX_GALS = 100;
	const double MILES = 500;
	bool valid = true;
	double gallons = 0.0;
	double mpg = 0.0;
	string carMake;


	cout << "Enter the make of the car: ";
	getline(cin, carMake);

	do
	{
		cout << "\nEnter how many gallons of fuel were used: ";
		cin >> gallons;

		if (cin.fail() || gallons <= 0) // Check for invalid input in the form of characters or 0 or negative numbers
		{
			if (cin.fail())
			{
				cout << "\nPlease enter numbers and not characters.\n";
			}
			else
			{
				cout << "\nInvalid input. Please enter a positive number.\n";
			}
			cin.clear(); // clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore input in buffer until newline character
			valid = false; // set flag to false to ensure do while loops again
		}
		else if (gallons > MAX_GALS)
		{
			cout << "\nThat seems like a very high amount. Are you sure? (y/n): ";
			char confirm;
			cin >> confirm;

			if (tolower(confirm) == 'y')
			{
				valid = true;
			}
			else
			{
				valid = false;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		else
		{
			valid = true; // set flag to true to exit loop
		}
	} while (!valid);

	mpg = calcMPG(gallons, MILES);

	cout << fixed << setprecision(2);
	cout << endl << "During the 500 mile drive, the " << carMake << "'s fuel efficiency was " << mpg << " miles per gallon." << endl;

	return 0;
}

double calcMPG(double gallons, double miles)
{
	return miles / gallons;
}