#include <iostream>
#include <string>
#include "month.h"

using namespace std;
				
		Month::Month(void) 
			: monthNumber(1) { }
		
		Month::Month(string monthInput) 
			: monthNumber(getMonthNumberFromName(monthInput)) { }
		
		
		Month::Month(unsigned short monthInput) 
			: monthNumber(monthInput)		{ }
		
		Month::Month(const Month & m) 
			: monthNumber(m.monthNumber) { }
		
		const string monthNames[] = {
			"January", "February", "March", "April", "May", "June", "July", 
			"August", "September", "October", "November", "December" };
			
		unsigned short Month::get_month(void) {
			return monthNumber;
		}
		
		void Month::set_month(string monthInput) {
			monthNumber = getMonthNumberFromName(monthInput);
		}
		
		void Month::set_month(unsigned short monthInput) {
			monthNumber = monthInput;
		}
		
		void Month::output(void) {
			cout << "Month: " << monthNames[monthNumber - 1] << " (" << 
			monthNumber << ")\n";
		}

		void Month::input(void) {
			string userInput;
			cin >> userInput;
			
			if(userInput.length() < 3 && isdigit(userInput[0])) {
				monthNumber = static_cast<unsigned short>(stoi(userInput));
			}
			else if(userInput.length() >= 3) {
				monthNumber = getMonthNumberFromName(userInput);
			}
			else {
				cerr << "Invalid input. Setting month to January." << endl;
				monthNumber = 1;
			}
		}
		
		inline void Month::advance(unsigned short months) {
			monthNumber += months;
		monthNumber = static_cast<unsigned short>((monthNumber - 1) % 12 + 1);
		}
		
		void Month::before(string monthInput) {
			monthNumber -= getMonthNumberFromName(monthInput);
			if(monthNumber <= 0) {
				monthNumber = 12 + monthNumber;
			}
		}
		inline void Month::before(unsigned short months) {
			monthNumber -= months;
			if(monthNumber <= 0) {
				monthNumber = 12 + monthNumber;
			}
		}
		
		inline bool Month::same(const Month & other) const {
			return monthNumber == other.monthNumber;
		}

int main() {
	Month myMonth;
	
	cout << "Enter the month (number or name or 3-letter abbreviation) ";
	myMonth.input();
	
	myMonth.output();
	
	// After
	short advanceMonths;
	cout << "Enter the number of months to advance: ";
	cin >> advanceMonths;
	myMonth.advance(advanceMonths);
	myMonth.output();
	
	// Before
	short beforeMonths;
	cout << "Enter the number of months to go back: ";
	cin >> beforeMonths;
	myMonth.before(beforeMonths);
	myMonth.output();
	
	
	// Same
	Month anotherMonth;
	cout << "Enter the month (number or name or 3-letter abbreviation) ";
	anotherMonth.input();
	
	if(myMonth.same(anotherMonth)) {
		cout << "Both months are the same." << endl;
	}
	else {
		cout << "The months are different." << endl;
	}
	
	return 0;
}