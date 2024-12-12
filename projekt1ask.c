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
}

int main(){
    menu();
    return 0;
}
