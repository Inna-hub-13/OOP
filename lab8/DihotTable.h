#include "LexUnit.h"

class DihotTable{

    LexUnit* table;
    int length;
    int capacity;

    // Resizes the table, doubling the original size
    int resize();

    public:
    DihotTable();
    ~DihotTable();

    int BinarySearch(char*);
    int Add(LexUnit*);
    int Delete(char*);
    void print();
};