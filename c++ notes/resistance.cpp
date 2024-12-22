#include <iostream> 
#include <string>

using namespace std;

int main(void)
{
	// variables
	double x;
	double y;
	
	double resist1;
	double resist2;
	
	// string var to catch bad user input
	string garbage;
	
	// print welcome statements
	cout << "\n\t\tWelcome to the Resistor Calculation Program!!!\n\n";
	
	// get user input
	cout << "\nPlease enter your first resistance: ";
	cin >> x >> garbage;
	
	cout << "\nPlease enter your second resistance: ";
	cin >> y >> garbage;
	
	cout << "\nThank you!! You've entered " << x << " ohms and " << y << " ohms! Calculating...\n";
	cout << "\nDone.\n"; 
	
	// calculations for series and parallel resistance
	resist1 = x + y;
	resist2 = (x*y)/(x+y);

	// ending statements 
	cout << "\nIf your resistors are placed in a series, they'll total to " << resist1 << " ohms.\n";
	cout << "\nIf they are placed in parallel, they'll total to " << resist2 << " ohms.\n";
	cout << "\nThank you for using the RCP!!\n";
	cout << "\nHave a good day.\n";
	
	return 0; 
}