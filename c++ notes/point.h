#ifndef POINT_H
#define POINT_H

class Point {
public:
    double x, y, z;
    Point() : x(0), y(0), z(0) {} 
    Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {} 
};

#endif 
