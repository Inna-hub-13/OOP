#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime> 
#include "robber.h"

void Robber::setRobber(char* nameRobber, double ratingRobber, bool isInPrisonRobber){

    strcpy(name, nameRobber);
    rating = ratingRobber;
    isInPrison = isInPrisonRobber;
}

void Robber::print(){

    printf("\n\n******************************\n");
    printf("Rober name: %s\n", name);
    printf("Rober rating: %.2lf\n", rating);
    printf("Robber is in prison: %d\n", isInPrison);
    printf("******************************\n");
}

double RobberGang::calcHowMuchCanSteal(){

    howMuchCanSteal = 0;
    int i;
    for(i = 0; i < numberOfRobbers; i++)
        if((robbers + i)->isInPrison == false)
            howMuchCanSteal += (robbers + i)->rating;
    
    howMuchCanSteal *= 0.8;
    return howMuchCanSteal;
}


RobberGang::RobberGang(){

    size = 2;
    numberOfRobbers = 0;
    robbers = new Robber[size];
    howMuchCanSteal = calcHowMuchCanSteal();
}

int RobberGang::add(char* name, double rating, bool isInPrison){

    if(numberOfRobbers == size){

        // Gang needs resizing!
        Robber* newRobbers = new Robber[size * 4];
        if(!newRobbers){

            printf("Can not add new robber!\n");
            return -1;
        }

        int i;
        for(i = 0; i < numberOfRobbers; i++)
            *(newRobbers + i) = *(robbers + i);
        
        size = size * 4;;
        delete[] robbers;
        robbers = newRobbers;
        newRobbers = nullptr;
    }

    (robbers + numberOfRobbers)->setRobber(name, rating, isInPrison);
    numberOfRobbers++;
    return 0;
}

void RobberGang::goToPrison(){

    // The robber with the highest rating goes to prison!

    int i, pos;
    double currentHighest = 0;
    for(i = 0, pos = 0; i< numberOfRobbers; i++)
        if((robbers + i)->rating > currentHighest && !((robbers + i)->isInPrison)){

            currentHighest = (robbers + i)->rating;
            pos = i;
        }
    
    (robbers + pos)->isInPrison = true;
    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);
    (robbers + pos)->print();
    printf("Went to prison at %d:%d:%d!\n", datetime.tm_hour, datetime.tm_min, datetime.tm_sec);
}

void RobberGang::printRobbersInPrison(){

    printf("\n\nRobbers in prison:");
    int i;
    for(i = 0; i < numberOfRobbers; i++)
        if((robbers + i)->isInPrison)
            (robbers + i)->print();
}

void RobberGang::rob(char* name, double rating){

    goToPrison();
    add(name, rating, false);
}

void RobberGang::print(){

    printf("\n\n---------------------------------\n");
    printf("This band can steal: %.2lf\n", calcHowMuchCanSteal());

    int i;
    for(i = 0; i < numberOfRobbers; i++)
        (robbers + i)->print();

    printf("\n---------------------------------");
}

RobberGang::~RobberGang(){

    delete[] robbers;
}
