#include <stdio.h>
#include <string.h>
#include "LexUnit.h"

unsigned LexUnit::nextAddress = 0;
unsigned LexUnit::nextVNum = 1;

void LexUnit::set(char* iden, char* typ, char* des, unsigned adr){

    strcpy(identifier, iden);
    strcpy(type, typ);
    strcpy(descriptor, des);
    address = adr;
}

LexUnit::LexUnit() {

    set("", "", "", 0);
}

LexUnit::LexUnit(char* iden, char* typ){

     if((strcmp(typ, "int") != 0) && (strcmp(typ, "char") !=0) && (strcmp(typ, "float") != 0) &&
                (strcmp(typ, "double") != 0))

        set(iden, typ, "invalid\0", 10000000);
    
    else{

        set(iden, typ, "", 0);
        setAddress();
        setDescriptor();
    }
}

LexUnit::LexUnit(LexUnit& lU){

    set(lU.identifier, lU.type, lU.descriptor, lU.address);
}

LexUnit& LexUnit::operator=(LexUnit& lU){

    set(lU.identifier, lU.type, lU.descriptor, lU.address);
    return *this;
}

void LexUnit::print(){

    printf("%s\t\t%s\t%s\t\t%u\n", identifier, type, descriptor, address);
}

void LexUnit::setAddress(){

    address = nextAddress;
    if(strcmp(type, "char") == 0)
        nextAddress += 1;
    else if(strcmp(type, "int") == 0)
        nextAddress += 2;
    else if(strcmp(type, "float") == 0)
        nextAddress += 4;
    else if(strcmp(type, "double") == 0)
        nextAddress += 8;
}

void LexUnit::setDescriptor(){

    sprintf(descriptor, "V%u", nextVNum);
    nextVNum++;
}

char* LexUnit::getIdentifier(){

    return identifier;
}

unsigned LexUnit::getAddress(){

    return address;
}
