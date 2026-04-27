#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DihotTable.h"

using namespace std;

int DihotTable::resize() {

    LexUnit* temp = new LexUnit[capacity * 2];
    if(!temp)
        return -1;
    
    int i;
    for(i = 0; i < length; i++)
        *(temp + i) = *(table + i);
    
    delete[] table;
    table = temp;
    capacity *= 2;
    return 0;
}

DihotTable::DihotTable(){

    table = new LexUnit[2];
    capacity = 2;
    length = 0;
}

DihotTable::~DihotTable(){

    delete[] table;
    table = nullptr;
}

int DihotTable::BinarySearch(char* iden){

    if(length == 0)
        return 0;

    int l = 0, r = length - 1, mid = 0, res = 0;

    // Checks if the element to be added should be placed last
    res = strcmp(iden, (table + length - 1)->getIdentifier());
    if(res > 0)
        return length;

    // Checks if the element to be added should be placed first
    res = strcmp(iden, (table + 0)->getIdentifier());
    if(res < 0)
        return -1;

    while(l <= r){
        
        mid = (l + r)/2;
        res = strcmp(iden, (table + mid)->getIdentifier());
        if(res < 0)
            r = mid - 1;
        else if(res > 0)
            l = mid + 1;
        else    
            return mid;

   }

    if(l > mid)
        return l + length;

    return mid + length;
}

int DihotTable::Add(LexUnit* lU){

    
    int i = 0, index = 0, pos = 0;
    pos = BinarySearch(lU->getIdentifier());

    if(pos == -1)
        index = 0;
    else if(pos == length)
        index = pos;
    else if(pos < length) // Element already in table
        return -1;
    else
        index = pos - length;

    if(length >= capacity)
        resize();

    for(i = length; i > index; i--)
        *(table + i) = *(table + i - 1);
    
    *(table + index) = *lU;
    length ++;
    return 0;
}

int DihotTable::Delete(char* iden){

    int pos = BinarySearch(iden);

    // Element not in table
    if(pos >= length)
        return -1;
    
    int i;
    for(i = pos; i < length - 1; i++)
        *(table + i) = *(table + i + 1);

    length--;
    return 0;
}

void DihotTable::print(){

    printf("\nidentifier\ttype\tdescriptor\taddress\n");
    int i;
    for(i = 0; i < length; i++)
        (table + i)->print();
}
