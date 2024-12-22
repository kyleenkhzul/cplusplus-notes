#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include <string>

class Shape {
protected:
    std::string name;
    Point point;
public:
    Shape(const std::string& _name, const Point& _point) 
		: name(_name), point(_point) {}
    virtual ~Shape() {}
    virtual void draw() const = 0;
    virtual void print() const {
        std::cout << "Shape: " << name << std::endl;
    }
    const std::string& getName() const { return name; }
    const Point& getPoint() const { return point; }
};

#endif 
