#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct ksiazka{
  char autor[255];
  char tytul[255];

  unsigned ilosc;
  float cena;
};

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
bool wypelnijMagazyn(const char *nazwaPliku, struct ksiazka *magazyn){
    
    int len = 0;
    char autor[300];
    char tytul[300];
    char ilosc[100];
    char cena[100];

    FILE *fp = fopen (nazwaPliku, "r");
    
    if (fp == NULL) {
        return 0;
    }
    
    int i;
    const int max_n = 500;
    char linia[max_n], *result;

    for(i = 0; i < ROZMIAR ;i ++){
        result = fgets(linia,max_n,fp);
        
        split(linia, autor, tytul, ilosc,cena, ';');

        strcpy(magazyn[i].autor, autor);
        strcpy(magazyn[i].tytul, tytul);
        magazyn[i].ilosc = atoi(ilosc);
        magazyn[i].cena = atof(cena);

    } 
    fclose(fp);
    return 1;
}

void wyswietlKsiazke(int pozycja, struct ksiazka *magazyn){
    printf("Ksiazka nr %d to: %s %s %d %5.2f\n", 
    pozycja,  magazyn[pozycja].autor, magazyn[pozycja].tytul,magazyn[pozycja].ilosc, magazyn[pozycja].cena);
}

int main(void){
  struct ksiazka magazyn[ROZMIAR];
  int T;
  int pozycja;
  char NazwaPliku[200];
  
  scanf("%d", &T);
  for(int i = 0; i < T; i++){
    
    scanf("%s %d", NazwaPliku, &pozycja);
    
    if(pozycja < 50){ 
        
        bool sukces = wypelnijMagazyn(NazwaPliku, magazyn);
        if(sukces) wyswietlKsiazke(pozycja, magazyn);
        else printf("Brak pliku z danymi\n");
    }
    else printf("W magazynie nie ma ksiazki o podanej pozycji\n");
        
    
  }
  
}