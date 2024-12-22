#ifndef FLESCH_H_INC
#define FLESCH_H_INC

#include <string>

class Flesch{
public:
    FleschIndexCalculator() = default; // Default constructor
    ~FleschIndexCalculator() = default; // Default destructor

    double calculateFleschIndex(const std::string& text) {
        int totalWords = 0;
        int totalSentences = 0;
        int totalSyllables = 0;
        
        bool inWord = false;
        bool prevCharWasVowel = false;
        
        for (char c : text) {
            if (std::isalpha(c)) {
                if (!inWord) {
                    inWord = true;
                    totalWords++;
                }
                if (std::tolower(c) == 'a' || std::tolower(c) == 'e' || std::tolower(c) == 'i' ||
                    std::tolower(c) == 'o' || std::tolower(c) == 'u' || std::tolower(c) == 'y') {
                    if (!prevCharWasVowel) {
                        totalSyllables++;
                        prevCharWasVowel = true;
                    }
                } else {
                    prevCharWasVowel = false;
                }
            } else if (std::ispunct(c) && c != '.') {
                totalSentences++;
                inWord = false;
            } else if (c == '.') {
                totalSentences++;
                inWord = false;
            }
        }
        
        if (totalWords == 0) {
            return 0.0; // Prevent division by zero
        }
        
        double alpha = static_cast<double>(totalSyllables) / totalWords;
        double beta = static_cast<double>(totalWords) / totalSentences;
        
        return 206.835 - (alpha * 84.6) - (beta * 1.015);
    }

private:
    int countSyllables(const std::string& word) {
        int count = 0;
        bool prevCharWasVowel = false;
        
        for (char c : word) {
            if (std::tolower(c) == 'a' || std::tolower(c) == 'e' || std::tolower(c) == 'i' ||
                std::tolower(c) == 'o' || std::tolower(c) == 'u' || std::tolower(c) == 'y') {
                if (!prevCharWasVowel) {
                    count++;
                    prevCharWasVowel = true;
                }
            } else {
                prevCharWasVowel = false;
            }
        }
        
        return count;
    }
};

#endif 