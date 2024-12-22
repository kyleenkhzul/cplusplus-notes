#ifndef LINE_H
#define LINE_H

#include "OneD.h"

class Line : public OneD {
    Point end;
public:
    Line(const std::string& _name, const Point& _start, const Point& _end)
        : OneD(_name, _start), end(_end) {}
    void draw() const override {}
};

#endif