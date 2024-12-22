#include <iostream>
#include <cmath>
#include <limits>

using namespace std;
constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

double calculateMidX(double x1, double x2) {
    return ((x1+x2)/2.0);
}
    
double calculateMidY(double y1, double y2) {
    return ((y1+y2)/2.0);
}

double calculateDistance(double x1, double x2, double y1, double y2) {
    return (sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)));
}

void printDistance(double x1, double x2, double y1, double y2, 
   double distance){
    cout << "\n(" << x1 << ", " << y1 << ") is " << distance 
         << " units away from (" << x2 << ", " << y2 << ").\n\n";
}

void printMidpoint(double x1, double x2, double y1, double y2, 
double midx, double midy) {
    cout << "\n The midpoint of the line segment from (" 
         << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 
         << ")\n is (" << midx << ", " << midy << ").\n\n";
}

int main() {
    double x1, x2, y1, y2, midx, midy, distance;
    char garbage, choice;
    bool done = false;
    
    cout << "\t\t\t Welcome to the Point Menu Program!!!\t\n";

    while(!done) {
        cout << "\n\t1) Calculate Distance Between Two Points\n"
    "\t2) Calculate Midpoint of Two Points\n"
    "\t3) Quit\n\n"
    "\tChoice:    ";
    
        cin >> choice;
        cin.ignore(INF_FLAG, '\n');
        
        choice = static_cast<char>(toupper(choice));
        
        switch(choice) {
            case '1': case 'D':
    cout << "\nWhere is the first point? ";
    cin >> garbage >> x1 >> garbage >> y1 >> garbage;
    
    cout << "\nWhere is the second point? ";
    cin >> garbage >> x2 >> garbage >> y2 >> garbage;            
            
    distance = calculateDistance(x1, x2, y1, y2);

    printDistance(x1, x2, y1, y2, distance);
    break;
            case '2': case 'M':
    cout << "\nWhere is the first point? ";
    cin >> garbage >> x1 >> garbage >> y1 >> garbage;
            
    cout << "\nWhere is the second point? ";
    cin >> garbage >> x2 >> garbage >> y2 >> garbage;
        
    midx = calculateMidX(x1, x2);
    midy = calculateMidY(y1, y2);
        
    printMidpoint(x1, x2, y1, y2, midx, midy);
    break;
            case '3': case 'Q':
    cout << "\nThank you for using the PMP!!\n";
    cout << "\nHave a good day!\n";
    done = true;
    break;
            default:
    cout << "\nI'm sorry, that choice is invalid! \n";
    cout << "\nPlease try to read/type more carefully ";
    cout << "next time\n";
        }
    }
}    
    