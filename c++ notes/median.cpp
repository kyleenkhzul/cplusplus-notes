#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function to find the median of a set of data
double findMedian(vector<double>& data) {
    size_t numItems = data.size();
    // Bubble sort the data
    for (size_t i = 0; i < numItems - 1; ++i) {
        for (size_t j = 0; j < numItems - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                // Swap data[j] and data[j+1]
                double temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    // Calculate the median
    if (numItems % 2 == 0) {
        return (data[numItems / 2 - 1] + data[numItems / 2]) / 2.0;
    } else {
        return data[numItems / 2];
    }
}

int main() {
    char choice;
    do {
        // Open the file
        ifstream file;
        string filename;
        cout << "Enter filename: ";
        cin >> filename;
        file.open(filename); 
        if (!file) {
            cerr << "Error: Unable to open file!" << endl;
            continue; // Skip to the next iteration of the loop
        }

        // Read data from the file
        vector<double> data;
        double value;
        while (file >> value) {
            data.push_back(value);
        }

        // Close the file
        file.close();

        // Find the median
        double median = findMedian(data);

        // Print the median
        cout << "Median: " << median << endl;

        // Ask user if they want to repeat
        cout << "Do you want to calculate median with another file? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}