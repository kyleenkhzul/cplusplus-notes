#include <iostream> 
#include <string>
#include <limits>

using namespace std;

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

/*
    This method is intended to take a number input and check if it is 
    a valid number. If it is not a valid number, the function reprompts 
    the user until a valid number is passed through. It then stores the 
    valid number into a variable and returns the variable.
    @return newNumber within bounds
*/ 
short checkValidNum(short number) {
    short newNumber;
    while( number > 3999 || number < 1) {
        if(number > 3999) {
            cout << "\nOh I'm sorry, that value is too large for Roman";
            cout << " civilization. \n";
            cout << "\nPlease try again with a number [strictly] smaller";
            cout << " than 4000, thank you. \n";
            cout << "\n Enter your number: ";
        
            cin >> number;
            }
        else {
            cout << "\nOh I'm sorry, that value is too small for Roman";
            cout << " civilization. \n";
            cout << "\nPlease try again with a number [strictly] bigger";
            cout << " than 0, thank you. \n";
            cout << "\n Enter your number: ";
    
            cin >> number;
            }
        }
    newNumber = number;
    return newNumber;
}
/*
    This method simply prints out the display result of the number 
    translated to roman numerals.
    @return void
*/
void displayResult(string roman) {
    cout << "\nAh I believe that would be " << roman << ", right?\n";
}


int main() {
    
    char yes_no;
    string roman;
    short number;
    short temp;
    
    cout << "\n\t\t Welcome to the Roman Numeral Program!!! \n\n";
    
    cout << "Will you converting numbers to Roman form with us today? ";
    
    cin >> yes_no;
    cin.ignore(INF_FLAG, '\n');
    
    while ( toupper(yes_no) != 'N')
    {
        cout << "\nExcellent! Glad to have you along! \n";
        cout << "\nEnter your number: ";
        
        cin >> number;
        
        number = checkValidNum(number);
    
    //thousands 
    if(number >= 1000) {
        temp = (number / 1000);
        
        for(short i = 0; i < temp; i++) {
            roman += 'M';
        }
        number %= 1000;
    }
        
    // hundreds
    if( number >= 100) {
        temp = (number / 100) ;
        
        if(temp == 9) {
            roman += "CM";
        }
        else if ( temp >= 5) {
            roman += 'D';
            
            for(short i = 0; i < temp; i++) {
                roman += 'C';
            }
        }
        else if( temp == 4) {
            roman += "CD";
        }
        else if(temp >= 1) {
            for(short i = 0; i < temp; i++) { 
                roman += 'C';
            }
         }
        number %= 100;
    }
    
    // tens
    if(number >= 10) {
        temp = (number / 10); 
            
        if(temp == 9) {
            roman += "XC";
        }
        else if(temp >= 5) {
            roman += 'L';
            
            for( short i = 0; i < temp; i++) {
                roman += 'X';
            }
        }
        else if(temp == 4) {
            roman += "XL";
        }
        else if (temp >= 1) {
            for(short i = 0; i < temp; i++) {
                roman += 'X';
            }
        }
        number %= 10;
    }
            
    // ones
    if(number >= 1) {
        temp = number;
                
        if(temp == 9) {
            roman += "IX";
        }
        else if (temp >= 5) {
            roman += "V";
        
            for(short i = 0; i < number - 5; i++) {
                roman += 'I';
            }
        }
        else if (temp == 4) {
            roman += "IV";
        }
        else if (temp >= 1) {
        
            for (short i = 0; i < temp; i++) {
                roman += 'I';
            }
        }
    }
    
    
      displayResult(roman);
      
      cout << "\nWould you like to convert another number? ";
      cin >> yes_no;
      cin.ignore(INF_FLAG, '\n');
      roman.clear();
    }
    
    cout << "\nThank you for using the RNP!!\n";
    cout << "\nHave a good day\n";
}