#include <string.h>
#include "AnsiString.h"


void AnsiString::setAnsiString(char* si){

    size = strlen(si);
    s = new char[size + 1];
    strcpy(s, si);
}

AnsiString::AnsiString(char* si){

    setAnsiString(si);
}

AnsiString::AnsiString(AnsiString& as){

    setAnsiString(as.s);
}

AnsiString& AnsiString::operator=(AnsiString& as){

    if(s) delete s;
    setAnsiString(as.s);
    return *this;
}

AnsiString AnsiString::operator+(AnsiString& as){

    AnsiString tempAnsi;
    tempAnsi.size = size + as.size;
    tempAnsi.s = new char[tempAnsi.size + 1];
    strcpy(tempAnsi.s, s);
    strcat(tempAnsi.s, as.s);
    return tempAnsi;
}


void AnsiString::print(){

    printf("\ns: %s\n", s);
    printf("size: %u\n", size);
}


int main() {

    AnsiString s1("Coconut water");
    AnsiString s2(" is delicious");
    AnsiString s3 = s1 + s2;

    printf("s3:");
    s3.print();
    printf("s2:");
    s2.print();
    printf("s1:");
    s1.print();


    return 0;
}