#include <iostream>
#include <string>

using namespace std; 

bool isPalindrome(string str) {
	for(short i = 0; i < static_cast<short>(str.length())/2; i++) {
	  if(tolower(str[i]) != tolower(str[static_cast<short>(str.length())-1-i]))
		{
			return false;
		}
	}
	return true;
}

int main() {
	string input;
	
	cout << "Enter any text: ";
	cin >> input;
	if(isPalindrome(input)) {
		cout << "The text you input is a palindrome.\n";
	}
	else{
		cout << "The text you input is not a palindrome.\n";
	}
}

