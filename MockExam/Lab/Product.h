#pragma once
#include "Foreman.h"

class Product{

    friend int cmp(const void*, const void*);
    char date[N];
    Foreman * foreMan;
    char material[S];
    double amount;
    void set(char*, Foreman*, char*, double);

    public:
    Product();
    Product(char*, Foreman*, char*, double); 
    void display();
    Product& operator=(Product&);
};