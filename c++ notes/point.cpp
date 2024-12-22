#include "point.h"

#include <iostream>
#include <cmath>

using namespace std;

// read standard 2D point notation (x,y) -- ignore
// window dressing
void Point::Input(void)
{
    char dummy;
    cin >> dummy >> x >> dummy >> y >> dummy;
    return;
}

// output standard 2D point notation (x,y)
void Point::Output(void)
{
    cout << '(' << x << ", " << y << ')';
    return;
}

// calculate distance between two 2D points --
// the one that called us and the argument
double Point::distance(Point other)
{
    return sqrt(pow(other.x-x, 2.0) +
                pow(other.y-y, 2.0));
}

// set coordinates to programmer-specified values
void Point::set_x(double new_x)
{
    x = new_x;        // no error checking since anything is legal
    return;
}

// set coordinates to programmer-specified values
void Point::set_y(double new_y)
{
    y = new_y;        // no error checking since anything is legal
    return;
}

// construct Point by default -- no values specified
Point::Point(void)
	: x(0.0), y(0.0) {}

// construct Point given initial x,y values
Point::Point(double new_x, double new_y)
	: x(new_x), y(new_y) {}

// creates a point flipped about the x axis from us
Point Point::flip_x(void)
{
    return Point(x,-y);
}

// creates a point flipped about the y axis from us
Point Point::flip_y(void)
{
    return Point(-x,y);
}

// creates a point shifted along the x axis from us
Point Point::shift_x(double move_by)
{
    return Point(x+move_by,y);
}

// creates a point shifted along the y axis from us
Point Point::shift_y(double move_by)
{
    return Point(x,y+move_by);
}

// Overload operator- for distance between two points
double Point::operator-(const Point& other) const
{
	return sqrt(pow(other.get_x() - get_x(), 2.0) + 
		pow(other.get_y() - get_y(), 2.0));
}

// Overload operator>> for input
istream& operator>>(istream& in, Point& p)
{
    char dummy;
    in >> dummy >> p.x >> dummy >> p.y >> dummy;
    return in;
}

// Overload operator<< for output
ostream& operator<<(ostream& out, const Point& p)
{
    out << '(' << p.x << ", " << p.y << ')';
    return out;
}

// Overload operator== for equality
bool Point::operator==(const Point& other) const
{
// Included a tolerance because the operator== was throwing warnings of
// floating-point conversion. This meant that if the comparison was too
// large it could lead to problems so this is the only fix that I found.
    const double range = 1e-8; 
    return (abs(x - other.x) < range) && (abs(y - other.y) < range);
}

// Overload operator!= for inequality
bool Point::operator!=(const Point& other) const
{
    return !(*this == other);
}

// Overload operator/ for midpoint
Point Point::operator/(const Point& other) const
{
    return Point((x + other.x) / 2.0, (y + other.y) / 2.0);
}

// Overloading operator for []
double& Point::operator[](char coordinate)
{
    if (coordinate == 'x' || coordinate == 'X')
    {
        return x;
    }
    else if (coordinate == 'y' || coordinate == 'Y')
    {
        return y;
    }
    else
    {
        cerr << "Invalid coordinate specified";
    }
	static double dummy = 0.0; // Dummy value to return in case of error
    return dummy;
}

// Driver program
int main()
{
    Point p1(1.0, 2.0);
    Point p2(4.0, 6.0);
	
	cout << "Generating two points...\n";
	cout << "Point 1 of: " << p1 << "\n";
	cout << "Point 2 of: " << p2 << "\n";

    // Usage of overloaded operators
    double distance1 = p1 - p2;
    cout << "The distance between p1 and p2 are: " << distance1 
		<< " units\n" << endl;

    cout << "Enter a point: ";
    cin >> p1;
    cout << "You entered: " << p1 << endl;
	cout << "Setting Point 1 to " << p1 << endl;
	
	double distance2 = p1 - p2;
    cout << "The new distance between p1 and p2 are: " << distance2
		<< " units\n" << endl;

    cout << "\nAre p1 and p2 equal? "  << endl;
	if(p1==p2) {
		cout << "Yes, p1 and p2 are equal.\n" << endl;
	}
	else {
		cout << "No, p1 and p2 are not equal.\n" << endl;
	}
	
    cout << "Are p1 and p2 not equal? " << endl;
	if(p1!=p2) {
		cout << "Yes, p1 and p2 are not equal.\n" << endl;
	}
	else {
		cout << "No, p1 and p2 are equal.\n" << endl;
	}

    Point midpoint = p1 / p2;
    cout << "The midpoint between p1 and p2 is: " << midpoint << endl;
	
	Point p3(3.2, 9.8);
	cout << "\nGenerating a third point of: " << p3 << endl;
	double my_x, my_y;
	my_x = p3['x'];   
	my_y = p3['y'];
	cout << "\nThe x-value of Point 3 is " << my_x << endl;
	cout << "The y-value of Point 3 is " << my_y << endl;
	
    return 0;
}