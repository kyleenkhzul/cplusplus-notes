#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>

using namespace std;
constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

bool isVowel(char c);
bool hasNumber(const string & str);

string ConvertToPigLatin(const string & word);
string concatenateWords(const vector<string> & convertedWords);

vector<string> adjustText(const string & normalText, size_t width);
vector<string> convertTextToPigLatin(const vector<string> & normalWords);
vector<string> parsedWords(const string & paragraph);

int main() 
{
    char y_n;

    vector<string> normalWords;
    vector<string> convertedWords;
	
	string normalText;
    string convertedText;
    
    cout << "\n\t Welcome to the Pig Latin Translation Program!!! \n" ;
    
    while( tolower(y_n) != 'n'){
        cout << "\n\t\tWhat text do you want converted to Pig Latin?\n\n";
        cin >> normalText;
		
		normalWords = parsedWords(normalText);
		convertedWords = convertTextToPigLatin(normalWords);
		convertedText = concatenateWords(convertedWords);
        
        cout << "\nThis is what the normal input looks like: "
             << concatenateWords(adjustText(normalText, 55));
             
        cout << "\nThis is what the translated input looks like: "
             << concatenateWords(adjustText(convertedText, 55));

        cout << "\nWould you like to translate more? \n\n";
        
        cin >> y_n;
        cin.ignore(INF_FLAG, '\n');
    }
    
     cout << "\nThank you for using the PLTP!!\n\n Have a good day! BYE !\n\n";
}

/*
    This method is intended to take the individual words and put them back 
	together to form a paragraph after the vector of strings has been 
	translated into PigLatin. 
    @return vector of strings of concatenated words
*/ 

string concatenateWords(const vector<string> & convertedWords) 
{
    string paragraph;

    if (!convertedWords.empty()) {
        paragraph += convertedWords[0];
        for (size_t i = 1; i < convertedWords.size(); ++i) {
            paragraph += " " + convertedWords[i];
        }
    }

    return paragraph;
}

/*
	This method is intended to check whether or not a char is a vowel
    @return true/false depending on if input char is a vowel
*/ 
bool isVowel(char c) 
{
    char convertChar = static_cast<char>(tolower(c));
    return (convertChar == 'a' || convertChar == 'e' || convertChar == 'i' || 
					convertChar == 'o' || convertChar == 'u');
}

/*
	This method is intended to check whether or not there is a digit located
	within a string by iterating through every element.
    @return true/false depending on if string contains a digit
*/ 
bool hasNumber(const string & str) 
{
    for (char c : str) 
    {
        if (isdigit(c)) 
        {
            return true;  
        }
    }
    return false; 
}

/*
    This method is intended to extract singular words out of a paragraph or
	line and store them into individual elements within a vector. This allows
	manipulation of each word in a paragraph.
    @return vector of strings of individual words
*/ 

vector<string> parsedWords(const string & paragraph) 
{
    vector<string> normalWords;

    size_t initial = 0;
    size_t final = 0;

    while (final < paragraph.size()) {
        while (initial < paragraph.size() && paragraph[initial] == ' ') {
            initial++;
        }
        final = initial;
        while (final < paragraph.size() && paragraph[final] != ' ') {
            final++;
        }
        if (initial < final) {
            normalWords.push_back(paragraph.substr(initial, final - initial));
        }
        initial = final + 1;
    }

    return normalWords;
}

/*
    This method is intended to convert a vector of strings to PigLatin and
	return an updated vector of strings in Pig Latin. 
    @return vector of strings of translated Pig Latin words
*/ 
vector<string> convertTextToPigLatin(const vector<string> & normalWords) 
{
    vector<string> pigLatinWords;
    for (const auto & word : normalWords) 
    {
        pigLatinWords.push_back(ConvertToPigLatin(word));
    }
    return pigLatinWords;
}

/*
    This method is intended to convert a singular word to PigLatin.
    @return translated Pig Latin word
*/ 
string ConvertToPigLatin(const string & word) 
{
    if (word.empty() || hasNumber(word)) 
    {
        return word; 
    }
	
    size_t previousCharPos = word.size() - 1;
    char previousChar = word[previousCharPos];
    bool hasPunctuation = ispunct(previousChar);

    string words = word.substr(0, hasPunctuation ? 
                                        previousCharPos : word.size());

    size_t firstVowelPos = 0;
    if (!isVowel(words[0])) 
    {
        for (size_t i = 1; i < words.size(); ++i) 
        {
            if (isVowel(static_cast<char>(words[i])) || 
               (words[i] == 'y' && i > 0 && 
               !isVowel(words[i - 1]))) 
            {
                firstVowelPos = i;
                break;
            }
        }
    }
    
    for (char & c : words) 
    {
        c = static_cast<char>(tolower(c));
    }
    
    string pigLatinWord;
    if (firstVowelPos == 0) 
    {
        pigLatinWord = words + "yay";
    } 
    else 
    {
        pigLatinWord = words.substr(firstVowelPos) + 
                       words.substr(0, firstVowelPos) + "ay";
    }
    if (isupper(word[0])) 
    {
        pigLatinWord[0] = static_cast<char>(toupper(pigLatinWord[0]));
    }
    if (hasPunctuation) 
    {
        pigLatinWord += previousChar;
    }
    return pigLatinWord;
}

/*
	This method is intended to format the translated normalText for nicer output_iterator
	@return formatted output of translated normalText
*/

vector<string> adjustText(const string & normalText, size_t width) 
{
    vector<string> result;
    string line;
    
    for (char c : normalText) 
    {
        if (c == '\n') 
        {
            result.push_back(line);
            line.clear();
        } 
        else 
        {
            line += c;

            if (line.size() == width) 
            {
                result.push_back(line);
                line.clear();
            }
        }
    }

    if (!line.empty()) 
    {
        result.push_back(line);
    }

    return result;
}

