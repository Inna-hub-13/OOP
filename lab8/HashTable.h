#define L 128
#include "LexUnit.h" 

class HashTable{

    LexUnit table[L];

    public:
    HashTable(){};
    int HashFunction(char*);
    int Search(char*);
    int Add(LexUnit&);
    int Delete(char*);
    void print();
};