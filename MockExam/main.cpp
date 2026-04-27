#include <stdio.h>
#include <string.h>
#include "Protocol.h"

FILE * fp;

int main() {


    fopen_s(&fp, "Candidates.txt", "r");
    if(!fp)
        return -1;

    unsigned num, countVotes;
    char name1[S];
    char name2[S];
    CandidatePair pair;
    Protocol protocol1("Sofia", 313, "Ivan");
    Protocol protocol2("Plovdiv", 314, "Kaloyan");

    do{

        fscanf(fp, "%u %s %s %u", &num, name1, name2, &countVotes);
        pair = CandidatePair(num, name1, name2, countVotes);
        protocol1.addPair(&pair); 
        protocol2.addPair(&pair);
    }while(!feof(fp));

    fclose(fp);

    Protocol protocol3 = protocol1 + protocol2;
    protocol1.setVote(33, 8);
    protocol1.setVote(40, 2090);

    protocol1.print();
    protocol2.print();
    protocol3.print();
    
    printf("Max Votes number: %u\n", protocol1.findPollingPlace());

    return 0;
}
