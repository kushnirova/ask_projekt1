#include <windows.h>
#include<stdio.h>
#include <conio.h>

void menu(){
    int opcja, k, typ;
    printf("\n 1. Wydrukowac postac binarna liczby");
    printf("\n 2. Wydrukowac postac bajtowa liczby");
    printf("\n 3. Zaprezentowac zasady odejmowania liczb w U2");
    printf("\n 4. Zaprezentowac konwersje FLOAT -> DECIMAL lub DECIMAL -> FLOAT \n");

    do {
        printf("\n Podaj opcje: ");
        k=scanf("%d",&opcja);
        if(k==0||opcja<1||opcja>4) printf(" Przy wyborze opcji wystapil blad, sprobuj ponownie");
        while (getchar()!='\n');
    }
    while(k==0||opcja<1||opcja>4);
    system("cls");
    printf("\n");

    if(opcja==1){
        typ=wyboropcji();
        wczytdrukbin(typ);
    }
    if(opcja==2){
        typ=wyboropcji();
        wczytdrukbajt(typ);
    }
    if(opcja==3){
        odejmowanieU2();
    }
    if(opcja==4){
        konwersja();
    }
}

int wyboropcji(){
    int opcja, k;
    printf(" 1. Int");
    printf("\n 2. Float");
    printf("\n 3. Double \n");

    do {
        printf("\n Podaj typ liczby: ");
        k=scanf("%d",&opcja);
        if(k==0||opcja<1||opcja>3) printf(" Przy wyborze opcji wystapil blad, sprobuj ponownie");
        while (getchar()!='\n');
    }
    while(k==0||opcja<1||opcja>3);
    system("cls");
    printf("\n");
    return opcja;
}

void wczytdrukbin(int typ){

    int liczbaINT, k;
    float liczbaFLOAT;
    double liczbaDOUBLE;

    unsigned char *bajtINT = (unsigned char*)&liczbaINT;
    unsigned char *bajtFLOAT = (unsigned char*)&liczbaFLOAT;
    unsigned char *bajtDOUBLE = (unsigned char*)&liczbaDOUBLE;

    if(typ==1){
        do {
            printf("\n Podaj liczbe: ");
            k=scanf("%d",&liczbaINT);
            if (k==0) printf("\n Blad formatu, sprobuj ponownie");
            while(getchar()!='\n');
        }
        while(k==0);
        printf(" Liczba %d w postaci binarnej: ", liczbaINT);

        for(int i=sizeof(liczbaINT)-1; i>=0;i--){
            drukbin(bajtINT[i]);
            printf(" ");
        }
        printf("\n");

    }
    if(typ==2){
        do {
            printf("\n Podaj liczbe: ");
            k=scanf("%f",&liczbaFLOAT);
            if (k==0) printf("\n Blad formatu, sprobuj ponownie");
            while(getchar()!='\n');
        }
        while(k==0);
        printf(" Liczba %f w postaci binarnej: ", liczbaFLOAT);
        for(int i=sizeof(liczbaFLOAT)-1; i>=0;i--){
            drukbin(bajtFLOAT[i]);
            printf(" ");
        }
        printf("\n");
    }
    if(typ==3){
        do {
            printf("\n Podaj liczbe: ");
            k=scanf("%lf",&liczbaDOUBLE);
            if (k==0) printf("\n Blad formatu, sprobuj ponownie");
            while(getchar()!='\n');
        }
        while(k==0);
        printf(" Liczba %lf w postaci binarnej: ", liczbaDOUBLE);
        for(int i=sizeof(liczbaDOUBLE)-1; i>=0;i--){
            drukbin(bajtDOUBLE[i]);
            printf(" ");
        }
        printf("\n");
    }

powrot();
}

void drukbin(unsigned char bajt){
    for(int i=7; i>=0; i--){
        printf("%d", (bajt>>i)&1);
    }
}

void wczytdrukbajt(int typ){

    int liczbaINT, k;
    float liczbaFLOAT;
    double liczbaDOUBLE;

    unsigned char *bajtINT = (unsigned char*)&liczbaINT;
    unsigned char *bajtFLOAT = (unsigned char*)&liczbaFLOAT;
    unsigned char *bajtDOUBLE = (unsigned char*)&liczbaDOUBLE;

    if(typ==1){
        do {
            printf("\n Podaj liczbe: ");
            k=scanf("%d",&liczbaINT);
            if (k==0) printf("\n Blad formatu, sprobuj ponownie");
            while(getchar()!='\n');
        }
        while(k==0);
        printf(" Liczba %d w postaci bajtowej: ", liczbaINT);

        for(int i=sizeof(liczbaINT)-1; i>=0;i--){
            printf("%02x ",bajtINT[i]);
        }
        printf("\n");

    }
    if(typ==2){
        do {
            printf("\n Podaj liczbe: ");
            k=scanf("%f",&liczbaFLOAT);
            if (k==0) printf("\n Blad formatu, sprobuj ponownie");
            while(getchar()!='\n');
        }
        while(k==0);

        printf(" Liczba %f w postaci bajtowej: ", liczbaFLOAT);
        for(int i=sizeof(liczbaFLOAT)-1; i>=0;i--){
            printf("%02x ",bajtFLOAT[i]);
        }
        printf("\n");
    }
    if(typ==3){
        do {
            printf("\n Podaj liczbe: ");
            k=scanf("%lf",&liczbaDOUBLE);
            if (k==0) printf("\n Blad formatu, sprobuj ponownie");
            while(getchar()!='\n');
        }
        while(k==0);
        printf(" Liczba %lf w postaci bajtowej: ", liczbaDOUBLE);
        for(int i=sizeof(liczbaDOUBLE)-1; i>=0;i--){
            printf("%02x ", bajtDOUBLE[i]);
        }
        printf("\n");
    }
powrot();
}

void odejmowanieU2(){
    printf("\n Zasady odejmowania liczb w U2.");
    printf("\n 1 - 1 = 0");
    printf("\n 1 - 0 = 0");
    printf("\n 10 - 1 = 1");
    printf("\n Odejmowanie w U2 dziala tak samo, jak w systemie dziesietnym: jesli nie ma");
    printf("\n od czego odejmowac - 'pozyczamy' u sasiada po lewej.");
    printf("\n     5012      |      1010");
    printf("\n    -  15      |     -0011");
    printf("\n Nie mozemy odjac 5 od 2 (1 od 0) - 'zabieramy' 10 (1) z kolejnego rzedu");
    printf("\n     500 (12)  |      100 (10)");
    printf("\n    -  1   5   |     -001   1");
    printf("\n           7   |            1");
    printf("\n Jesli u sasiada tez za malo - zabieramy u kolejnego");
    printf("\n    49 (10)(12)|       01 (10) (10)");
    printf("\n    -     1  5 |     -    001    1");
    printf("\n        499  7 |       01   1    1");
    powrot();
}

void konwersja(){

    int opcja, k;
    printf("\n 1. Konwersja DEC -> FLOAT");
    printf("\n 2. Konwersja FLOAT -> DEC");

    do {
        printf("\n Podaj opcje: ");
        k=scanf("%d",&opcja);
        if(k==0||opcja<1||opcja>2) printf(" Przy wyborze opcji wystapil blad, sprobuj ponownie");
        while (getchar()!='\n');
    }
    while(k==0||opcja<1||opcja>2);
    system("cls");
    printf("\n");

    if (opcja==1){
        printf(" 1. Konwersja DEC -> FLOAT \n");
        printf("\n    W IEEE74 FLOAT liczba jest przechowywana na 32 bitach:");
        printf("\n    1 bit znaku | 8 bitow cechy | 23 bity mantysy");
        printf("\n    Zalozmy, ze chcemy dokonac konwersji liczby 231.12 \n");
        printf("\n    Krok 1. Jesli liczba jest dodatnia - wpisujemy w bit znaku 0, jesli nie - 1.");
        printf("\n            231.12 - dodatnie, wpisujemy 0");
        printf("\n            0 ________ _______________________");
        printf("\n    Krok 2. Teraz dla wyrazenia liczba / 2^(potega) musimy dobrac taka potege,");
        printf("\n            by wartosc tego wyrazenia byla pomiedzy 1 a 2:");
        printf("\n            231.12 / 2^7 = 1,805625...");
        printf("\n            Do otrzymanej potegi dodajemy 127 (bias dla float):");
        printf("\n            7+127=134 -> 10000110");
        printf("\n            Wynik zapisujemy binarnie do cechy:");
        printf("\n            0 10000110 _______________________");
        printf("\n    Krok 3. Czesc ulamkowa wyniku z kroku 2 musimy zapisac binarnie");
        printf("\n            0,805625... -> 11001110 00111101 0111000 ...");
        printf("\n            0,805625 * 2 | 1,61125 | 1 - wpisujemy pierwsza cyfre po mnozeniu razy 2");
        printf("\n            0,61125  * 2 | 1,2225  | 1 - kiedy po mnozeniu razy 2 otrzymamy liczbe wieksza od 1");
        printf("\n            0,2225   * 2 | 0,445   | 0   odejmujemy od niej jeden");
        printf("\n            0,445    * 2 | 0,89    | 0 ");
        printf("\n            0,89     * 2 | 1,78    | 1");
        printf("\n            ... \n            Kontynujemy, dopoki nie otrzymamy 23 bity");
        printf("\n    Krok 4. Wynik z kroku 3 wpisujemy do mantysy");
        printf("\n            0 10000110 11001110 00111101 0111000");
        printf("\n    Gotowe! \n");
    }
    if (opcja==2){
        printf(" 2. Konwersja FLOAT -> DEC");
        printf("\n    W IEEE74 FLOAT liczba jest przechowywana na 32 bitach:");
        printf("\n    1 bit znaku | 8 bitow cechy | 23 bity mantysy");
        printf("\n    Mozemy skorzystac ze wzoru (-1)^(bit znaku) * (1+mantysa) * 2^(cecha-127)");
        printf("\n    Zalozmy, ze chcemy dokonac konwersji liczby 0 10000110 11001110 00111101 0111000 \n");
        printf("\n    Krok 1. Pierwszy bit jest bitem znaku. 1 - liczba ujemna, 0 - dodatnia.");
        printf("\n            W naszej liczbie piewrszy bit 0 - jest dodatnia");
        printf("\n    Krok 2. Zapisujemy mantyse decymalnie jako czesc ulamkowa:");
        printf("\n            0,11001110 00111101 0111000 -> 0,805625...");
        printf("\n            1*2^(-1)+1*2^(-2)+0*2(-3)+0*2^(-4)+1*2^(-5)+...");
        printf("\n    Krok 3. Od cechy odejmujemy 127 (bias):");
        printf("\n            10000110 -> 134-127=7");
        printf("\n    Krok 4. Do otrzymanego w kroku 2 ulamka dodajemy 1");
        printf("\n            0,805625... + 1 = 1,805625...");
        printf("\n            Otrzymana liczbe mnozymy przez 2^(potega obliczona w kroku 3)");
        printf("\n            1,805625 * 2^7 = 231,12");
        printf("\n            Pamietamy o znaku (krok 1).");
        printf("\n            +231,12");
        printf("\n    Gotowe!");
    }
    powrot();

}

void powrot(){
    printf("\n\n Wcisnij Q zeby wrocic do menu lub inny przycisk zeby skonczyc program\n");
    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch=='q' || ch=='Q') {
                system("cls");
                menu();
                break;
                }
            else break;
        }
    }
}


int main(){
    menu();
    return 0;
}
