#define MAX 5

class BankAccount{

    char accType[15];
    char IBAN[11];
    double amount;

    public:
    BankAccount();
    char* getIBAN();
    double getAmount();
    void print();
    void setAccount(char*, char*, double);
    void setAmount(double);
    BankAccount& operator = (BankAccount&);
};

class Client{

    char firstName[15];
    char lastName[20];
    int numberOfBankAccs;
    int clientID;
    BankAccount bankAccounts[MAX];

    public:
    Client();
    Client(char*, char*, int);
    Client(Client&);
    void setClient(char*, char*, int, int);
    int addAccount(char*, char*, double);
    int searchAcc(char*);
    int delAcc(char*);
    int addAmount(char*, double);
    int getID();
    double sumAmmounts();
    void print();
    Client& operator = (Client&);
};

class Fibonacci {

    int f1;
    int f2;

public:
    Fibonacci();
    // Returns the next Fibonacci number
    int Get();
    // Returns the second to next Fibonacci number
    int Set(int);
};

class Bank{

    int tableEnd;
    Fibonacci fNumber;
    int size;
    Client* table;

    public:
    Bank();
    Bank(int);
    ~Bank();
    int addClient(Client&);
    int deleteClient(int);
    void print();

};
