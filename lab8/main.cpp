#include <stdio.h>
#include <string.h>
#include "DihotTable.h"

FILE* fp;

int main() {

    LexUnit l1;
    char iden[S];
    char typ[S];

    fopen_s(&fp, "des.txt", "r");

    DihotTable table = DihotTable();

    do{

        fscanf(fp, "%s %s", iden, typ);
        *(typ  + strlen(typ) - 1) = '\0';
        l1 = LexUnit(iden, typ);
        // Invalid element not added to table
        if(l1.getAddress() != 10000000)
            table.Add(&l1);
    }while(!feof(fp));

    table.print();
    table.Delete("b");
    table.Delete("e");
    table.print();

    fclose(fp);
    return 0;
}
