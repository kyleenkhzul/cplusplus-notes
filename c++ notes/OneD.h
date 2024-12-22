#ifndef ONED_H
#define ONED_H

#include "Shape.h"

class OneD : public Shape {
protected:
    OneD(const std::string& _name, const Point& _point) 
		: Shape(_name, _point) {}
};

#endif