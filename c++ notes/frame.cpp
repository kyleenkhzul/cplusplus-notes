#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <sstream>

using namespace std;

class FramePhrase {
private:
    string phrase;
    char frameChar;

public:
    FramePhrase(const string& inputPhrase, char inputFrameChar) : phrase(inputPhrase), frameChar(inputFrameChar) {}

    vector<string> frame(int width, int longestWordSize, int justification) const {
        vector<string> framedPhrase;
        string border(width, frameChar);

        framedPhrase.push_back(border);

        istringstream iss(phrase);
        string word;
        while (iss >> word) {
            string line;
            if (justification == 1) { // Centered
                ostringstream oss;
                oss << setw(width - 2) << left << word;
                line = "*" + oss.str() + "*";
            } else if (justification == 2) { // Right
                line = "*" + string(width - word.size() - 2, ' ') + word + "*";
            } else { // Left
                line = "*" + word + string(longestWordSize - word.size(), ' ') + "*";
            }
            framedPhrase.push_back(line);
        }

        framedPhrase.push_back(border);
        return framedPhrase;
    }

    friend istream& operator>>(istream& input, FramePhrase& framePhrase) {
        cout << "Enter frame character: ";
        input >> framePhrase.frameChar;
        cout << "Enter frame width: ";
        int width;
        input >> width;
        cout << "Choose justification (0: left, 1: centered, 2: right): ";
        int justification;
        input >> justification;

        cout << "Enter phrase: ";
        input.ignore();
        getline(input, framePhrase.phrase);
        return input;
    }

    friend ostream& operator<<(ostream& output, const FramePhrase& framePhrase) {
        output << "Frame character: " << framePhrase.frameChar << endl;
        output << "Phrase: " << framePhrase.phrase << endl;

        istringstream iss(framePhrase.phrase);
        string word;
        int longestWordSize = 0;
        while (iss >> word) {
            longestWordSize = max(longestWordSize, static_cast<int>(word.size()));
        }

        int justification = 1; // Default to centered
        vector<string> framed;
        if (justification == 1) {
            framed = framePhrase.frame(2 * longestWordSize + 3, longestWordSize, justification);
        } else {
            framed = framePhrase.frame(2 * longestWordSize + 3, longestWordSize, 0); // Left justify for now
        }
        
        for (const auto& line : framed) {
            output << line << endl;
        }
        return output;
    }
};

int main() {
    char choice;
    cout << "Read phrases from keyboard (k) or file (f)? ";
    cin >> choice;

    if (choice == 'k') {
        FramePhrase phrase("", '*');
        cin >> phrase;

        cout << "Print to screen (s) or file (f)? ";
        cin >> choice;

        if (choice == 's') {
            cout << phrase << endl;
        } else if (choice == 'f') {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            ofstream outFile(filename);
            if (outFile.is_open()) {
                outFile << phrase << endl;
                outFile.close();
                cout << "Phrase written to " << filename << endl;
            } else {
                cerr << "Unable to open file " << filename << endl;
            }
        } else {
            cerr << "Invalid choice!" << endl;
            return 1;
        }
    } else if (choice == 'f') {
        string filename;
        cout << "Enter filename: ";
        cin >> filename;
        ifstream inFile(filename);
        if (inFile.is_open()) {
            FramePhrase phrase("", '*');
            inFile >> phrase;

            cout << "Print to screen (s) or file (f)? ";
            cin >> choice;

            if (choice == 's') {
                cout << phrase << endl;
            } else if (choice == 'f') {
                string outFilename;
                cout << "Enter output filename: ";
                cin >> outFilename;
                ofstream outFile(outFilename);
                if (outFile.is_open()) {
                    outFile << phrase << endl;
                    outFile.close();
                    cout << "Phrase written to " << outFilename << endl;
                } else {
                    cerr << "Unable to open file " << outFilename << endl;
                }
            } else {
                cerr << "Invalid choice!" << endl;
                return 1;
            }
        } else {
            cerr << "Unable to open file " << filename << endl;
            return 1;
        }
    } else {
        cerr << "Invalid choice!" << endl;
        return 1;
    }

    return 0;
}
