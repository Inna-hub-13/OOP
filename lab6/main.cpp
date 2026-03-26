#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

Property::Property(char* address, char* owner, double price, double area){

    strcpy(this->address, address);
    strcpy(this->owner, owner);
    this->price = price;
    this->area = area;
}

double Property::getPrice(){

    return price;
}

Apartment::Apartment(char* address, char* owner, double price, double area,
     int countFloors, int floor):Property(address, owner, price, area){

        this->countFloors = countFloors;
        this->floor = floor;
}

void Apartment::print() {

    printf("\n**************************************\n");
    printf("Apartment:\n");
    printf("Address: %s\n", address);
    printf("Owner: %s\n", owner);
    printf("Price: %.2lf euro\n", price);
    printf("Area: %.2lf\n", area);
    printf("Number of floors: %d\n", countFloors);
    printf("Floor: %d\n", floor);
    printf("**************************************\n");
}

int Apartment::getPropertyID(){

    return 1000;
}

House::House(char* address, char* owner, double price, double area,
     int countRooms, int countFloors, double areaYard):Property(address, owner, price, area){

        this->countRooms = countRooms;
        this->countFloors = countFloors;
        this->areaYard = areaYard;
}

void House::print() {

    printf("\n**************************************\n");
    printf("House:\n");
    printf("Address: %s\n", address);
    printf("Owner: %s\n", owner);
    printf("Price: %.2lf euro\n", price);
    printf("Area: %.2lf\n", area);
    printf("Number of rooms: %d\n", countRooms);
    printf("Number of floors: %d\n", countFloors);
    printf("Area of yard: %.2lf\n", areaYard);
    printf("**************************************\n");
}

int House::getPropertyID() {

    return 1010;
}

Parcel::Parcel(char* address, char* owner, double price, double area,
     bool hasWater, bool hasElectricity, bool nearRoad):Property(address, owner, price, area){

        this->hasWater = hasWater;
        this->hasElectricity = hasElectricity;
        this->nearRoad = nearRoad;
}

void Parcel::print() {

    printf("\n**************************************\n");
    printf("Parcel:\n");
    printf("Address: %s\n", address);
    printf("Owner: %s\n", owner);
    printf("Price: %.2lf euro\n", price);
    printf("Area: %.2lf\n", area);
    printf("Has water: %d\n", hasWater);
    printf("Has electricity: %d\n", hasElectricity);
    printf("Near road: %d\n", nearRoad);
    printf("**************************************\n");
}

int Parcel::getPropertyID() {

    return 1001;
}

Agency::Agency(char* name){

    strcpy(this->name, name);
    countProperties = 0;
}

Property* Agency::findProperty(int ID) {

    int i;
    for(i = 0; i < countProperties; i++)
        if((*(properties + i))->getPropertyID() == ID)
            return *(properties + i);
    
    return NULL;
}

int Agency::addProperty(Property* pr){

    if(countProperties >= NSIZE){

        printf("This agency can't accommodate more properties!\n");
        return -1;
    }

    *(properties + countProperties) = pr;
    countProperties++;
    return 0;
}

int Agency::removeProperty(int ID){

    Property* temp = findProperty(ID);
    if(!temp){

        printf("No property with ID %d found!\n", ID);
        return -1;
    }

    int i;
    for(i = 0; i < countProperties && *(properties + i) != temp; i++);

    for(;i < countProperties - 1; i++)
        *(properties + i) = *(properties + i + 1);

    free(temp);
    countProperties--;
    return 0;
}

void Agency::findPriceRange(double lPrice, double hPrice){

    int i;
    double price = 0;
    printf("\n\nPrice range (%.2lf - %.2lf) euro:\n", lPrice, hPrice);
    for(i = 0; i < countProperties; i++){
        
        price = (*(properties + i))->getPrice();
        if(price >= lPrice && price <= hPrice)
            (*(properties + i))->print();
    }
}

void Agency::print(){

    int i;
    printf("\n==============================================================\n");
    printf("Agency \"%s\" has %d properties\n", name, countProperties);

    for(i = 0; i < countProperties; i++)
        (*(properties + i))->print();
    
    printf("\n==============================================================\n");
}


int main(){

    Agency a("BuildingImot");

    Property* h1 = new House("Ivan Vazov 10", "Ivan Ivanov", 100000, 50, 5, 2, 10);
    House* h2 = new House("Vasil Levski 11", "Yana Yazova", 1538999, 45, 10, 3, 10);

    Property* a1 = new Apartment("Ivan Vazov 16", "Petya Nedelina", 100000, 50, 7, 3);
    Apartment* a2 = new Apartment("Lyuben Karavelov 16", "Silviya Petrova", 500000, 50, 10, 3);

    Property* parcel = new Parcel("Klokotnitsa 1", "Stefan Penev", 20000, 50, true, true, true);

    a.addProperty(h1);
    a.addProperty(h2);
    a.addProperty(a1);
    a.addProperty(a2);
    a.addProperty(parcel);

    a.print();

    //a.findPriceRange(100000, 500001);
    //a.findPriceRange(20000, 100000);

    a.removeProperty(1001);
    a.print();
    return 0;
}
