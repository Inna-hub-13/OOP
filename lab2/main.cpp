#include <stdio.h>
#include "classes.h"


int main() {

    Client c1("Mariya", "Petrova");
    c1.AddAccount("pensionna", "345675", 3000);
    c1.AddAccount("spestovna", "341275", 6557.95);
    c1.AddAccount("pensionna", "345075", 3000);
    c1.AddAmount("345675", 30);
    c1.print();

    Client c2 = c1;
    c2.print();

    c1.DelAcc("345075");
    c1.print();

    
    c2.DelAcc("1198765");
    c2.DelAcc("1198765");
    c2.DelAcc("1198765");
    c2.print();

    c2.AddAccount("osiguritelna", "897643", 19000.23);
    c2.print();
    printf("\nSum Amount c1: %lf\n", c1.SumAmmounts());
}
