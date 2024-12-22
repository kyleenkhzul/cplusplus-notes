#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x1, x2, y1, y2, distance;
	char garbage;
	
	cout << "\t\n Welcome to the 2D Distance Program!!!\t\n";
	
	cout << "\n What is the first point? ";
	cin >> garbage >> x1 >> garbage >> y1 >> garbage;

	
	cout << "\n What is the second point? ";
	cin >> garbage >> x2 >> garbage >> y2 >> garbage;
	
	cout << "\n Thank you!!! Calculating... Done. \n";
	
	distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

	cout << "\n(" << x1 << ", " << y1 << ") is " << distance 
	<< " units away from (" << x2 << ", " << y2 << ").\n";
	
	cout << "\nThank you for using the TDP!!\n";
	cout << "\nHave a good day\n";
}

