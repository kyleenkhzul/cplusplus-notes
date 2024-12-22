#ifndef CONE_H
#define CONE_H

#include "ThreeD.h"

class Cone : public ThreeD {
    double radius, height;
public:
    Cone(const std::string& _name, const Point& _center, double _radius, 
		double _height)
        : ThreeD(_name, _center), radius(_radius), height(_height) {}
    void draw() const override {}
};

#endif