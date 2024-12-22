#include <iostream>
#include <cmath>

using namespace std;

/*
    This method is intended to take the amount of hours between two 
    hour values and convert the difference to minutes.
    @return minutes from hours
*/
short convertHourToMin(short hour1, short hour2) {
    return static_cast<short>((hour2-hour1-1) * 60);
}

/*
    This method is intended to calculate the total amount of minutes
    between two times. It utilizes the helper function, 
    convertHourToMin().
    @return total minutes between two times
*/
short calculateTotalMin(short min1, short min2, short hour1, 
        short hour2) {
    return static_cast<short>(convertHourToMin(hour1, hour2) + 
    abs((60-min1)+min2-1));
}

/*
    This method is intended to calculate the total amount of hours 
    between two times. It utilizes the helper function, 
    calculateTotalMin().
    @return double data type of total hours
*/
double calculateTotalHour(short hour1, short hour2, short min1, 
        short min2) {
    return (calculateTotalMin(min1, min2, hour1, hour2) / 60.0);
 } 

/*
    This method is intended to calculate the total amount of 
    minutes between two values of minutes.
    @return total minutes between two values of minutes. 
*/
short calculateMinBetweenTimes(short min1, short min2){
    return static_cast<short>((60-min1) + min2 - 1);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    short hour1, hour2, min1, min2, rnd;
    char colon;
    
    cout << "\t\t Welcome to the Time Calculation Program!!!\t\t\n";
    cout << "\nWhat is your first time? ";
    
    cin >> hour1 >> colon >> min1;
    
    cout << "\nWhat is your second time? ";
    
    cin >> hour2 >> colon >> min2;
        
    cout << "\nThere are " << calculateTotalMin(min1,min2,hour1,hour2) << 
    " minutes between the two times (" 
    << calculateTotalMin(min1, min2, hour1, hour2) + 2 
    << " inclusive).\n";
    
    if(calculateMinBetweenTimes(min1, min2) >= 60) {
        cout << "\nThat's the same as " 
        << floor(calculateTotalHour(hour1, hour2, min1, min2)) 
        << " hours and " <<  calculateMinBetweenTimes(min1, min2) % 60 
        << " minutes or (" << hour2-hour1 << ":"; 
        cout.fill('0');
        cout.width(2);
        cout << calculateMinBetweenTimes(min1, min2) % 60 + 2
        << " inclusive).\n";
    }
    else {
    cout << "\nThat's the same as " 
    << floor(calculateTotalHour(hour1,hour2,min1,min2)) << " hours and " 
    <<  calculateMinBetweenTimes(min1, min2) << " minutes or (" 
    << hour2-hour1-1 << ":" << 
    calculateMinBetweenTimes(min1, min2) + 2 << " inclusive).\n";
    }
    
    cout << "\nOh... and that's also " 
    << calculateTotalHour(hour1, hour2, min1, min2) << " hours (or " 
    << (calculateTotalHour(hour1, hour2, min1, min2) + (1/30.0)) 
    << " inclusive).\n";
    
    cout << "\nThank you for using the TCP!!\n";
    
    rnd = static_cast<short>(rand() % (3 - 1 + 1) + 1);
    
    switch(rnd) {
        case 1:
            cout << "\nHave a good day. \n";
            break;
        case 2:
            cout << "\nHave a marvelous day. \n";
            break;
        case 3: 
            cout << "\nHave a wonderful day. \n";
            break;
    }
}
    