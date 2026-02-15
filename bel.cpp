#include <stdio.h>
#include <string.h>

#define EOT - 1

struct BelRow{

    char Name[12];
    char Fam[15];
    unsigned long Tel;
};

class Bel {

    BelRow Table[100];
    int TableEnd;
    int CurrentRecord;
    public:
    Bel(void);
    int Append(char *Name, char *Fam, unsigned long Tel);
    void First();
    void Last();
    int Next();
    int Prev();
    BelRow* Get();
};

Bel::Bel(void){

    TableEnd = 0;
}

int Bel::Append(char *Name, char *Fam, unsigned long Tel){

    if(TableEnd>=100) return 0;
    strcpy(Table[TableEnd].Name, Name);
    strcpy(Table[TableEnd].Fam, Fam);
    Table[TableEnd].Tel = Tel;
    TableEnd++;
    return 1;
}

void Bel::First(){
    CurrentRecord=0;
}

void Bel::Last(){
    CurrentRecord=TableEnd-1;
}

int Bel::Next(){

    if(CurrentRecord == TableEnd - 1)
        return EOT;
    
    CurrentRecord++;
    return CurrentRecord;
}

int Bel::Prev(){

    if(CurrentRecord == 0)
        return EOT;
    
    CurrentRecord--;
    return CurrentRecord;
}


BelRow* Bel::Get(){

    return &Table[CurrentRecord];
}


int main() {

    Bel Tef;
    BelRow * Arrow;
    Tef.Append("Tanq", "Petrova", 3427182);
    Tef.Append("Stefan", "Gerov", 3352771);
    Tef.Append("Lena", "Teneva", 1012921);
    Tef.Append("Petq", "Kanewa", 3490182);
    Tef.Append("Stefan", "Georgiev", 8373623);

    Tef.First();
    do{

        Arrow=Tef.Get();
        printf("Name:%s\tFam:%s\tTel:%lu\n", Arrow->Name, Arrow->Fam, Arrow->Tel);

    }while(Tef.Next()!=EOT);
}