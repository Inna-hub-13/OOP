#pragma once
#define S 15

class LexUnit{

    char identifier[S];
    char type[S];
    char descriptor[S];
    unsigned address;
    static unsigned nextVNum;
    static unsigned nextAddress;

    void set(char*, char*, char*, unsigned);
    void setAddress();
    void setDescriptor();

    public:
    LexUnit();
    LexUnit(char*, char*);
    LexUnit(LexUnit&);
    LexUnit& operator=(LexUnit&);
    void print();
    char* getIdentifier();
    unsigned getAddress();
};