#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "TwoD.h"

class Rectangle : public TwoD {
    double length, width;
public:
	Rectangle(const std::string& _name, const Point& _topLeft, double _length, 
		double _width)
        : TwoD(_name, _topLeft), length(_length), width(_width) {}
    void draw() const override {}
};

#endif