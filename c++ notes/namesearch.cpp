#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "strextra.h"

using namespace std;

string getPositionSuffix(short position) {
    if (position % 10 == 1 && position != 11)
        return "st";
    else if (position % 10 == 2 && position != 12)
        return "nd";
    else if (position % 10 == 3 && position != 13)
        return "rd";
    else
        return "th";
}

void searchNameInFile(const string& filename, const string& name) {
    ifstream file(filename);
    string line;
    short lineNumber = 0;
    bool found = false;
	
    if (file.is_open()) {
		file >> std::ws;
        while (getline(file, line)) {
            lineNumber++;
			line.erase(line.length()-1);

            if (strcmp_ncase(name.c_str(), line.c_str()) == 0) {
                found = true;
                cout << "\n'" << name << "' is the " << lineNumber 
				<< getPositionSuffix(lineNumber) << " name in the file! " 
				<< endl;
                break; 
            }
        }
        file.close();
        file.clear();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }

    if (!found) {
        cout << "Name '" << name << "' not found in the file." << endl;
    }
}

bool fileExists(const string& filename) {
	ifstream file(filename);
	return file.good();
}

int main() {
	ifstream data_file;
    string fileName, name;
    bool continueSearching = true;
	
	// ask user for filename
    cout << "\t\t\tWelcome to the Name Searching Program!!!!\n";
    cout << "Please enter the name of your names file: ";
    getline(cin, fileName);

    data_file.open(fileName);
    // validate file exists
    while (!data_file) {
        data_file.close();
        data_file.clear();
        cout << "I'm sorry, I could not open '" << fileName <<
                "' Please enter another name: ";
        getline(cin, fileName);
        data_file.open(fileName);
    }
    while (continueSearching) {
        cout << "\nEnter the name to search for: ";
        getline(cin, name);

        searchNameInFile(fileName, name);

        char choice;
      cout << "\nDo you want to search another name in the same file? (y/n): ";
        cin >> choice;
        cin.ignore(); // to clear the input buffer
        if (choice != 'y' && choice != 'Y') {
            continueSearching = false;
        }
    }
	
	cout << "\nThank you for using the NSP!!\n";
	cout << "\nEndeavor to have an amazing day\n";

    return 0;
}