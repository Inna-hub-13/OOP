class Point{

    int x, y;
    void set(int xi, int yi){x = xi; y = yi;}

    public:
    Point ();
    Point(int, int);
    Point(Point& p);
    Point& operator=(Point&);
    void operator+=(Point&);
    Point operator+(Point&);
    ~Point(){}
    friend int cmp(const void* el1,const void* el2);//Въшна за класа
    void getXY(int& xRef, int& yRef){xRef = x; yRef = y;}
};

