#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ZA_MALO_PAMIECI 0

typedef struct wezel {
  
  char *tytul;
  char *autor;
  double cena;
  int ilosc;
  struct wezel *nastepny;
  char *opis;
} ksiazka;

ksiazka *currentlySelected;
ksiazka *magazyn = NULL;


void push_back(ksiazka *nowy, ksiazka **pierwszy) {

  ksiazka* element;
  ksiazka* iterator = *pierwszy;
  
  if( (element = (ksiazka*)malloc(sizeof(ksiazka))) == NULL ) {
    fprintf(stderr, "Za mało pamięci!\n");
    exit(ZA_MALO_PAMIECI);
  }

    element->tytul = nowy->tytul;
    element->autor = nowy->autor;
    element->cena = nowy->cena;
    element->ilosc = nowy->ilosc;
    element->opis = nowy->opis;
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
void split(const char *source, char *autor, char *tytul, char *ilosc, char *cena, char *opis,char delim){
    *autor = '\0';
    *tytul = '\0';
    *ilosc = '\0';
    *cena = '\0';
    *opis = '\0';

    while (*source != delim) { //AUTOR
         *autor = *source;
            autor++;
            source++;
        }
        *autor = '\0';  
        source++;  
    while (*source != delim) { //TYTUL
         *tytul = *source;
            tytul++;
            source++;
        }
        *tytul = '\0';  
        source++;

    while (*source != delim) { //ILOSC
         *ilosc = *source;
            ilosc++;
            source++;
        }
        *ilosc = '\0';  
        source++;
    while (*source != delim) { //CENA
         *cena = *source;
            cena++;
            source++;
        }
        *cena = '\0';  
        source++;
    while (*source != '\0') { //OPIS
         *opis = *source;
            opis++;
            source++;
        }
        *opis = '\0';

}
bool wypelnijMagazyn(const char *nazwaPliku, ksiazka **pierwszy){
    
    FILE *fp = fopen (nazwaPliku, "r");
    if (fp == NULL) {
       printf("Brak pliku z danymi\n");
       return 0;
    }
    const int max_n= 500;
    char linia[max_n], *result;
    char tytul[200];
    char autor[100];
    char ilosc[10];
    char cena[20];
    char opis[500];
   
    while(!feof(fp)){
    
       ksiazka *element;
       if ((element = (ksiazka*)malloc(sizeof(ksiazka))) == NULL ) {
          fprintf(stderr, "Za mało pamięci!\n");
          exit(ZA_MALO_PAMIECI);
       }
       result = fgets (linia, max_n, fp);
       split(linia, tytul, autor, ilosc, cena, opis,';');
       
       element->tytul = (char*) malloc((strlen(tytul) + 1) * sizeof(char));
       strcpy(element->tytul, tytul);
       
       element->autor = (char*) malloc((strlen(autor) + 1) * sizeof(char));
       strcpy(element->autor, autor);
       
       element->ilosc = atoi(ilosc);
       element->cena = atof(cena);

       element->opis = (char*) malloc((strlen(opis) + 1) * sizeof(char));
       strcpy(element->opis, opis);

       push_back(element, pierwszy);
       
       }
       
    fclose(fp);
    
    return 1;
}



