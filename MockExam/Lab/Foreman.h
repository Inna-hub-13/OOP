#pragma once
#include "Person.h"
#include "Commander.h"

class Foreman : public Person {

    unsigned facNum;
    char university[S];
    char discipline[S];
    Commander* com;

    void set(unsigned, char*, char*, Commander*);

    public:
    Foreman();
    ~Foreman(){}
    Foreman(char*, char*, char*, unsigned, unsigned, char*, char*, Commander*);
    void display();
};