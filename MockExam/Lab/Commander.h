#pragma once
#include "Person.h"

class Commander : public Person {

    char firmName[S];
    char town[S];
    char country[S];
    
    void set(char*, char*, char*);

    public:
    Commander();
    ~Commander(){}
    Commander(char*, char*, char*, unsigned, char*, char*, char*);
    void display();
};