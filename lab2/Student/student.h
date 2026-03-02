
#define MAX 30

class Student{

    int facNum;
    char name[40];
    double score;

    public:
    Student();
    Student(int, char*, double);
    Student(Student&);
    void setStudent(int, char*, double);
    int getFacNum();
    double getScore();
    char* getName();
    void print();
    Student& operator = (Student&);
};

class Group{

    Student students[MAX];
    int tableEnd;

    public:
    Group();
    Group(int, Student*);
    void setGroup(int, Student*);
    int addStudent(int, char*, double);
    double avgScore();
    void findMaxScore();
    void findMinScore();
    void printStudent(int);
    void print();
    void sortAscFacNum();
    void sortAscScore();
};

