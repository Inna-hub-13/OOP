#include <stdio.h>
#include <iostream>
#include "Point.h"
#define N 5

using namespace std;


int main() {

    Point p1(2, 3);
    Point p2 = p1;
    Point p3 = p1 + p2;
    Point p4 = p3 + p1;
    Point p5(3, -1);

    Point points[N];
    *(points + 0) = p1;
    *(points + 1) = p4;
    *(points + 2) = p3;
    *(points + 3) = p2;
    *(points + 4) = p5;

    int i, xTemp = 0, yTemp = 0;
    for(i = 0; i < N; i++){

        (points + i)->getXY(xTemp, yTemp);
        cout<< "Point: " <<"("<< xTemp << ";" << yTemp<< ")" << endl;
    }

    qsort((Point*)points, N, sizeof(Point), cmp);

    cout<<"After qsort:"<<endl;
    for(i = 0; i < N; i++){

        (points + i)->getXY(xTemp, yTemp);
        cout<< "Point: " <<"("<< xTemp << ";" << yTemp<< ")" << endl;
    }

    return 0;
}
