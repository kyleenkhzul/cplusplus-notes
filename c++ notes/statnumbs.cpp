#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <limits>

// Function to calculate the average of a vector of numbers
double calculateAverage(const std::vector<double>& numbers) {
    double sum = 0.0;
    for (double num : numbers) {
        sum += num;
    }
    return sum / static_cast<double>(numbers.size()); // Explicit cast to double
}

// Function to calculate the variance of a vector of numbers
double calculateVariance(const std::vector<double>& numbers, double average) {
    double variance = 0.0;
    for (double num : numbers) {
        variance += (num - average) * (num - average);
    }
    return variance / static_cast<double>(numbers.size() - 1); // Explicit cast to double
}

// Function to calculate the standard deviation from variance
double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}

int main() {
	
	using namespace std; 
	
    string filename;
    cout << "Enter the name of the file: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open the file.\n";
        return 1;
    }

    vector<double> numbers;
    double number;
    while (file >> number) {
        numbers.push_back(number);
    }

    if (numbers.empty()) {
        cerr << "Error: No numbers found in the file.\n";
        return 1;
    }

    double average = calculateAverage(numbers);
    double variance = calculateVariance(numbers, average);
    double standardDeviation = calculateStandardDeviation(variance);

	// set max and min to -infinity and infinity for reusability
    double max = -numeric_limits<double>::infinity();
    double min = numeric_limits<double>::infinity();
    for (double num : numbers) {
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }

	cout << "Count: " << numbers.size() << endl;
	cout << "Minimum: " << min << endl;
    cout << "Average: " << average << endl;
	cout << "Maximum: " << max << endl;
    cout << "Standard Deviation: " << standardDeviation << endl;



    return 0;
}