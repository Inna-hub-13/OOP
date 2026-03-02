#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void Student::setStudent(int facNum, char* name, double score){

    this->facNum = facNum;
    strcpy(this->name, name);
    this->score = score;
}

Student::Student(){

    setStudent(0000, "Ivan Ivanov", 2);
}

Student::Student(int facNum, char* name, double score) {

    setStudent(facNum, name, score);
}

Student::Student(Student& st) {

    setStudent(st.facNum, st.name, st.score);
}

int Student::getFacNum(){

    return facNum;
}

double Student::getScore(){

    return score;
}

char* Student::getName(){

    return name;
}

Student& Student::operator = (Student& st){

    setStudent(st.facNum, st.name, st.score);
    return *this;
}

void Student::print() {


    printf("\n\n***********************************\n");
    printf("Student name: %s\n", name);
    printf("Faculty number: %d\n", facNum);
    printf("Score: %.2lf\n", score);
    printf("***********************************\n\n");
}

void Group::setGroup(int size, Student* arr){

    if(!arr){
        
        tableEnd = 0;
        return;
    }

    if(size >= MAX){

        printf("Enter an array of students with size less than %d\n", MAX);
        tableEnd = 0;
        return;
    }
    
    tableEnd = size;
    int i;

    for(i = 0; i < tableEnd; i++)
        *(students + i) = *(arr + i);
    
}

Group::Group(){

   tableEnd = 0;
}

Group::Group(int size, Student* arr){

   setGroup(size, arr);
}

double Group::avgScore() {

    double avg = 0;

    int i;
    for(i = 0;i < tableEnd; i++)
        avg += (students + i)->getScore();

    avg = avg / i;
    return avg;
}

int Group::addStudent(int facNum, char* name, double score){

    if(tableEnd>=MAX){

        printf("No more space for students in this group!\n");
        return -1;
    }

    (students + tableEnd)->setStudent(facNum, name, score);

    tableEnd++;
    return 0;
}

void Group::findMaxScore(){

    double currentMin = 6;

    int i, pos = 0;
    for(i = 0; i < tableEnd; i++)
        if((students + i)->getScore() < currentMin){

            currentMin = (students + i)->getScore();
            pos = i;
        }

    printf("Student with lowest score is\n");
    (students + pos)->print();
}


void Group::findMinScore(){
    
    
    double currentMax = 2;

    int i, pos = 0;
    for(i = 0; i < tableEnd; i++)
        if((students + i)->getScore() > currentMax){

            currentMax = (students + i)->getScore();
            pos = i;
        }

    printf("Student with highest score is\n");
    (students + pos)->print();
}

void Group::printStudent(int facNum){

    int i;
    for(i = 0; i < tableEnd; i++)
        if((students + i)->getFacNum() == facNum){

            printf("Student with faculty number <%d> found!\n", facNum);
            (students + i)->print();
            return;
        }
    
    printf("Student with faculty number <%d> not found!\n", facNum);

}

void Group::print(){

    printf("Group with %d students\n", tableEnd);
    int i;

    for(i = 0; i < tableEnd; i++)
        (students + i)->print();
}

int compAscFacNums(const void * v1, const void *v2){

    Student*s1 = (Student*)v1;
    Student*s2 = (Student*)v2;

    if(s1->getFacNum() > s2->getFacNum())
        return 1;
    else if(s1->getFacNum() == s2->getFacNum())
        return 0;
    else 
        return -1;
}

int compAscScores(const void * v1, const void *v2){

    Student*s1 = (Student*)v1;
    Student*s2 = (Student*)v2;

    if(s1->getScore() > s2->getScore())
        return 1;
    else if(s1->getScore() == s2->getScore())
        return 0;
    else 
        return -1;
}

void Group::sortAscFacNum(){

    qsort(students, tableEnd, sizeof(Student), compAscFacNums);
}

void Group::sortAscScore(){

    qsort(students, tableEnd, sizeof(Student), compAscScores);
}