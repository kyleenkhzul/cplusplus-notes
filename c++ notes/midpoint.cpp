#include <iostream>

using namespace std;

int main(void) {
	double x1, x2, y1, y2, midx, midy;
	char garbage;
	
	cout << "\t\n Welcome to the 2D Midpoint Program!!!\t\n";
	
	cout << "\n What is the first end-point? ";
	cin >> garbage >> x1 >> garbage >> y1 >> garbage;
	
	cout << "\n What is the second end-point? ";
	cin >> garbage >> x2 >> garbage >> y2 >> garbage;
	
	cout << "\n Thank you!!! Calculating... Done. \n";
	
	midx = (x1+x2)/2.0;
	midy = (y1+y2)/2.0;
	
	cout << "\n The midpoint of the line segment between (" 
	<< x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ")\n is (" 
			<< midx << ", " << midy << ").\n";
	
	cout << "\nThank you for using the TMP!!\n";
	cout << "\nHave a good day\n";
}

