#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ZA_MALO_PAMIECI -1

typedef struct wezel {
  int wartosc;
  struct wezel *nastepny;

} Wezel;

void wypisz(Wezel *pierwszy) {
  Wezel *biezacy = pierwszy;

  if(!biezacy){
    printf("Pusta lista\n");
  }


  while (biezacy != NULL) {
    printf("%d\t", biezacy->wartosc);
    biezacy = biezacy->nastepny;
  }
  printf("\n");
}

void push_back(Wezel **pierwszy, int liczba) {//wstaw element na koniec listy

  // konstruujemy nowy węzeł
  Wezel* element;
  Wezel* iterator = *pierwszy;

  if( (element = (Wezel*)malloc(sizeof(Wezel))) == NULL ) {
    fprintf(stderr, "Za mało pamięci!\n");
    exit(ZA_MALO_PAMIECI);
  }
    element->wartosc = liczba;
    element->nastepny = NULL;

    if (iterator == NULL){//gdy pusta lista
        *pierwszy = element;
        return;
    }

    while (iterator->nastepny != NULL){
        iterator = iterator->nastepny;
    }

    iterator->nastepny = element;

}

bool insert(Wezel **lista, int pozycja, int wartosc){
    Wezel *iterator = *lista;
    Wezel *element;
    Wezel *temp;
    int licznik = 0;

    if( (element = (Wezel*)malloc(sizeof(Wezel))) == NULL ) {
    fprintf(stderr, "Za mało pamięci!\n");
    exit(ZA_MALO_PAMIECI);
  }
    element->wartosc = wartosc;
    element->nastepny = NULL;

    if(iterator == NULL && pozycja == 0){ //pusta lista i wstawiamy na poczatek
        *lista = element;
        return true;
    }
    if(iterator == NULL && pozycja != 0){
        printf("Pusta lista, nie mozna wstawic elementu\n");
        return false;
    }
    if(iterator != NULL && pozycja == 0){ //wstawiamy na poczatek nie pustej listy
        element->nastepny = iterator;
        
        *lista = element;
        return true;

    }
    for(int i = 1; i < pozycja;i++){
        if(iterator->nastepny == NULL){
            printf("Lista za krotka, nie mozna wstawic elementu\n");
            return false;
        }
        iterator = iterator->nastepny;
        
        

    }
    if(iterator->nastepny != NULL){
        temp = iterator->nastepny;
        iterator->nastepny = element;
        element->nastepny = temp;
        return true;
    }
    if(iterator->nastepny == NULL){ //dodajemy na koniec listy
        iterator->nastepny = element;
        return true;
    }

    return false;

}
int main(){
    int dlugosc;
    int x;
    int pozycja;
    int wartosc;
    Wezel *pierwszy = NULL;
    int T;

    scanf("%d", &dlugosc);
    pozycja = 0;
    while (pozycja != dlugosc)
    {
        scanf("%d", &wartosc);
        push_back(&pierwszy, wartosc);
        pozycja++;
    }
    wypisz(pierwszy);

    pozycja = dlugosc;
    wartosc = 100;

    printf("Wstaw na pozycje ostatnia liczbe %d\n", wartosc);
    if(insert(&pierwszy, pozycja, wartosc)){
       printf("Lista po wstawieniu: ");
       wypisz(pierwszy);
       dlugosc++;
    }

    // insert index 3 wartosc 5
    
    pozycja = 3;
    wartosc = 5;
    printf("Wstaw na pozycje %d liczbe %d\n", pozycja,wartosc);

    if(insert(&pierwszy, pozycja, wartosc)){
        printf("Lista po wstawieniu: ");
        wypisz(pierwszy);
        dlugosc++;
    }
    //insert index 0 wartosc 7
    pozycja = 0;
    wartosc = 7;
    printf("Wstaw na pozycje %d liczbe %d\n", pozycja,wartosc);
    if(insert(&pierwszy, pozycja, wartosc)){
        printf("Lista po wstawieniu: ");
        wypisz(pierwszy);
        dlugosc++;
    }
    //insert index dlugosc + 1 wartosc -4
    pozycja = dlugosc + 1;
    wartosc = -4;
    printf("Wstaw na pozycje spoza listy liczbe %d\n", wartosc);
    if(insert(&pierwszy, pozycja, wartosc)){
        printf("Lista po wstawieniu: ");
        wypisz(pierwszy);
        dlugosc++;
    }
    //insert index 0 wartosc -20 i pusta lista
    Wezel *drugi = NULL;
    dlugosc = 0;
    pozycja = 0;
    wartosc = -20;
    printf("Wstaw na pozycje %d liczbe %d\n", pozycja,wartosc);
    if(insert(&drugi, pozycja, wartosc)){
        printf("Lista po wstawieniu: ");
        wypisz(drugi);
        dlugosc++;
    }
    Wezel *trzeci = NULL;
    dlugosc = 0;
    pozycja = 3;
    wartosc = -20;
    //insert index 3 wartosc -20 i pusta lista
    printf("Wstaw na pozycje %d liczbe %d\n", pozycja,wartosc);
    if(insert(&trzeci, pozycja, wartosc)){
        printf("Lista po wstawieniu: ");
        wypisz(trzeci);
        dlugosc++;
    }
    return 0;
}