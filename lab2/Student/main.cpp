#include <stdio.h>
#include "student.h"

FILE* fp;

int main() {

    Group group;

    fp = fopen("D:\\Inna\\OOP\\lab2_extra\\Student\\students.txt", "r");

    if(!fp){

        printf("Can't open file!\n");
        return -1;
    }
        
    int help1;
    char help2[40];
    double help3;

    do{
        fscanf(fp, "%d %s %lf\n", &help1, help2, &help3);
        group.addStudent(help1, help2, help3);
    }while(!feof(fp));
    
    group.print();

    group.findMaxScore();
    group.findMinScore();
    group.printStudent(382334);
    group.printStudent(381034);

    double avg = group.avgScore();
    printf("avg of this group is: %.2lf\n\n", avg);

    printf("Invoking group.sortAscFacNum()\n");
    group.sortAscFacNum();

    group.print();

    printf("Invoking group.sortAscScore()\n");
    group.sortAscScore();

    group.print();


    fclose(fp);
    return 0;
}
