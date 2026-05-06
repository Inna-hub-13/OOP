#include "Product.h"

class Earning{

    Product* prods;
    unsigned size;
    unsigned capacity;

    void expand();

    public:
    Earning();
    ~Earning(){delete[] prods; prods = nullptr;}
    void addAtEnd(Product*);
    void display();
    Product* getArray() const { return prods; }
    unsigned getSize() const { return size;}
    //Commander* bestCommander();
};

unsigned getNextFib(unsigned);
