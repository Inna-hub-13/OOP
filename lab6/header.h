#define NSTR 30
#define NSIZE 30

class Property{

    protected:
    char address[NSTR];
    char owner[NSTR];
    double price;
    double area;

    public:
    //Property();
    Property(char*, char*, double, double);
    virtual void print(){printf("Just property\n");};
    // Each child of property has unique ID
    // apartment 1000
    // parcel 1001
    // house 1010
    virtual int getPropertyID(){return 0;};
    double getPrice();
};

class Apartment:public Property{

    int countFloors;
    int floor;

    public:
    Apartment(char*, char*, double, double, int, int);
    void print();
    int getPropertyID();
};

class House:public Property{

    int countRooms;
    int countFloors;
    double areaYard;

    public:
    House(char*, char*, double, double, int, int, double);
    void print();
    int getPropertyID();
};

class Parcel:public Property{

    bool hasWater;
    bool hasElectricity;
    bool nearRoad;

    public:
    Parcel(char*, char*, double, double, bool, bool, bool);
    void print();
    int getPropertyID();
};

class Agency{

    char name[NSTR];
    Property* properties[NSIZE];
    int countProperties;

    public:
    Agency(char*);
    Property* findProperty(int);
    int addProperty(Property*);
    // This method removes the fist found property with the given ID
    int removeProperty(int);
    void findPriceRange(double, double);
    void print();
    void printOnly(int);
};