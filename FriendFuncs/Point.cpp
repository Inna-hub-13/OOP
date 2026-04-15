#include "Point.h"


Point::Point(){

    set(0, 0);
}

Point::Point(int xi, int yi){

    set(xi, yi);
}

Point::Point(Point& p){

    set(p.x, p.y);
}

Point& Point::operator=(Point& p){

    set(p.x, p.y);
    return *this;
}

void Point::operator+=(Point& p) {

    x += p.x;
    y += p.y;
}

Point Point::operator+(Point& p){

    Point temp(*this);
    temp.x = x + p.x;
    temp.y = y + p.y;
    return temp;
}

int cmp(const void* el1,const void* el2){

    Point* p1 = (Point*)el1;
    Point* p2 = (Point*)el2;
    int p1X = 0, p1Y = 0, p2X = 0, p2Y = 0;
    p1->getXY(p1X, p1Y);
    p2->getXY(p2X, p2Y);
    return (p1X * p1X + p1Y * p1Y) > (p2X* p2X + p2Y * p2Y);
}

