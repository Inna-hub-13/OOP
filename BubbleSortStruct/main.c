#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define N 16
#define M 5

typedef struct Film{

    char name[N];
    int releaseYear;
    int price;
}Film;

typedef unsigned char byte;

int cmp_price(byte* el1, byte* el2);
int cmp_year(byte* el1, byte* el2);
void BubbleSort(byte* base, int nren, int reclen, int(*cmp)(byte* el1, byte* el2));
void print(const Film*, int);

int main() {

    Film films[M];

    Film f1 = {"Titanic", 1999, 10};
    Film f2 = {"Skyfall", 2012, 20};
    Film f3 = {"Sleepover", 2004, 5};
    Film f4 = {"Bridesmaids", 2011, 10};
    Film f5 = {"Liar Liar", 1997, 4};

    films[0] = f1;
    films[1] = f2;
    films[2] = f3;
    films[3] = f4;
    films[4] = f5;

    print(films, M);

    BubbleSort((byte*)films, M, sizeof(Film), cmp_year);

    printf("\n\nBubbleSort for release year:\n");
    print(films, M);

    BubbleSort((byte*)films, M, sizeof(Film), cmp_price);

    printf("\n\nBubbleSort for price:\n");
    print(films, M);

    return 0;
}

int cmp_price(byte* el1, byte* el2){

    return (*((int*)(el1 + 20)) > *((int*)(el2 + 20)) ? 1 : 0);
}

int cmp_year(byte* el1, byte* el2){

   return (*((int*)(el1 + 16)) > *((int*)(el2 + 16)) ? 1 : 0);
}

void BubbleSort(byte* base, int nrec, int reclen, int(*cmp)(byte* el1, byte* el2)){


    int i, j, flag;
    byte* help = (byte*)calloc(1, reclen);

    if(!help)
        return;

    for(i = 0, flag = 1; flag; i++){

        flag = 0;
        for(j = 0; j < nrec - i - 1; j++)
            if((*cmp)(base + j * reclen, base + (j + 1) * reclen)){

                memcpy_s(help, reclen, base + j * reclen, reclen);
                memcpy_s(base + j * reclen, reclen, base + (j + 1) * reclen, reclen);
                memcpy_s(base + (j + 1)*reclen, reclen, help, reclen);
                flag = 1;
            }
        
    }

    free(help);
}

void print(const Film* films, int nrec){


    int i;
    for(i = 0; i < nrec; i++)
        printf("name: %s; release year: %d; price: %d\n", (films + i)->name, 
        (*(films + i)).releaseYear, (films + i)->price);
    
}
