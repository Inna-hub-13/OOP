class Point{

    double x, y;
    
    public:
    Point(double xi, double yi){x = xi; y = yi;}
    virtual double area(){return 0;}
};