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


  while (biezacy != NULL) {
    printf("%d\n", biezacy->wartosc);
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

/**********************************************************/
// tu wpisz funkcje
void push_front(Wezel **pierwszy, int wartoscWejsciowa){
    Wezel *przyszlyDrugi = *pierwszy;
    
    Wezel* przyszlyPierwszy;

    if( (przyszlyPierwszy = (Wezel*)malloc(sizeof(Wezel))) == NULL ) {
    fprintf(stderr, "Za mało pamięci!\n");
    exit(ZA_MALO_PAMIECI);
  }

    przyszlyPierwszy->wartosc = wartoscWejsciowa;
    przyszlyPierwszy->nastepny = przyszlyDrugi;

    *pierwszy = przyszlyPierwszy;
}

/**********************************************************/






int main(){
int T;
  char linia[20];
  int x, y, error;
  Wezel *pierwszy = NULL;


  scanf("%d", &T);
  for (int i = 0; i < T; i++){
      scanf("%s", linia);
      if(strstr(linia, "push_back")){
        scanf("%d", &x);
        printf("test %d: %s %d\n", i, linia, x);
        push_back(&pierwszy, x);
        wypisz(pierwszy);
      }
      else{
        scanf("%d", &x);
        printf("test %d: %s %d\n", i, linia, x);
        push_front(&pierwszy, x);
        wypisz(pierwszy);

      }

  }

return 0;
}