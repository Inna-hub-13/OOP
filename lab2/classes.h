#define MAX 5

class BankAccount {

    char acc_type[15];
    char IBAN[11];
    double amount;

public:
    BankAccount();
    char* GetIBAN();
    double GetAmount();
    void print();
    void SetAccount(const char*,const char*, double);
    void SetAmount(double);
};

class Client {

    char first_name[15];
    char last_name[20];
    int number_of_bank_accs;
    BankAccount bank_accounts[MAX];

public:
    static int client_id;
    Client();
    Client(const char*,const char*);
    Client(Client&);
    int AddAccount(const char*,const char*, double);
    int SearchAcc(const char*);
    int DelAcc(const char*);
    int AddAmount(const char*, double);
    double SumAmmounts();
    void print();
};