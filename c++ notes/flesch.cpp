#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <cctype>

// Function to count the number of syllables in a word
short countSyllables(const std::string& word) {
	short syllableCount = 0;
	bool prevVowel = false;

	for (char c : word) {
		char lowerC = static_cast<char>(std::tolower(c));
		if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' 
		|| lowerC == 'o' || lowerC == 'u' || lowerC == 'y') {
			if (!prevVowel) {
				syllableCount++;
				prevVowel = true;
			}
		} else {
			prevVowel = false;
		}
	}

	// Adjust for words ending in 'e'
	char lastChar = static_cast<char>(std::tolower(word.back()));
	if (lastChar == 'e' && syllableCount > 1)
	syllableCount--;

	return syllableCount;
}
	
	
// Function to calculate the number of sentences in a string
short countSentences(const std::string& text) {
	short count = 0;
	for (char c : text) {
		if (c == '.' || c == '!' || c == '?') {
			count++;
		}
	}
	return count;
}
	
	
// Function to calculate the number of words in a string
short countWords(const std::string& text) {
	std::istringstream iss(text);
	short count = 0;
	std::string word;
	while (iss >> word) {
		count++;
	}
	return count;
}


// Function to calculate the Flesch Index
double calculateFleschIndex(short wordCount, 
	short sentenceCount, short syllableCount) {
		
return 206.835 - 1.015 * (static_cast<double>(wordCount)/sentenceCount) 
		- 84.6 * (static_cast<double>(syllableCount) / wordCount);
}


// Function to calculate the Flesch Index for given text
double calculateComponents(const std::string& text) {
	short wordCount = countWords(text);
	short sentenceCount = countSentences(text);
	short syllableCount = 0;
    
	std::istringstream iss(text);
	std::string word;
	while (iss >> word) {
		syllableCount += countSyllables(word);
	}

 return calculateFleschIndex(wordCount, sentenceCount, syllableCount);
}
	
// Driver program

using namespace std;	

int main(void) {
	
	std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string text;
    std::string line;
    while (std::getline(file, line)) {
        text += line + " ";
    }

    file.close();

    double fleschIndex = calculateComponents(text);
    std::cout << "Flesch Index: " << fleschIndex << std::endl;

    return 0;
}