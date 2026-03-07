#include <stdio.h>
#include <string.h>
#include "classes.h"

BankAccount::BankAccount(){

    strcpy_s(accType, "spestovna");
    strcpy_s(IBAN, "1198765");
    amount = 0;
}

void BankAccount::setAccount(char* accType, char* iban, double am){

    strcpy_s(this->accType, accType);
    strcpy_s(IBAN, iban);
    amount = am;
}

void BankAccount::setAmount(double newAmount){

    amount = newAmount;
}

BankAccount& BankAccount::operator = (BankAccount& ba){

    setAccount(ba.accType, ba.IBAN, ba.amount);
    return *this;
}

char* BankAccount::getIBAN(){

    return IBAN;
}

double BankAccount::getAmount() {

    return amount;
}

void BankAccount::print(){

    printf("\nAcount type: %s\n", accType);
    printf("IBAN: %s\n", IBAN);
    printf("Amount: %lf\n\n", amount);
}

void Client::setClient(char* fName, char* lName, int numBankAccs, int ID) {

    strcpy_s(firstName, fName);
    strcpy_s(lastName, lName);
    numberOfBankAccs = numBankAccs;
    clientID = ID;
}

Client::Client(){

    setClient("Ivan", "Ivanov", 0, 1010);
    clientID += 10;
}

Client::Client(char* fName, char* lName, int clientID){

    setClient(fName, lName, 0, clientID);
}

Client::Client(Client& client){

    setClient(client.firstName, client.lastName, client.numberOfBankAccs, client.clientID);

    int i;
    for(i = 0; i < numberOfBankAccs; i++)
        *(bankAccounts + i) = *(client.bankAccounts + i);
}

void Client::print() {

    printf("\n***********************\n");

    printf("First name: %s\n", firstName);
    printf("Last name: %s\n", lastName);
    printf("Number of bank accounts: %d\n", numberOfBankAccs);
    printf("ClientId: %d\n", clientID);

    int i;
    for(i = 0; i < numberOfBankAccs; i++)
        (bankAccounts+i)->print();

    printf("\n***********************\n");
}

int Client::addAccount(char* type, char* iban, double amount){

    if(numberOfBankAccs >= MAX)
        return -1;

    (bankAccounts + numberOfBankAccs)->setAccount(type, iban, amount);
    return ++numberOfBankAccs;
}

int Client::searchAcc(char* iban){

    int pos;
    for(pos = 0; pos < numberOfBankAccs; pos++)
        if(strcmp((bankAccounts+pos)->getIBAN(), iban) == 0)
            return pos;
    
    return -1;
}

int Client::delAcc(char* iban){

    int pos = searchAcc(iban);
    if(pos == -1)
        return -1;

    int i;
    for(i = pos; i < numberOfBankAccs - 1; i++)
        *(bankAccounts+i) = *(bankAccounts + i + 1);
    
    numberOfBankAccs--;
    return 1;
}

int Client::addAmount(char* iban, double amount){

    int pos = searchAcc(iban);
    if(pos == -1)
        return -1;

    double newAmount = (bankAccounts + pos)->getAmount() + amount;
    (bankAccounts + pos)->setAmount(newAmount);

    return 0;
}

double Client::sumAmmounts(){

    int i;
    double sum = 0;

    for(i = 0; i < numberOfBankAccs; i++)
        sum += (bankAccounts)->getAmount();
    
    return sum;
}

int Client::getID(){

    return clientID;
} 

Client& Client::operator = (Client& client){

    setClient(client.firstName, client.lastName, client.numberOfBankAccs, client.clientID);

    int i = 0;

    for(; i < numberOfBankAccs; i++)
        *(bankAccounts + i) = *(client.bankAccounts + i);

    return *this;
}

Bank::Bank(){

    tableEnd = 0;
    size = fNumber.Get();
    table = new Client[size];
}

Bank::Bank(int size){

    tableEnd = 0;
    this->size = fNumber.Set(size);
    table = new Client[size];
}

Bank::~Bank(){

    delete[] table;
}

int Bank::addClient(Client& client) {

    if (size == tableEnd) {

        printf("Bank needs resizing!\n");
        int newSize = fNumber.Set(size);
        Client* tableNew = new Client[newSize];
        if (!tableNew)
            return -1;

        int i;
        for (i = 0; i < size; i++)
            *(tableNew + i) = *(table + i);

        delete[] table;
        table = tableNew;
        tableNew = nullptr;
        size = newSize;
    }

    *(table + tableEnd) = client;
    tableEnd++;
    return 0;

}

int Bank::deleteClient(int clientID){

    printf("Invoking deleteClient().\nTrying to find client with clientID: %d\n", clientID);
    int i = 0, pos = 0;

    for(;i < tableEnd; i++)
        if((table + i)->getID() == clientID){

            pos = i;
            i = tableEnd + 1; // to terminate for loop
        }
    
    if(pos == 0)
        return -1;
    
    for(i = pos; i < tableEnd - 1; i++)
        *(table + i) = *(table + i + 1);
    
    tableEnd --;
    return 0;
}

void Bank::print(){

    printf("\n\nBank with size %d has clients %d:\n\n", size, tableEnd);
    int i = 0;
    for(; i < tableEnd; i++)
        (table + i)->print();
    printf("\n\n");

}

Fibonacci::Fibonacci() {

    f1 = 1;
    f2 = 1;
}

int Fibonacci::Get() {

    int nextFibonacci = f1 + f2;
    f1 = f2;
    f2 = nextFibonacci;
    return nextFibonacci;
}

int Fibonacci::Set(int size) {

    if (size < f2)
        return f2;

    while (size >= Get());

    return Get();
}
