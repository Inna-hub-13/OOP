#pragma once

#include "point.h"

class Circle:public Point{

    //protected:
    //double r;

    public:
    double r;
    Circle(double xi, double yi, double ri):Point(xi, yi){ r = ri;}
    double area();
};
