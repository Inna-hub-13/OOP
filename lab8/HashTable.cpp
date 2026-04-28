#include <stdio.h>
#include <string.h>
#include "HashTable.h"


int HashTable::HashFunction(char* iden){

    int i = 0, sum = 0;
    while(*(iden + i) != '\0'){
        
        sum += *(iden + i);
        i++;
    }
    
    return sum & (L-1);
}

int HashTable::Search(char* iden){

    int hashCode = HashFunction(iden);

    // Element already in hash table
    if(strcmp(iden, (table + hashCode)->getIdentifier()) == 0)
        return hashCode + L;

    int start;
    for(start = hashCode; start < L; start++)
        if(strcmp((table + start)->getIdentifier(), "") == 0)
            return start;
        
    for(start = 0; start < hashCode; start++)
        if(strcmp((table + start)->getIdentifier(), "") == 0)
            return start;
    
    return -1;
}

int HashTable::Add(LexUnit& lU){

    int pos = Search(lU.getIdentifier());

    if(pos == -1 || pos > L)
        return -1;

    *(table + pos) = lU;
    return 0;
}

int HashTable::Delete(char* iden){

    int pos = Search(iden);

    if(pos == -1 || pos < L)
        return -1;

    pos -= L;
    (table + pos)->set("", "", "", 0);
    return 0;
}

void HashTable::print(){

    printf("\n------------------------------------------\n");
    int pos;
    for(pos = 0; pos < L; pos++){

        printf("%d. ", pos);
        (table + pos)->print();
    }
    printf("------------------------------------------\n");
}
