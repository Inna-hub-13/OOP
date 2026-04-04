#include <stdio.h>
#include "point.h"
#include "cylinder.h"
#include "circle.h"
#include "rectangle.h"

double Circle::area(){

    return 3.14 * r * r;
}

double Cylinder::area(){

    return 2 * 3.14 * r * (r + h);
}

double Rectangle::area() {

    return w * h;
}


double areaDiff(Point* p1, Point* p2){

    return p1->area() - p2->area();
}

int main() {

    Point p(12, 13);
    Circle c(10, 11, 3);
    Cylinder cy(10, 11, 3, 2);
    Rectangle r(14, 15, 5, 6);

    Point* p_ptr;
    Circle* c_ptr;

    p_ptr = &p;
    printf("point area(): %.2lf\n", p_ptr->area());
    p_ptr = &c;
    printf("circle area(): %.2lf\n", p_ptr->area());
    // c_ptr = &p; compile error
    p_ptr = &cy;
    printf("cylinder area(): %.2lf\n", p_ptr->area());
    p_ptr = &r;
    printf("rectangle area(): %.2lf\n", p_ptr->area());

    printf("rectangle circle areaDiff(): %.2lf\n", areaDiff(&r, &c));
    printf("circle rectangle areaDiff(): %.2lf\n", areaDiff(&c, &r));

    Circle * pSC = static_cast<Circle *>(&p);
    printf("pSC area(): %.2lf; %p pSC->r = %.2lf\n", pSC->area(), &(pSC->r), pSC->r);// area 0
    
    Circle * pDC = dynamic_cast<Circle *>(&p);
    if(!pDC)
        printf("No dynamic pDC\n");

    Circle * pRC = reinterpret_cast<Circle *>(&p);
    if(!pRC)
        printf("No reinterpret pRC\n");
    
    printf("pRC area(): %.2lf; %p pRC->r = %.2lf\n", pRC->area(), &(pRC->r), pRC->r);// area 0

    // Circle * rSC = static_cast<Circle *>(&r); compile error

    Circle * rDC = dynamic_cast<Circle *>(&r);
    if(!rDC)
        printf("No dynamic rDC\n");

    Circle * rRC = reinterpret_cast<Circle *>(&r);
    if(!rRC)
        printf("No reinterpret rRC\n");

    printf("rRC->area() %.2lf\n", rRC->area());// rectangle area
    printf("rRC->r %.2lf\n", rRC->r);// rectangle w


    return 0;
}
