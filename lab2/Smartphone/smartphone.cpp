#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smartphone.h"


Smartphone::Smartphone() {

    setSmartphone("Samsung", 1000, "Android");
}

Smartphone::Smartphone(char* model, double price, char* os) {

    setSmartphone(model, price, os);
}

Smartphone::Smartphone(Smartphone& sphone) {

    setSmartphone(sphone.model, sphone.price, sphone.os);
}

void Smartphone::setSmartphone(char* model, double price, char* os) {

    strcpy_s(this->model, model);
    this->price = price;
    strcpy_s(this->os, os);
}

double Smartphone::getPrice() {

    return price;
}

void Smartphone::print() {

    printf("Model\t\tPrice\t\tOs\n");
    printf("%s   \t%.2lf\t\t%s\n\n", model, price, os);
}





