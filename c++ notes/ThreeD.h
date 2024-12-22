#ifndef THREED_H
#define THREED_H

#include "Shape.h"

class ThreeD : public Shape {
protected:
    ThreeD(const std::string& _name, const Point& _point) 
		: Shape(_name, _point) {}
};

#endif