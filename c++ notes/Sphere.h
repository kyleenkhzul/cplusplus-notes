#ifndef SPHERE_H
#define SPHERE_H

#include "ThreeD.h"

class Sphere : public ThreeD {
    double radius;
public:
    Sphere(const std::string& _name, const Point& _center, double _radius)
        : ThreeD(_name, _center), radius(_radius) {}
    void draw() const override {}
};

#endif