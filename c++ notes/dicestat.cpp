#include <iostream>
#include <limits>
#include <string>

using namespace std;

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

int main() {
	srand(static_cast<unsigned>(time(nullptr)));

	short number_of_dice, number_of_sides, random, minimum, maximum;
	double average;

	cout << "\n What is your dice roll? ";
	
	if( isdigit(cin.peek())) {
		cin >> number_of_dice;
		cin.ignore();
		if( isdigit(cin.peek())) {
			cin >> number_of_sides;
			cin.ignore(INF_FLAG, '\n');
		}
	}
	else {
		number_of_dice = 1;
		cin.ignore();
		if( isdigit(cin.peek())) {
			cin >> number_of_sides;
			cin.ignore(INF_FLAG, '\n');
		}
	}

	cout << "\n Thank you!! Calculating... Done.\n";
	
	minimum = number_of_dice;
	maximum = number_of_dice * number_of_sides;
	average = (minimum + maximum)/2.0;
	
	cout << "\n When rolling " << number_of_dice << " size-" << number_of_sides 
	<< " dice, your statistics will be: ";
	cout << "\n\t Minimum: " << minimum << "\n";
	cout << "\n\t Average: " << average << "\n";
	cout << "\n\t Maximum: " << maximum << "\n";
	
	random = static_cast<short>(rand() % (maximum - minimum + 1) + minimum);
	
	cout << "\n A typical dice roll might result in " << random << ".\n";
	
	cout << "\n Thank you for using the DSP!!\n";
	cout << "\n Have a good day!\n";
	
}

