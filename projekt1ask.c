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
}

void wczytdrukbin(){
}

void drukbin(unsigned char bajt){
    for(int i=7; i>=0; i--){
        printf("%d", (bajt>>i)&1);
    }
}

void wczytdrukbajt(){
}

void odejmowanieU2(){
}

void konwersja(){
}

void drukbainarny(){
}

int main(){
    menu();
    return 0;
}
