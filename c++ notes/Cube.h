#ifndef CUBE_H
#define CUBE_H

#include "ThreeD.h"

class Cube : public ThreeD {
    double side;
public:
    Cube(const std::string& _name, const Point& _topLeftBack, double _side)
        : ThreeD(_name, _topLeftBack), side(_side) {}
    void draw() const override {}
};

#endif 
