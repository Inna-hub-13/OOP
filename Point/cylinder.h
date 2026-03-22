#include "circle.h"

class Cylinder : public Circle{

    double h;

    public:
    Cylinder(double xi, double yi, double ri, double hi):Circle(xi, yi, ri){ h = hi;}
    double area();
};