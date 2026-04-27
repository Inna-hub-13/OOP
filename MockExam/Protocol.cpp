#include <stdio.h>
#include <string.h>
#include "Protocol.h"

Protocol::Protocol(char* reg, unsigned nSection, char* pred){

    strcpy(region, reg);
    numSection = nSection;
    strcpy(predName, pred);
    countAllVotes = 0;
    countAdded = 0;
}

Protocol::Protocol(){

    strcpy(region, "");
    numSection = 0;
    strcpy(predName, "");
    countAllVotes = 0;
    countAdded = 0;
}

int Protocol::addPair(CandidatePair* cP){

    if(countAdded >= M)
        return -1;

    
    *(table + countAdded) = *cP;
    countAllVotes += cP->getVotes();
    countAdded++;
    return 0;
}

// Updated votes are possitive additional votes
void Protocol::setVote(int num, unsigned updatedVotes){

    int i;
    for(i = 0; i < countAdded; i++)
        if((table + i)->getNum() == num){

            (table + i)->setVotes(updatedVotes);
            countAllVotes += updatedVotes; 
            return;
        }
}

int Protocol::findPollingPlace(){

    if(countAdded == 0)
        return 0;

    int i, maxPos = 0;
    for(i = 1; i < countAdded; i++)
        if((table + i)->getVotes() > (table + maxPos)->getVotes())
            maxPos = i;
    
    return (table + maxPos)->getNum();
}

Protocol Protocol::operator+(Protocol& prot){

    Protocol temp;
    int i, j;
    for(i = 0; i < countAdded; i++)
        temp.table[i] = *(table + i);

    temp.countAdded = countAdded;
    
    for(i = 0, j = countAdded; i < prot.countAdded && temp.countAdded < M; i++, j++, temp.countAdded++)
        temp.table[j] = prot.table[i];

    if(strcmp(region, prot.region) == 0)
        strcpy(temp.region, region);
    else 
        sprintf(temp.region, "%s-%s\0", region, prot.region);
    
    if(strcmp(predName, prot.predName) == 0)
        strcpy(temp.predName, predName);
    else 
        sprintf(temp.predName, "%s-%s\0", predName, prot.predName);
    
    temp.numSection = numSection + prot.numSection;
    temp.countAllVotes = countAllVotes + prot.countAllVotes;

    return temp;
}

void Protocol::print() {

    printf("\n=============================\n");
    printf("Region: %s\n", region);
    printf("Section number: %u\n", numSection);
    printf("Pred: %s\n", predName);
    printf("All votes: %u\n", countAllVotes);
    printf("\n=============================\n");
    printf("\nNumber\t\tPresident\t\tVice-President\t\tVotes\n");

    int i;
    for(i = 0; i < countAdded; i++)
        (table + i)->print();

    printf("\n");

}