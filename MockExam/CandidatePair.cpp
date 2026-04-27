#include <stdio.h>
#include <string.h>
#include "CandidatePair.h"

void CandidatePair::set(unsigned n, char* presidentName, char* vicePresidentName, unsigned votes){

    num = n;
    strcpy(president, presidentName);
    strcpy(vicePresident, vicePresidentName);
    countVotes = votes;
}

CandidatePair::CandidatePair() {

    set(0, "Ivan", "Ivan", 0);
}

CandidatePair::CandidatePair(unsigned n, char* presidentName, char* vicePresidentName, unsigned votes){

    set(n, presidentName, vicePresidentName, votes);
}

CandidatePair& CandidatePair::operator=(CandidatePair& cP){

    set(cP.num, cP.president, cP.vicePresident, cP.countVotes);
    return *this;
}

void CandidatePair::print(){

    printf("%u\t\t%s\t\t\t%s\t\t\t%u\n", num, president, vicePresident, countVotes);
}
