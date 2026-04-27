#define M 24
#define N 20
#include "CandidatePair.h"

class Protocol{

    char region[N];
    unsigned numSection;
    char predName[N];
    // Sorted acssending by num
    CandidatePair table[M];
    unsigned countAllVotes;
    int countAdded;

    public:
    Protocol();
    Protocol(char*, unsigned, char*);
    int addPair(CandidatePair*);
    void setVote(int, unsigned);
    int findPollingPlace();
    Protocol operator+(Protocol&);
    void print();
};