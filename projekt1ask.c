#include<stdio.h>

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


}

void odejmowanieU2(){
}

void konwersja(){
    printf("\n 1. Konwersja DEC -> FLOAT \n");
    printf("\n    W IEEE74 FLOAT liczba jest przechowywana na 32 bitach:");
    printf("\n    1 bit znaku | 8 bitow cechy | 23 bity mantysy");
    printf("\n    Zalozmy, ze chcemy dokonac konwersji liczby 231.12 \n");
    printf("\n    Krok 1. Jesli liczba jest dodatnia - wpisujemy w bit znaku 0, jesli nie - 1.");
    printf("\n            231.12 - dodatnie, wpisujemy 0");
    printf("\n            0 ________ _______________________");
    printf("\n    Krok 2. Teraz musimy zapisac binarnie czesc calkowita i ulamkowa.");
    printf("\n            213 -> 11010101");
    printf("\n            0,12 -> 00011110 10111000 01 ...");
    printf("\n            0,12 * 2 | 0,24 | 0 - wpisujemy pierwsza cyfre po mnozeniu razy 2");
    printf("\n            0,24 * 2 | 0,48 | 0");
    printf("\n            0,48 * 2 | 0,96 | 0");
    printf("\n            0,96 * 2 | 1,92 | 1 - kiedy po mnozeniu razy 2 otrzymamy liczbe wieksza od 1");
    printf("\n            0,92 * 2 | 1,84 | 1   odejmujemy od niej jeden");
    printf("\n            ... \n            Kontynujemy, dopoki nie otrzymamy 24 bity lacznie z czescia calkowita");
    printf("\n            Zapisujemy nasza liczbe z przeinkiem:");
    printf("\n            11010101,00011110 10111000 01");
    printf("\n    Krok 3. Zapisujemy liczbe w postaci liczba*2^(potega) tak, oby w czesci calkowitej zostala tylko 1:");
    printf("\n            11010101,00011110 10111000 01 = 1,10101010 00111101 01110000 1 * 2^7");
    printf("\n            Czyli przesuwamy przecinek o 7 znakow. Do otrzymanej potegi dwojki dodajemy 127 (bias):");
    printf("\n            2+127=130 -> 10000010 - wpisujemy do cechy");
    printf("\n            0 10000010 _______________________");
    printf("\n    Krok 4. Z otrzymanej liczby wpisujemy do mantysy pierwsze 23 bity czesci ulamkowej");
    printf("\n            0 10000010 1010101000111101011100001");
    printf("\n    Gotowe!");
    printf("\n\n\n 2. Konwersja FLOAT -> DEC \n");

}

int main(){
    menu();
    return 0;
}
