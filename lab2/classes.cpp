#include <stdio.h>
#include <string.h>
#include "classes.h"

BankAccount::BankAccount() {

    strcpy_s(acc_type, "spestovna");
    strcpy_s(IBAN, "1198765");
    amount = 0;
}

void BankAccount::SetAccount(const char* acc_type,const char* iban, double am) {

    strcpy_s(this->acc_type, acc_type);
    strcpy_s(IBAN, iban);
    amount = am;
}

void BankAccount::SetAmount(double new_amount) {

    amount = new_amount;
}

char* BankAccount::GetIBAN() {

    return IBAN;
}

double BankAccount::GetAmount() {

    return amount;
}

void BankAccount::print() {

    printf("\nAcount type: %s\n", acc_type);
    printf("IBAN: %s\n", IBAN);
    printf("Amount: %lf\n\n", amount);
}

int Client::client_id = 1000;

Client::Client() {

    strcpy_s(first_name, "Ivan");
    strcpy_s(last_name, "Ivanov");
    number_of_bank_accs = 0;
    client_id += 10;
}

Client::Client(const char* name,const char* lname) {

    strcpy_s(first_name, name);
    strcpy_s(last_name, lname);
    number_of_bank_accs = 0;
    client_id += 10;
}

Client::Client(Client& client) {

    strcpy_s(first_name, client.first_name);
    strcpy_s(last_name, client.last_name);
    number_of_bank_accs = client.number_of_bank_accs;
    client_id += 10;
}

void Client::print() {

    printf("\n***********************\n");

    printf("First name: %s\n", first_name);
    printf("Last name: %s\n", last_name);
    printf("Number of bank accounts: %d\n", number_of_bank_accs);
    printf("ClientId: %d\n", client_id);

    int i;
    for (i = 0; i < number_of_bank_accs; i++)
        (bank_accounts + i)->print();

    printf("\n***********************\n");
}

int Client::AddAccount(const char* type,const char* iban, double amount) {

    if (number_of_bank_accs >= MAX)
        return -1;

    (bank_accounts + number_of_bank_accs)->SetAccount(type, iban, amount);
    return ++number_of_bank_accs;
}

int Client::SearchAcc(const char* iban) {

    int pos;
    for (pos = 0; pos < number_of_bank_accs; pos++)
        if (strcmp((bank_accounts + pos)->GetIBAN(), iban) == 0)
            return pos;

    return -1;
}

int Client::DelAcc(const char* iban) {

    int pos = SearchAcc(iban);
    if (pos == -1)
        return -1;

    int i;
    for (i = pos; i < number_of_bank_accs; i++)
        *(bank_accounts + i) = *(bank_accounts + i + 1);

    number_of_bank_accs--;
    return 1;
}

int Client::AddAmount(const char* iban, double amount) {

    int pos = SearchAcc(iban);
    if (pos == -1)
        return -1;

    double new_amount = (bank_accounts + pos)->GetAmount() + amount;
    (bank_accounts + pos)->SetAmount(new_amount);
    return 1;
}

double Client::SumAmmounts() {

    int i;
    double sum = 0;

    for (i = 0; i < number_of_bank_accs; i++)
        sum += (bank_accounts + i)->GetAmount();

    return sum;
}