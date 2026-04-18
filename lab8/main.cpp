#include <stdio.h>
#include <string.h>
#include "DesTable.h"

FILE* fp;

int main() {

    LexUnit l1;
    char iden[S];
    char typ[S];

    fopen_s(&fp, "des.txt", "r");

    DesTable table = DesTable();

    do{

        fscanf(fp, "%s %s", iden, typ);
        *(typ  + strlen(typ) - 1) = '\0';
        l1 = LexUnit(iden, typ);
        table.AddAtEnd(&l1);
    }while(!feof(fp));

    table.print();

    fclose(fp);
    return 0;
}
