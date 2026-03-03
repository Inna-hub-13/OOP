
struct Robber{

    char name[30];
    double rating;
    bool isInPrison;

    void setRobber(char*, double, bool);
    void print();
};

class RobberGang{

    Robber* robbers;
    int size;
    int numberOfRobbers;
    double howMuchCanSteal;

    public:
    RobberGang();
    ~RobberGang();
    int add(char*, double, bool);
    double calcHowMuchCanSteal();
    void goToPrison();
    void rob(char*, double);
    void printRobbersInPrison();
    void print();
};

