#include "LexUnit.h"

class DesTable{

    LexUnit* table;
    int length;
    int capacity;

    // Resizes the table, doubling the original size
    int resize();

    public:
    DesTable();
    ~DesTable();

    int LinearSearch(char*);
    int AddAtEnd(LexUnit*);
    int Delete(char*);
    void print();
};