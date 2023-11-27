#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#define ROZMIAR 30
#define ZA_MALO_PAMIECI 0

typedef struct wezel {
  
  char *tytul;
  char *autor;
  double cena;
  int ilosc;
  struct wezel *nastepny;
} ksiazka;

void push_back(ksiazka *nowy, ksiazka pierwszy) {//wstaw element na koniec listy

  // konstruujemy nowy węzeł
  ksiazka* element;
  ksiazka* iterator = &pierwszy;

  if( (element = (ksiazka*)malloc(sizeof(ksiazka))) == NULL ) {
    fprintf(stderr, "Za mało pamięci!\n");
    exit(ZA_MALO_PAMIECI);
  }
    element->tytul = nowy->tytul;
    element->autor = nowy->autor;
    element->cena = nowy->cena;
    element->ilosc = nowy->ilosc;
    element->nastepny = NULL;

    if (iterator == NULL){//gdy pusta lista
        pierwszy = *element;
        return;
    }

    while (iterator->nastepny != NULL){
        iterator = iterator->nastepny;
    }

    iterator->nastepny = element;

}
void split(const char *source, char *autor, char *tytul, char *ilosc, char *cena, char delim){
    
    
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
    while (*source != '\0') { //CENA
         *cena = *source;
            cena++;
            source++;
        }
        *cena = '\0';  

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
   
    
    //for(int i = 0; i < ROZMIAR; ++i) {//pod warunkiem, ze znamy ilosc linii w pliku
    while(!feof(fp)){
    
       ksiazka *element;
       if ((element = (ksiazka*)malloc(sizeof(ksiazka))) == NULL ) {
          fprintf(stderr, "Za mało pamięci!\n");
          exit(ZA_MALO_PAMIECI);
       }
       result = fgets (linia, max_n, fp);
       split(linia, tytul, autor, ilosc, cena, ';');
       
       element->tytul = (char*) malloc((strlen(tytul) + 1) * sizeof(char));
       strcpy(element->tytul, tytul);
       element->autor = (char*) malloc((strlen(autor) + 1) * sizeof(char));
       strcpy(element->autor, autor);
       element->ilosc = atoi(ilosc);
       element->cena = atof(cena);

       //uzupelnij kod ponizej

       //push_back(element, &(*pierwszy));// w starszych kompilatorach
       push_back(element, **pierwszy);
       
       }
    fclose(fp);
    return 1;
}

void wyswietlKsiazke(int pozycja,  ksiazka *pierwszy){
    int licznik = 1;
    ksiazka *iterator = pierwszy;
    while (licznik != pozycja)
    {
        iterator = iterator->nastepny;
        licznik++;
    }
    
    printf("Ksiazka nr %d to: %s %s %d %5.2f\n", 
    pozycja, iterator->autor, iterator->tytul, iterator->ilosc, iterator->cena);
}

int main(){
  int T;
  ksiazka *pierwszy = NULL;
  scanf("%d", &T);
  for(int i = 0; i < T; i++){
    char NazwaPliku[200];
    int pozycja = 0;
    scanf("%s %d", NazwaPliku, &pozycja);
    bool sukces = wypelnijMagazyn(NazwaPliku, &pierwszy);
    if(sukces)
      wyswietlKsiazke(pozycja, pierwszy);
  }
return 0;
}