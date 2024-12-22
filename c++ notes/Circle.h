#ifndef CIRCLE_H
#define CIRCLE_H

#include "TwoD.h"

class Circle : public TwoD {
    double radius;
public:
    Circle(const std::string& _name, const Point& _center, double _radius)
        : TwoD(_name, _center), radius(_radius) {}
    void draw() const override {}
};

#endif 
