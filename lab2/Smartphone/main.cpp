#include <stdio.h>
#include <stdlib.h>
#include "smartphone.h"

FILE* fp;

int compr(const void* v1, const void* v2) {

    Smartphone* s1 = (Smartphone*)v1;
    Smartphone* s2 = (Smartphone*)v2;

    if (s1->getPrice() > s2->getPrice())
        return 1;
    else if (s1->getPrice() == s2->getPrice())
        return 0;
    else
        return -1;
}

int main() {

    Smartphone* smartphones;
    char help1[20];
    char help2[20];
    double help3;

    int count = 0;

    fp = fopen("D:\\Inna\\OOP\\lab2_extra\\Smartphone\\smartphones.txt", "r");

    if (!fp)
        return -1;

    do {

        fscanf(fp, "%s %lf %s\n", help1, &help3, help2);
        count++;
    } while (!feof(fp));

    printf("\ncount is: %d\n", count);

    smartphones = new Smartphone[10];

    if (!smartphones) {

        printf("Problem with allocating memory for smartphones!\n");
        fclose(fp);
        return -1;
    }

    fseek(fp, 0L, SEEK_SET);
    count = 0;

    do {

        fscanf(fp, "%s %lf %s\n", help1, &help3, help2);
        *(smartphones + count) = Smartphone(help1, help3, help2);
        count++;
    } while (!feof(fp));

    int i = 0;

    for (; i < count; i++)
        (smartphones + i)->print();

    printf("After invoking qsort()...\n");
    qsort(smartphones, count, sizeof(Smartphone), compr);
  
    i = 0;

    for (; i < count; i++)
        (smartphones + i)->print();


    delete[] smartphones;
    smartphones = nullptr;
    fclose(fp);
    return 0;
}
