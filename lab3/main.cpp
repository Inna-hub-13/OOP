
#include "classes.h"

int main() {

    Client cl1("Yana", "Deleva", 1011);
    cl1.addAccount("spestovna", "908765", 1500);
    cl1.addAccount("osiguritelna", "907246", 15000);

    Client cl2 = Client("Petar", "Gerov", 1100);
    cl2.addAccount("spestovna", "808765", 2000);
    cl2.addAccount("osiguritelna", "807246", 50000);
    cl2.addAccount("osiguritelna", "807241", 50000);

    Client cl3 = Client("Ivana", "Ganeva", 1101);
    cl3.addAccount("spestovna", "708765", 200000);
    cl3.addAccount("osiguritelna", "707246", 37000);
    cl3.addAccount("osiguritelna", "707241", 368338);

    Client cl4 = Client("Stefani", "Razkolnikova", 1001);
    cl4.addAccount("spestovna", "608765", 9000000);
    cl4.addAccount("osiguritelna", "607241", 9008338);

    Client cl5 = cl2;

    Bank myBank = Bank(4);

    myBank.addClient(cl1);
    myBank.addClient(cl2);
    myBank.addClient(cl3);
    myBank.addClient(cl4);
    myBank.addClient(cl5);

    myBank.print();
    myBank.deleteClient(1100);

    myBank.print();
    return 0;
}
