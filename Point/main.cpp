#include <stdio.h>
#include "cylinder.h"

double Circle::area(){

    return 3.14 * r * r;
}

double Cylinder::area(){

    return 2 * 3.14 * r *(r + h);
}


int main() {

    Point p(12, 13);
    Circle c(10, 11, 3);
    Cylinder cy(10, 11, 3, 2);

    Point* p_ptr;
    Circle* c_ptr;

    p_ptr = &p;
    printf("point area(): %.2lf\n", p_ptr->area());
    p_ptr = &c;
    printf("circle area(): %.2lf\n", p_ptr->area());
    // c_ptr = &p; compile error
    p_ptr = &cy;
    printf("cylinder area(): %.2lf\n", p_ptr->area());

    return 0;
}
