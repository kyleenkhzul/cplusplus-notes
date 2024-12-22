#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int ounces;
	int pounds;
	int remainder;
	double actual; 
	
	cout << "\n\t\tWelcome to the Ounce Conversion Program!!!\n\n";
	
	cout << "\nHow many ounces do you have? ";
	cin >> ounces;
	cin.ignore();
	
	pounds = ounces/16;
	remainder = ounces%16;
	actual = ounces/16.0;
	
	cout << "\nThank you!! Calculating... Done.\n";
	cout << "\n" << ounces << " oz. is equivalent to " << pounds << " lbs. and " << remainder << " oz. (" << actual << " lbs.).\n";
	
	cout << "\nThank you for using the OCP!!\n";
	cout << "\nHave a good day!\n";
}