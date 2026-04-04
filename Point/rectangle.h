#include "point.h"

class Rectangle:public Point{

    double w, h;

    public:
    Rectangle(double xi, double yi, double wi, double hi):Point(xi, yi){w = wi; h = hi;}
    double area();
};