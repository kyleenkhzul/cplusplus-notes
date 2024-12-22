#include <iostream>
#include <limits>
#include <string>

using namespace std;

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

void printWelcome() {
	cout << "\t\n Welcome to the Dice Statistics Program!!! \t\n";
	cout << "\n What is your dice roll? ";
}

void printClosing() {
	cout << "\n Thank you for using the DSP!!\n";
	cout << "\n Have a good day!\n";
}

void printDieRoll(short numDice, short numSide) {
	cout << "\n When rolling " << numDice << "d" << numSide << 
		"(" << numDice << " size-" << numSide 
		<< " dice), your statistics will be: \n";
}

void printResults(short min, short max, double avg) {
	cout << "\n\t Minimum: " << min << "\n";
	cout << "\n\t Average: " << avg << "\n";
	cout << "\n\t Maximum: " << max << "\n";
}

short calculateMax(short numSide, short numDice) {
	short max = numSide * numDice;
	return max;
}

short calculateMin(short numDice) {
	short min = numDice;
	return min;
}

double calculateAvg(short max, short min) {
	return (max+min)/2.0;
}

short generateRand(short max, short min) {
	return static_cast<short>(rand() % (max - min + 1) + min);
}


int main() {
	srand(static_cast<unsigned>(time(nullptr)));
	short number_of_dice, number_of_sides, random, minimum, maximum;
	double average;
	
	printWelcome();
	
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
	
	minimum = calculateMin(number_of_dice);
	maximum = calculateMax(number_of_sides, number_of_dice);
	average = calculateAvg(maximum, minimum);
	
 	printDieRoll(number_of_dice, number_of_sides);

	printResults(minimum, maximum, average);
	
	random = generateRand(maximum, minimum);
	
	cout << "\n A typical dice roll might result in " << random << ".\n";
	
	printClosing();
}

