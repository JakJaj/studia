#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ZA_MALO_PAMIECI -1

typedef struct wezel {
  int wartosc;
  struct wezel *nastepny;
  //struct wezel *poprzedni;//w przypadku listy dwukierunkowej
} Wezel;


/**********************************************************/

void wypisz(Wezel *pierwszy) {
  Wezel *biezacy = pierwszy;

  if(!biezacy){
    printf("Pusta lista\n");
  }

  printf("Lista: ");
  while (biezacy != NULL) {
    printf("%d\t", biezacy->wartosc);
    biezacy = biezacy->nastepny;
  }
  printf("\n");
}

/**********************************************************/

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

/*************** PONIZEJ NAPISZ BRAKUJACA FUNKCJE **********/
Wezel *get_elem(Wezel **pierwszy, int index) {
    Wezel *iterator = *pierwszy;
    int numer = index;

    if (iterator == NULL) {
        printf("Pusta lista\n");
        return NULL;
    }

    while (index != 0) {
        iterator = iterator->nastepny;
        index--;

        if (iterator == NULL) {
            printf("Lista za krotka\n");
            return NULL;
        }
    }

    Wezel *wartoscDoZwrotu = (Wezel*)malloc(sizeof(Wezel));
    wartoscDoZwrotu->wartosc = iterator->wartosc;
    wartoscDoZwrotu->nastepny = NULL;

    if(iterator->nastepny == NULL){
        printf("Na pozycji ostatniej znajduje sie wartosc %d\n", wartoscDoZwrotu->wartosc);
    }else{
    printf("Na pozycji %d znajduje sie wartosc %d\n", numer, wartoscDoZwrotu->wartosc);
    }
    return wartoscDoZwrotu;
}

/**********************************************************/

int main(){
  int dlugosc, x, pozycja;
  Wezel *element;
  Wezel *pierwszy = NULL;
  Wezel *drugi = NULL;
  //wczytaj wartosci i zbuduj liste
  scanf("%d", &dlugosc);

  for (int i = 0; i < dlugosc; i++){
    scanf("%d\t", &x);
    push_back(&pierwszy, x);
  }
  //wypisz liste
  wypisz(pierwszy);
  
  //przetestuj funkcję get_elem dla pozycji 3-ciej
  get_elem(&pierwszy,3);
  
  //przetestuj funkcję get_elem dla pozycji 0-wej
  get_elem(&pierwszy,0);
  
  //przetestuj funkcję get_elem dla pozycji ostatniej
  get_elem(&pierwszy,dlugosc-1);
  
  //przetestuj funkcję get_elem dla pozycji spoza listy
  
  get_elem(&pierwszy,dlugosc + 1);
  //przetestuj funkcję get_elem dla pozycji drugiej i pustej listy
  
  get_elem(&drugi,2);

  return 0;
}