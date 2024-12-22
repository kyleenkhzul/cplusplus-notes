#include <iostream>
#include <limits>

using namespace std;

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

void generateCode() {
    unsigned long random = (static_cast<unsigned long>(rand() % 
        (9999999 - 1000000 + 1000000) + 1000000));
    cout << "\nGood, your wash code is " << random 
            << ". It will be good until noon on Friday\n";
} 

int main() {
    double cost_of_super = 5.00, 
           cost_of_premium = 6.00, 
           cost_of_ultra = 8.00;
    char yes_no, choice, answer;

    srand(static_cast<unsigned>(time(nullptr)));

    cout << "\t\t Welcome to Kyle's Gas'n'Go Car Wash System!!!\t\n";
    cout << "\nWould you like a car wash today? ";
    cin >> yes_no;
    cin.ignore(INF_FLAG, '\n');

    while(toupper(yes_no) != 'N') {
        cout << "\nWhich wash would you like: Super, Premium, or Ultra? ";
        cin >> choice;
        cin.ignore(INF_FLAG, '\n');
        
        choice = static_cast<char>(toupper(choice));
        
        switch(choice) {
            case 'S':
                cout.setf(ios_base::fixed);
                cout.precision(2);
                cout.width(7);
                cout << "\nThat will be $" << cost_of_super 
                << ", is that okay? ";
                cin >> answer;
                cin.ignore(INF_FLAG, '\n');
                if(toupper(answer) != 'N') {
                    generateCode();
                    yes_no = 'N';
                }
                else {
                    cout << "\nI'm sorry...\n";
                    cout << "\n\nWould you like a car wash today? ";
                    cin >> yes_no;
                    cin.ignore(INF_FLAG, '\n');
                }
                break;
            case 'P':
                cout.setf(ios_base::fixed);
                cout.precision(2);
                cout.width(7);
                cout << "\nThat will be $" << cost_of_premium 
                << ", is that okay? ";
                cin >> answer;
                cin.ignore(INF_FLAG, '\n');
                if(toupper(answer) != 'N') {
                    generateCode();
                    yes_no = 'N';
                }
                else {
                    cout << "\nI'm sorry...\n";
                    cout << "\n\nWould you like a car wash today? ";
                    cin >> yes_no;
                    cin.ignore(INF_FLAG, '\n');
                }
                break;
            case 'U':
                cout.setf(ios_base::fixed);
                cout.precision(2);
                cout.width(7);
                cout << "\nThat will be $" << cost_of_ultra 
                << ", is that okay? ";
                cin >> answer;
                cin.ignore(INF_FLAG, '\n');
                if(toupper(answer) != 'N') {
                    generateCode();
                    yes_no = 'N';
                }
                else {
                    cout << "\nI'm sorry...\n";
                    cout << "\n\nWould you like a car wash today? ";
                    cin >> yes_no;
                    cin.ignore(INF_FLAG, '\n');
                }
                break;
            default:
                cout << "\nI'm sorry, that choice is invalid! \n";
                cout << "\nPlease try to read/type more carefully ";
                cout << "next time\n";
        }
    }
    cout << "\nThank you for using the KGnGCWS!! \n";
    cout << "\nHave a good day! \n";
}