#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ZA_MALO_PAMIECI -1

typedef struct wezel {
  struct wezel *nastepny;
  int wartosc;
} Wezel;

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

void stworzCykliczna(Wezel **pierwszy, int liczba){
    Wezel* iterator = *pierwszy;

    while (iterator->nastepny != NULL)
    {
      iterator = iterator->nastepny;
    }
    iterator->nastepny = *pierwszy;

  
}

int rozmiarListy(Wezel *start){
    Wezel *iterator = start;
    int licznik = 1;
    while (iterator->nastepny != start)
    {
        iterator = iterator->nastepny;
        licznik++;
    }
    return licznik;
}

int main(void){
  
  srand( (unsigned)time( NULL ) );
  int rozmiar, shift;
  int n;
  Wezel *pierwszy = NULL;



while (scanf("%d", &n) != EOF) {

        push_back(&pierwszy,n);
    }

  stworzCykliczna(&pierwszy, n);

  
  Wezel *p = pierwszy;
  shift = rand()%100;
  //printf("shift = %d\n", shift);
  for(int i = 0; i < shift; i++){
     p = p->nastepny;
  }

  rozmiar = rozmiarListy(p);
  printf("Rozmiar wynosi %d\n", rozmiar);
  return 0;
}