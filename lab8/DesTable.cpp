#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DesTable.h"

DesTable::DesTable(){

    table = new LexUnit[2];
    capacity = 2;
    length = 0;
}

int DesTable::resize(){

    LexUnit* temp = new LexUnit[capacity * 2];
    if(!temp)
        return -1;
    
    int i;
    for(i = 0; i < capacity; i++)
        *(temp + i) = *(table + i);
    
    free(table);
    table = temp;
    capacity *= 2;
    return 0;
}

DesTable::~DesTable() {

    delete[] table;
    table = nullptr;
}

int DesTable::LinearSearch(char* iden){

    int index;

    for(index = 0; index < length; index++)
        if(strcmp((table + index)->getIdentifier(), iden) == 0)
            return index;
    
    return -1;
}

int DesTable::AddAtEnd(LexUnit* lU){

    if(!lU)
        return -1;
    
    int index = LinearSearch(lU->getIdentifier());
    // The unit is already in the table, so it can't be added again
    if(index != -1)
        return -1;

    // Invalid unit can't be added
    if(lU->getAddress() == -1)
        return -1;

    if(length == capacity)
        resize();

    *(table + length) = *lU;
    length++;
    return 0;
}

int DesTable::Delete(char* iden){

    if(length == 0)
        return -1;

    int index = LinearSearch(iden);
    if(index == -1)
        return -1;

    int i;
    for(i = index; i < length - 1; i++)
        *(table + i) = *(table + i + 1);

    length--;
    return 0;
}

void DesTable::print(){

    printf("\nidentifier\ttype\tdecriptor\taddress\n");
    int i;
    for(i = 0; i < length; i++)
        (table + i)->print();
}