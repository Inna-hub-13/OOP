#include <stdio.h>
#include <string.h>
#include "header.h"

CinemaRoom::CinemaRoom(){

   setCinema();
}

void CinemaRoom::print() {

    int i, j;
    for(i = 0; i<MAXROW; i++){

        for(j = 0; j < MAXCOL; j++)
            printf("%c ", *(*(seats + i) + j));

        printf("\n");
    }

    printf("\n");
}

bool CinemaRoom::seatIsFree(unsigned row, unsigned col){

    if (*(*(seats + row) + col) == '0')
        return true;

    return false;
}

void CinemaRoom::setCinema() {

    int i, j;
    for(i = 0; i<MAXROW; i++)
        for(j = 0; j < MAXCOL; j++)
            *(*(seats + i) + j) = '0';
        

    numberOfSoldtickets = 0;
}

Film::Film(char* fName, char* fGenre, unsigned fReleaseYear, double fPrice){

    strcpy(name, fName);
    strcpy(genre, fGenre);
    releaseYear = fReleaseYear;
    price = fPrice;
}

void Film::print(){

    printf("\n************  %s  ************\n", name);
    printf("Genre: %s\n", genre);
    printf("Price: %.2lf$\n", price);
    printf("Release year: %u\n", releaseYear);
    printf("\n");
}


void Ticket::setTicket(char* tDate, Film* tFilm){

    if(cr->numberOfSoldtickets == MAXROW * MAXCOL){

        rowNumber = -1;
        seatNumber = -1;
        film = NULL;
        price = 0;
        strcpy(date, "00.00 0000");
        return;
    }

    int counter = 1;
    unsigned row = -1, seat = -1;
    cr->print();

    do{
        printf("%d)Enter valid row number:\n", counter);
        scanf("%u", &row);
        printf("%d)Enter valid seat number:\n", counter);
        scanf("%u", &seat);

        if(cr->seatIsFree(row - 1, seat - 1)){

            rowNumber = row - 1;
            seatNumber = seat - 1;
            film = tFilm;
            price = film->price / 100000;
            strcpy(date, tDate);
            return;
        }

        counter++;

    }while(counter <= 5);

    rowNumber = -1;
    seatNumber = -1;
    film = NULL;
    price = 0;
    strcpy(date, "00.00 0000");
}


Ticket::Ticket(CinemaRoom* cr,char * tDate, Film* tFilm){

   this->cr = cr;
   setTicket(tDate, tFilm);
}

void Ticket::Sell(){

    if(rowNumber == -1)
        printf("Invalid ticket can not be sold!\n\n");
    
    else {

        cr->seats[rowNumber][seatNumber] = '1';
        print();
        printf("Ticket sold for %.2lf! Enjoy the film!\n\n", price);
    }
}

void Ticket::print(){

   printf("\n\n**********************************************************\n");
   printf("**********************************************************\n");
   
   printf("|Film: %s| Genre: %s| Date: %s|\n", film->name, film-> genre, date);
   printf("|Row: %u| Seat: %u| Price: %.2lf|\n", rowNumber, seatNumber, price);

   printf("**********************************************************\n");
   printf("**********************************************************\n\n");
}


StudentTicket::StudentTicket(CinemaRoom* cr,char * tDate, Film* tFilm):Ticket(cr, tDate, tFilm)
{


}


void StudentTicket::changePrice() {

    price = price - price * 0.2;
}

void StudentTicket::Sell(){

    changePrice();
    
    // Method is the same as in base class
    // Can it be invoked from the derived class?? (28.03 2026)
    if(rowNumber == -1)
        printf("Invalid ticket can not be sold!\n\n");
    
    else {

        cr->seats[rowNumber][seatNumber] = '1';
        print();
        printf("Ticket sold for %.2lf! Enjoy the film!\n\n", price);
    }
}




GroupTicket::GroupTicket(CinemaRoom* cr, char * tDate, Film* tFilm, unsigned groupNumber)
:Ticket(cr, tDate, tFilm){

    if(groupNumber > MAXGROUP)
        this->groupNumber = 1;
    else
        this->groupNumber = groupNumber;
}

void GroupTicket::changePrice() {

    if(groupNumber >= 10)
        price = price - price * 0.1;
    else if(groupNumber >= 20)
        price = price - price * 0.2;
}

void GroupTicket::Sell(){

    changePrice();

     if(rowNumber == -1)
        printf("Invalid ticket can not be sold!\n\n");
    
    else {
        
        cr->seats[rowNumber][seatNumber] = '1';
        print();
        printf("Ticket sold for %.2lf! Enjoy the film!\n\n", price);
    }
}

int main() {


    Film f1 = {"1917", "drama", 2019, 10000000};
    f1.print();

    CinemaRoom cf1;

    Ticket t1(&cf1, "28.04 2026", &f1);
    t1.Sell();
    Ticket t2(&cf1, "28.04 2026", &f1);
    t2.Sell();
    StudentTicket st1(&cf1, "28.04 2026", &f1);
    st1.Sell();

    int groupCount = 0;
    printf("Enter group number: ");
    scanf("%d", &groupCount);
    GroupTicket gt1(&cf1, "28.04 2026", &f1, groupCount);
    gt1.Sell();

    cf1.print();

    return 0;
}
