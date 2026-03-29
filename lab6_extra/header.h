#define STRSIZE 30
#define MAXROW 10
#define MAXCOL 16
#define MAXGROUP 25


struct Film{

    
    char name[STRSIZE];
    char genre[STRSIZE];
    unsigned releaseYear;
    double price;
    Film(char*, char*, unsigned, double);
    void print();
};

struct CinemaRoom{

  
    char seats[MAXROW][MAXCOL];
    unsigned numberOfSoldtickets;
    CinemaRoom();
    void print();
    bool seatIsFree(unsigned, unsigned);

    private:
    void setCinema();
};

class Ticket{

    protected:
    int rowNumber;
    int seatNumber;
    // Date in format 28.03 2026
    char date[11];
    double price;
    Film* film;
    CinemaRoom* cr;

    void setTicket(char*, Film*);

    public:
    // If ticket has rowNumber = -1, seatNumber = -1, invalid ticket is created
    // In this case it can't be sold
    Ticket(CinemaRoom*, char*, Film*);
    virtual void Sell();
    void print();
};

class StudentTicket:public Ticket{

    private:
    // Price for student ticket is 20% lower
    void changePrice();

    public:
    StudentTicket(CinemaRoom* ,char *, Film*);
    void Sell();
};

class GroupTicket:public Ticket{

    private:
    int groupNumber;
    void changePrice();

    public:
    GroupTicket(CinemaRoom* ,char * , Film*, unsigned);
    void Sell();
};