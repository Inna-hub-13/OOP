#include <iostream>
#include <string.h>
#include "Person.h"
#include "Foreman.h"
#include "Product.h"
#include "Earning.h"

using namespace std;

void Person::set(char* egnS, char* nameS, char* emailS, unsigned gsmS) {

    strcpy(egn, egnS);
    strcpy(name, nameS);
    strcpy(email, emailS);
    gsm = gsmS;
}

Person::Person() {

    set("", "", "", 0);
}

Person::Person(char* egnS, char* nameS, char* emailS, unsigned gsmS){

    set(egnS, nameS, emailS, gsmS);
}

void Person::display() {

    cout<<"Egn: " << egn << endl;
    cout<<"Name: " << name << endl;
    cout<<"Email: " << email << endl;
    cout<<"GSM: " << gsm << endl;
}

void Foreman::set(unsigned facNumS, char* uniS, char* disS, Commander* comS) {

    facNum = facNumS;
    strcpy(university, uniS);
    strcpy(discipline, disS);
    com = comS;
}

Foreman::Foreman() : Person() {

    set(0, "", "", nullptr);
}

Foreman::Foreman(char* egnS, char* nameS, char* emailS, unsigned gsmS,
     unsigned facNumS, char* uniS, char* disS, Commander* comS) : Person(egnS, nameS, emailS, gsmS) {

        set(facNumS, uniS, disS, comS);
     }

void Foreman::display(){

    cout<<endl;
    cout<< "I am a foreman"<< endl;
    cout<<"Egn: " << egn << endl;
    cout<<"Name: " << name << endl;
    cout<<"Email: " << email << endl;
    cout<<"GSM: " << gsm << endl;
}


void Commander::set(char* firmNameS, char* townS, char* countryS) {

    strcpy(firmName, firmNameS);
    strcpy(town, townS);
    strcpy(country, countryS);
}

Commander::Commander() : Person() {

    set("", "", "");
}

Commander::Commander(char* egnS, char* nameS, char* emailS, unsigned gsmS, 
    char* firmNameS, char* townS, char* countryS) : Person(egnS, nameS, emailS, gsmS) {

        set(firmNameS, townS, countryS);
} 

void Commander::display(){
    
    cout<<endl;
    cout<< "I am a commander"<< endl;
    cout<<"Egn: " << egn << endl;
    cout<<"Name: " << name << endl;
    cout<<"Email: " << email << endl;
    cout<<"GSM: " << gsm << endl;
}

void Product::set(char* dateS, Foreman* foreManS, char* materialS, double amountS){

    strcpy(date, dateS);
    foreMan = foreManS;
    strcpy(material, materialS);
    amount = amountS;
}

Product::Product() {

    set("", nullptr, "", 0);
}

Product::Product(char* dateS, Foreman* foreManS, char* materialS, double amountS){

    set(dateS, foreManS, materialS, amountS);
}

void Product::display() {

    //foreMan -> display();
    cout << date << " " << material << " " << amount << endl; 
}


Product& Product::operator=(Product& right){

    if(this != &right)
        set(right.date, right.foreMan, right.material, right.amount);

    return *this;
}

unsigned getNextFib(unsigned currentCapacity){

    // 1 + 1 = 2 , 1 + 2 = 3, 2 + 3 = 5 ...

    // 8 ?? -> 13
    // 7 ?? -> 8
    // 5 ?? -> 8

    unsigned f1 = 1, f2 = 1, fib = 1;
    while(fib <= currentCapacity){

        fib = f1 + f2;
        f1 = f2;
        f2 = fib;
    }

    return fib;
}

void Earning::expand(){

    capacity = getNextFib(capacity);
    Product* temp = new Product[capacity];

    unsigned i = 0;
    for(;i < size; i++)
        *(temp + i) = *(prods + i);

    delete[] prods;
    prods = temp;
}

Earning::Earning() {

    capacity = getNextFib(0);
    size = 0;
    prods = new Product[capacity];
}

void Earning::addAtEnd(Product* product){

    if(size >= capacity)
        expand();

    *(prods + size) = *product;
    size++;
}

void Earning::display(){
    
    unsigned i = 0;
    for(; i < size; i++)
        (prods + i)->display();
}

int cmp(const void* prod1, const void* prod2){

    Product* p1 = (Product*)prod1;
    Product* p2 = (Product*)prod2;

    if(p1->amount > p2->amount)
        return 1;
    else if(p1->amount == p2->amount)
        return 0;
    else 
        return -1;
}

int main() {

    Commander com1 ("999", "Joann", "@@", 6210, "South", "Brithon", "Britain");
    Commander com2 ("999", "Dain", "@@", 6310, "North", "Miami", "USA");

    Foreman f1 ("699", "Stefani", "@@", 7310, 3210, "TU-Sofia", "KST", &com1);
    Foreman f2 ("699", "Veselin", "@@", 5310, 3210, "TU-Sofia", "MM", &com2);

    Product p1 ("10.10 2026", &f1, "tomatoes", 10);
    Product p2 ("10.10 2026", &f1, "cucumbers", 11);
    Product p3 ("10.10 2026", &f1, "raspberries", 13);
    Product p6("10.10 2026", &f1, "raspberries", 13.5);

    Product p4("13.10 2026", &f2, "wool", 5);
    Product p5 ("13.10 2026", &f2, "linen", 3);

    Earning e1;
    e1.addAtEnd(&p1);
    e1.addAtEnd(&p2);
    e1.addAtEnd(&p3);
    e1.addAtEnd(&p4);
    e1.addAtEnd(&p5);
    e1.addAtEnd(&p6);


    e1.display();
    qsort(e1.getArray(), e1.getSize(), sizeof(Product), cmp);

    cout<<endl;
    cout<< "After qsort:"<<endl;
    e1.display();

    return 0;
}

