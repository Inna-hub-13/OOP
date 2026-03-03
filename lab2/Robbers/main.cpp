#include "robber.h"

int main() {

    RobberGang gang;
    gang.print();

    gang.add("Glupcho 1", 1, false);
    gang.add("Glupcho 2", 3, false);
    gang.add("Glupcho 3", 2, false);
    gang.add("Glupcho 4", 1, false);
    gang.add("Glupcho 5", 2.5, false);
    gang.add("Glupcho 6", 1, false);


    gang.print();

    gang.rob("Glupcho 7", 3);
    gang.rob("Glupcho 8", 1);
    gang.printRobbersInPrison();

    gang.print();

    return 0;
}
