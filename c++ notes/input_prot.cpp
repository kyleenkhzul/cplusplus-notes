#include <iostream> 
#include <string> 

#include "input_prot.h"

using namespace std;

int main(void) { 
	// Testing getBounds function
	short num1, num2;
	
	cout << "\nWhat are your lower and upper bounds? ";
	cin >> num1 >> num2;

	input_protect(num1, num2, "\nWhat is your lower bound? ", 
	"\nWhat is your upper bound? ", "\nPlease enter a correct bound! ");
	
	
	// Testing getLowerBound function
	double num3, num4;
	cout << "\nWhat is your old and new lower bound? ";
	cin >> num3 >> num4;
	
	getLowerBound(num3, num4, "What is your new lower bound? ", 
		"Enter a new lower bound that is less than your old lower bound! \n");
		
		
	// Testing getUpperBound function
	long num5, num6;
	cout << "\nWhat is your old and new upper bound? ";
	cin >> num5 >> num6;
	
	getUpperBound(num5, num6, "What is your new upper bound? ", 
		"Enter a new upper bound that is greater than your old upper bound! \n");
		
	// Testing choices function
	
	char ans;
	cout << "\nWould you like to continue? ";
	cin >> ans;
	
	input_protect(ans, "Would you like to continue? ", "\nPlease enter Y or N only! \n",
		{'Y', 'N', 'n', 'y'});
	
	return 0;
}