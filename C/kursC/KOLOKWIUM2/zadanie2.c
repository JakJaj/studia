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

int min;
int  *minimum(Wezel **lista){

    
    Wezel * iterator = *lista;
    min = iterator->wartosc;

    while (iterator != NULL)
    {
        if(iterator->wartosc < min) min = iterator->wartosc;
        iterator = iterator->nastepny;
    }
    
    return &min;
    
}

int main(){
    int mini;
    int wartosc;
    Wezel *pierwszy = NULL;
    int T;
    char character, dana;

    scanf("%d", &T);
    for (int i = 0; i < T; i++){ 
        
        for (int i = 0; i < T; i++) {

        int liczba;
        

        
        while (scanf("%d", &liczba) == 1) {
            push_back(&pierwszy,liczba);
            char znak = getchar();
            if (znak == '\n' || znak == EOF) {
                break;
            }
        }

        printf("Lista: ");
        wypisz(pierwszy);

        mini = *minimum(&pierwszy);
        printf("Minimum wynosi: %d\n", mini);
        pierwszy = NULL;
        }
    
    

    return 0;
}
}