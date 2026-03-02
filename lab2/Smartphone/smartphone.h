
class Smartphone{

    char model[20];
    double price;
    char os[20];

    public:
    Smartphone();
    Smartphone(char*, double, char*);
    Smartphone(Smartphone&);
    double getPrice();
    void setSmartphone(char*, double, char*);
    void print();
};

