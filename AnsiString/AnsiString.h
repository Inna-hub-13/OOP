#include <stdio.h>

class AnsiString{

    char* s;
    unsigned size;
    public:
    AnsiString(){s = NULL; size = 0;}
    void setAnsiString(char* si);
    AnsiString(char* si);
    AnsiString(AnsiString& as);
    ~AnsiString(){printf("Destructor invoked\n");delete s; s = NULL;}
    AnsiString& operator=(AnsiString& as);
    AnsiString operator+(AnsiString& as);
    void print();
};
