#pragma once
#define S 15
#define N 11

class Person{

    protected:
    char egn[N];
    char name[S];
    //char midName[S];
    //char famName[S];
    //char address[S];
    char email[S];
    unsigned gsm;

    void set(char*, char*, char*, unsigned);

    public:
    Person();
    Person(char*, char*, char*, unsigned);
    virtual ~Person(){}
    virtual void display();
};