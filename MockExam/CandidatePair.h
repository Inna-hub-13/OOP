#pragma once
#define S 20

class CandidatePair{

    unsigned num;
    char president[S];
    char vicePresident[S];
    unsigned countVotes;

    public:
    void set(unsigned, char*, char*, unsigned);
    CandidatePair();
    CandidatePair(unsigned, char*, char*, unsigned);
    CandidatePair& operator=(CandidatePair&);
    unsigned getVotes(){return countVotes;}
    void setVotes(unsigned updatedVotes){countVotes += updatedVotes;}
    unsigned getNum(){return num;}
    void print();
};