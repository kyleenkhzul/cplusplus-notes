#ifndef TWOD_H
#define TWOD_H

#include "Shape.h"

class TwoD : public Shape {
protected:
    TwoD(const std::string& _name, const Point& _point) 
		: Shape(_name, _point) {}
};

#endif